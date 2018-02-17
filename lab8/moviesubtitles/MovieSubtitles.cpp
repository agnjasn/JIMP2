//
// Created by Kinga on 06.05.2017.
//

#include "MovieSubtitles.h"
#include <regex>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

namespace moviesubs
{

    MicroDvdSubtitles::MicroDvdSubtitles() {

    }

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {

        if (fps<0)
        {
            throw std::invalid_argument("");
        }
        const std::string INPUT = (*in).str();
        const std::regex ok_line_format ("(\\{[0-9]+\\}\\{[0-9]+\\}.*\n?)+");
        const std::regex catch_each_line ("\\{[0-9]+\\}\\{[0-9]+\\}.*\n?");
        const std::regex extract_numbers_and_text ("\\{([0-9]+)\\}\\{([0-9]+)\\}(.*\n?)");

        std::string OUTPUT = "";

       if(!std::regex_match(INPUT, ok_line_format)) // sprawdza czy dobry format
       {
           throw InvalidSubtitleLineFormat(); // jesli nie to od razu jebs wyjątek, nie ma się co bawić
       } else
       {
           std::vector <std::string> line_matches;
           auto words_begin = std::sregex_iterator(INPUT.begin(), INPUT.end(), catch_each_line);
           auto words_end = std::sregex_iterator();
           for (std::sregex_iterator i = words_begin; i != words_end; ++i) { //wyłapuje wszystkie pojedyncze linijki
               std::smatch matches = *i;
               line_matches.push_back(matches.str()); //wklada je do wektora
             //  cout<<line_matches.back();
           }

           for (int i=0; i<line_matches.size(); i++) // ta pętla "przerabia" każdą linię osobno
           {

               std::smatch matches;
               regex_match(line_matches[i], matches, extract_numbers_and_text);
               //   cout<<matches[0];
               int start_frame=std::stoi(matches[1]); // zawartość pierwszych wąsatych nawiasów
               int end_frame=std::stoi(matches[2]); // i drugich
               if (end_frame<start_frame)
               {
                   throw SubtitleEndBeforeStart(i+1); // jak napisy się zaczynają pózniej niz koncza to rzuca wyjątek
                   // i+1 to numer linii (indeksując od 1 jak matlab nie od 0 jak cpp(~Maciej Szymkat)), w której jest błąd
               }
               std::string line_text=matches[3]; // cały tekst po nawiasach łącznie z \n

               int offset= static_cast<int>((static_cast<double >(delay)/1000.)*fps); // ustalenie o ile klatek mają się przesunąć napisy
             //  int offset=static_cast<int>(offset);

               start_frame+=offset; //przesunięcie napisów
               end_frame+=offset;

               if(start_frame<0 || end_frame<0) // w sumie drugi warunek opcjonalny
               {
                   throw NegativeFrameAfterShift(); // jeżeli napisy miałyby się zacząc na ujemnej klasie to wyrzuca wyjątek
               }
                if(line_text[line_text.length()-1]!='\n') line_text+='\n';
               OUTPUT+="{"+std::to_string(start_frame)+"}{"+std::to_string(end_frame)+"}"+line_text; // składanie wyjściowego stringa


           }

           (*out)<<OUTPUT;
       }

    }


    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        if (fps<0)
        {
            throw std::invalid_argument("");
        }
        const std::string INPUT = (*in).str();
        const std::regex ok_line_format ("([0-9]+\n+[0-9][0-9]:[0-9][0-9]:[0-9][0-9],[0-9]+ --> [0-9][0-9]:[0-9][0-9]:[0-9][0-9],[0-9]{3}\n+(.*\n+)+\n?)");
        const std::regex catch_each_line ("([0-9]+)\n+([0-9][0-9]):([0-9][0-9]):([0-9][0-9]),([0-9]+) --> ([0-9][0-9]):([0-9][0-9]):([0-9][0-9],[0-9]{3})\n+(.*[^0-9]\n+)+");
        const std::regex extract_numbers_and_text ("([0-9]+)\n+([0-9][0-9]):([0-9][0-9]):([0-9][0-9],[0-9]{3}) --> ([0-9][0-9]):([0-9][0-9]):([0-9][0-9],[0-9]{3})\n+(.*\n+)+");

        std::string OUTPUT = "";
        if(!std::regex_match(INPUT, ok_line_format))
        {
            throw InvalidSubtitleLineFormat();
        } else
        {
            std::vector <std::string> line_matches;
            auto words_begin = std::sregex_iterator(INPUT.begin(), INPUT.end(), catch_each_line);
            auto words_end = std::sregex_iterator();
            for (std::sregex_iterator i = words_begin; i != words_end; ++i) { //wyłapuje wszystkie pojedyncze linijki
                std::smatch matches = *i;
                line_matches.push_back(matches.str()); //wklada je do wektora
                //  cout<<line_matches.back();
            }

            for (int i=0; i<line_matches.size(); i++) // ta pętla "przerabia" każdą linię osobno
            {

                std::smatch matches;
                regex_match(line_matches[i], matches, extract_numbers_and_text);
                std::string frame=matches[1];
                int start_hour=std::stoi(matches[2]);
                int start_minutes=std::stoi(matches[3]);
                std::string str=matches[4];
                str.replace(2,1,".");
                double start_seconds=std::stod(str);
//                int start_miliseconds=std::stoi(matches[5]);
                double start_time=start_hour*3600+start_minutes*60+start_seconds;//+start_miliseconds*0.001; //w sekundach

                int end_hour=std::stoi(matches[5]);
                int end_minutes=std::stoi(matches[6]);
                std::string str2=matches[7];
                str2.replace(2,1,".");
                double end_seconds=std::stod(str2);
//                int end_miliseconds=std::stoi(matches[9]);
                double end_time=(end_hour*3600)+(end_minutes*60)+end_seconds;//+(end_miliseconds*0.001);
                if (end_time<start_time)
                {
                    throw SubtitleEndBeforeStart(i+1);
                }
                std::string line_text=matches[8]; // cały tekst po nawiasach łącznie z \n

                double offset= delay/1000.;
//              int offset=static_cast<int>(offset);
//
                start_time+=offset; //przesunięcie napisów
                end_time+=offset;

                if(start_time<0 || end_time<0) // w sumie drugi warunek opcjonalny
                {
                    throw NegativeFrameAfterShift(); // jeżeli napisy miałyby się zacząc na ujemnej klasie to wyrzuca wyjątek
                }

                start_seconds+=offset;
                while(start_seconds>60)
                {
                    start_seconds-=60;
                    start_minutes+=1;
                }
                while (start_minutes>60)
                {
                    start_minutes-=60;
                    start_hour+=1;
                }

                end_seconds+=offset;
                while(end_seconds>60)
                {
                    end_seconds-=60;
                    end_minutes+=1;
                }
                while (end_minutes>60)
                {
                    end_minutes-=60;
                    end_hour+=1;
                }

                //std::string delayed_start_time=std::to_string(start_time);
               // if(line_text[line_text.length()-1]!='\n') line_text+='\n';

                std::stringstream ss;
                ss<<start_seconds;
                str=ss.str();

//                for (int i=0; i<str.length(); i++)
//                {
//                    if (str[i]=='.') str[i]=',';
//                    break;
//                }

                    if (str.length()<6) str="0"+str;

                str.replace(2,1,",");
//
//               OUTPUT+=std::to_string((i+1))+"\n"+std::to_string(start_hour)+":"+std::to_string(start_minutes)+":"+str;
//                OUTPUT+=" --> ";
//
                std::stringstream ss2;
                ss2<<start_seconds;
                str2=ss2.str();

//                for (int i=0; i<str2.length(); i++)
//                {
//                    if (str2[i]=='.') str2[i]=',';
//                    break;
//                }

                if (str2.length()<6)
                {str2="0"+str2;}
                str2.replace(2,1,",");

//
//                OUTPUT+=std::to_string(end_hour)+":"+std::to_string(end_minutes)+":"+str2+"\n";
//                OUTPUT+=line_text;

                (*out)<<frame<<"\n"<<std::setfill('0')<<std::setw(2)<<start_hour<<":"<<std::setfill('0')<<std::setw(2)<<start_minutes<<":"<<str<<
                      " --> "<<std::setfill('0')<<std::setw(2)<<end_hour<<":"<<std::setfill('0')<<std::setw(2)<<end_minutes<<":"<<str2<<"\n"<<line_text;
//
//
            }

           // (*out)<<OUTPUT;
        }
    }
}
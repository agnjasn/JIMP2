//
// Created by Kinga on 06.05.2017.
//

#include "MovieSubtitles.h"
#include <regex>
#include <string>
#include <iostream>
#include <vector>
namespace moviesubs
{

    MicroDvdSubtitles::MicroDvdSubtitles() {

    }

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        std::regex pattern ("\\{(\\d+)\\}\\{(\\d+)\\}(.+)");
        std::string str=(*in).str();
        std::smatch match;
        std::regex_search(str, match, pattern);

        if (fps<0)
        {
            throw std::invalid_argument("");
        }
        const std::string INPUT = (*in).str();
        const std::regex ok_line_format ("(\\{[0-9]+\\}\\{[0-9]+\\}.*\n)+");
        const std::regex catch_each_line ("\\{[0-9]+\\}\\{[0-9]+\\}.*\n");
        const std::regex extract_numbers_and_text ("\\{([0-9]+)\\}\\{([0-9]+)\\}(.*\n)");

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
               if (end_frame>start_frame)
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

               OUTPUT+="{"+std::to_string(start_frame)+"}{"+std::to_string(end_frame)+"}"+line_text; // składanie wyjściowego stringa


           }

           (*out)<<OUTPUT;
       }

    }


    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {

    }
}
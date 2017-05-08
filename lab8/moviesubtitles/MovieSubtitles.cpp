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

        if (fps<0)
        {
          //  throw std::invalid_argument;
        }
        const std::string INPUT = (*in).str();
        const std::regex ok_line_format ("(\\{[0-9]+\\}\\{[0-9]+\\}.*\n)+");
        const std::regex catch_each_line ("\\{[0-9]+\\}\\{[0-9]+\\}.*\n");
        const std::regex extract_numbers_and_text ("\\{([0-9]+)\\}\\{([0-9]+)\\}(.*\n)");

        std::string OUTPUT = "";

       if(!std::regex_match(INPUT, ok_line_format))
       {
           throw InvalidSubtitleLineFormat();
       } else
       {
           std::vector <std::string> line_matches;
           auto words_begin = std::sregex_iterator(INPUT.begin(), INPUT.end(), catch_each_line);
           auto words_end = std::sregex_iterator();
           for (std::sregex_iterator i = words_begin; i != words_end; ++i) { //wyłapuje wszystkie pasujące napisy
               std::smatch matches = *i;
               line_matches.push_back(matches.str()); //wklada je do wektora
             //  cout<<line_matches.back();
           }

           for (int i=0; i<line_matches.size(); i++)
           {

               std::smatch matches;
               regex_match(line_matches[i], matches, extract_numbers_and_text);
               //   cout<<matches[0];
               int start_frame=std::stoi(matches[1]);
               int end_frame=std::stoi(matches[2]);
               if (end_frame>start_frame)
               {
                   throw SubtitleEndBeforeStart(i+1);
               }
               std::string line_text=matches[3];

               int offset= static_cast<int>((static_cast<double >(delay)/1000.)*fps);
             //  int offset=static_cast<int>(offset);

               start_frame+=offset;
               end_frame+=offset;

               if(start_frame<0 || end_frame<0) // w sumie drugi warunek opcjonalny
               {
                   throw NegativeFrameAfterShift();
               }

               OUTPUT+="{"+std::to_string(start_frame)+"}{"+std::to_string(end_frame)+"}"+line_text;


           }

           (*out)<<OUTPUT;
       }

    }


    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {

    }
}
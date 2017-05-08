//
// Created by Kinga on 06.05.2017.
//

#include "MovieSubtitles.h"
#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main (void)
{
//    regex pat ("(\\{[0-9]+\\}\\{[0-9]+\\}.*\n)+");
//    //smatch matches;
//    string line = "{0}{250}TEXT\n{7}{257}TEXT\n{10}{290}TEXT\n";
//
////    std::ptrdiff_t const match_count(std::distance(
////            std::sregex_iterator(line.begin(), line.end(), pat),
////            std::sregex_iterator()));
//
//    if (regex_match(line, pat)) cout<<"tak"<<endl;
//
//    regex pat2 ("\\{[0-9]+\\}\\{[0-9]+\\}.*\n");
//
//
//    std::vector <std::string> line_matches;
//    auto words_begin = std::sregex_iterator(line.begin(), line.end(), pat2);
//    auto words_end = std::sregex_iterator();
//    for (std::sregex_iterator i = words_begin; i != words_end; ++i) { //wyłapuje wszystkie pasujące napisy
//        std::smatch matches = *i;
//        line_matches.push_back(matches.str()); //wklada je do wektora
//        cout<<line_matches.back();
//    }
//
//    regex pat3 ("\\{([0-9]+)\\}\\{([0-9]+)\\}(.*\n)");
//    int fps=25;
//    int delay = 1000;
//
//    string OUTPUT="";
//
//    for (int i=0; i<line_matches.size(); i++)
//    {
//
//        std::smatch matches;
//        regex_match(line_matches[i], matches, pat3);
//     //   cout<<matches[0];
//        int start_frame=std::stoi(matches[1]);
//        int end_frame=std::stoi(matches[2]);
//        if (end_frame>start_frame)
//        {
//            //throw SubtitleEndBeforeStart
//        }
//        std::string line_text=matches[3];
//
//        int  offset=delay/1000*fps;
//       // int offset=static_cast<int>(offset);
//
//        start_frame+=offset;
//        end_frame+=offset;
//
//        if(start_frame<0 || end_frame<0) // w sumie drugi warunek opcjonalny
//        {
//            //throw NegativeFrameAfterShift
//        }
//
//        OUTPUT+="{"+to_string(start_frame)+"}{"+to_string(end_frame)+"}"+line_text;
//
//
//        cout << OUTPUT;
//    }
//
//    cout<<"line"<<line;

    return 0;
}
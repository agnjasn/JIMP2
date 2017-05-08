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


    }

    SubRipSubtitles::SubRipSubtitles() {

    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {

    }
}
//
// Created by Kinga on 14.03.2017.
//

#include "MinimalTimeDifference.h"

#include <sstream>
#include <regex>
#include <cmath>

namespace minimaltimedifference {
    using namespace std;
    int StringtoInt(std::string text)
    {
        stringstream ss;
        int value;
        ss<<text;
        ss>>value;
        return value;

    }
    unsigned int ToMinutes(std::string time_HH_MM) {


        regex pattern {R"((\d{1,2}):(\d{2}))"};
        smatch matches;

        regex_match(time_HH_MM, matches, pattern);

        string hstr = matches[1];
        string mstr = matches[2];
        int h= stoi(hstr);
        int m= stoi(mstr);

        unsigned int minutes=60*h+m;
        return minutes;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        unsigned int minimal_time_diff = 720;
        vector<int> time_in_minutes;
        int diff = 0;

        for (int i = 0; i < times.size(); i++) {
            time_in_minutes.push_back(ToMinutes(times[i]));
        }

        for (int i = 0; i < times.size() - 1; i++) {
            for (int j = i + 1; j < times.size(); j++) {
                diff = abs(time_in_minutes[i] - time_in_minutes[j]);

                if (diff > 720) {
                    diff = 1440 - diff;
                }

                if (diff < minimal_time_diff) {
                    minimal_time_diff = diff;
                }
            }

        }

        return minimal_time_diff;
    }
}
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
        unsigned int MinimalTimeDifference = 720;
        vector<int> TimeInMinutes;
        int diff = 0;

        for (int i = 0; i < times.size(); i++) {
            TimeInMinutes.push_back(ToMinutes(times[i]));
        }

        for (int i = 0; i < times.size() - 1; i++) {
            for (int j = i + 1; j < times.size(); j++) {
                diff = abs(TimeInMinutes[i] - TimeInMinutes[j]);

                if (diff > 720) {
                    diff = 1440 - diff;
                }

                if (diff < MinimalTimeDifference) {
                    MinimalTimeDifference = diff;
                }
            }

        }

        return MinimalTimeDifference;
    }
}
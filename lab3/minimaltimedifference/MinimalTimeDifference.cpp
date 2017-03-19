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


        regex pattern {R"((\d{1,2}):(\d{2}))"};  //regex dopasowujący się do formatu godziny HH:MM lub H:MM
        smatch matches; //tablica z tym co się dopauje do regexa

        regex_match(time_HH_MM, matches, pattern); //wpisanie do ej tablicy dopasowań ze  stringa z wejsćia funkcji

        string hstr = matches[1]; //string z częscią godzinową
        string mstr = matches[2]; //string z częścią minutową
        int h= stoi(hstr); //liczba godzin
        int m= stoi(mstr); //liczba minut

        unsigned int minutes=60*h+m; //liczba minut, która upłynęła tego dnia od północy do danej godziny
        return minutes;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        unsigned int minimal_time_diff = 720;  //przypisanie największej możliwej wartości różnicy czasu między godzinami
        vector<int> time_in_minutes;  // wektor z wartościami czasu od północy w minutach
        int diff = 0;

        for (int i = 0; i < times.size(); i++) {
            time_in_minutes.push_back(ToMinutes(times[i])); //wpisanie do wektora tych godzin w formacie ilości minut, które upłynęły od północy
        }

        for (int i = 0; i < times.size() - 1; i++) {
            for (int j = i + 1; j < times.size(); j++) {
                diff = abs(time_in_minutes[i] - time_in_minutes[j]); //wyliczenie róznicy między dwiema podanymi wartościami

                if (diff > 720) {  // jeśli różnica wyjdzie większa niż 720 minut
                    diff = 1440 - diff; // to idąc "w drrugą stronę po zegarku" będzie mniejsza i wyniesie tyle
                }

                if (diff < minimal_time_diff) {  //jeśli aktualnie wyliczona róznica jest mniejsza od dotychczas najmniejszej
                    minimal_time_diff = diff; // to zaktuaizuj najmniejszą
                }
            }

        }

        return minimal_time_diff; // zwróć tę najmniejszą różnicę
    }
}
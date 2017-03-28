//
// Created by agnieszka on 25.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <experimental/optional>
#include <string>
#include <vector>
#include <map>

namespace nets
{
    using std::experimental::optional;

    class JsonValue
    {
    public:

        JsonValue(int a);
        JsonValue(double a);
        JsonValue(std::string a);
        JsonValue(bool a);
        JsonValue(std::vector<JsonValue> a);
        JsonValue(std::map<std::string, JsonValue> a);
        ~JsonValue();
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    private:
        optional <int> value1;
        optional <double> value2;
        optional <std::string> value3;
        optional <bool> value4;
        optional <std::vector<JsonValue>> vector;
        std::map <std::string, JsonValue> map;

    };
//    class JsonValue
//    { public:
//        struct obiekt
//        {
//          std::map<std::string, JsonValue> mapa;
//        };
//
//           JsonValue();
//        JsonValue(int value);
//        JsonValue(double value);
//        JsonValue(bool value);
//        JsonValue(std::string value);
//        JsonValue(std::vector<JsonValue> value);
//        JsonValue(obiekt value);
//        JsonValue(std::string str, int value);
//        JsonValue(std::string str, double value);
//        JsonValue(std::string str, bool value);
//        JsonValue(std::string str, std::string value);
//        JsonValue(std::string str, std::vector<JsonValue> value);
//        JsonValue(std::string str, obiekt value);
//        //JsonValue(int value, double number, bool a, std::vector<JsonValue> tab, obiekt object);
//          ~JsonValue();
//
////            int Getint() const;
////            double Getdouble() const;
////            bool Getbool() const;
////            std::vector<JsonValue> Getvector() const;
//       // obiekt Getobj() const;
//        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
//        std::string ToString() const;
////        void Setint(int value);
////        void Setdouble(double number);
////        void Setbool(bool a);
////        void Setvector(std::vector<JsonValue>);
////        void Setobj(obiekt);
//
//
//    private:
//        std::string strin;
//        int num;
//        double number;
//        bool a;
//        std::vector<JsonValue> tab;
//        obiekt obj;
//    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H

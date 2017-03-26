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
    class JsonValue
    { public:
           JsonValue();
        JsonValue(int value, double number, bool a, std::vector<JsonValue> tab, obj object);
        //JsonValue(int value, double number, bool a, std::vector<JsonValue> tab, obj object);
          ~JsonValue();

            int Getint() const;
            double Getdouble() const;
            bool Getbool() const;
            std::vector<JsonValue> Getvector() const;
            obj Getobj() const;

        void Setint(int value);
        void Setdouble(double number);
        void Setbool(bool a);
        void Setvector(std::vector<JsonValue>);
        void Setobj(obj);

    private:
        std::string str;
        int value;
        double number;
        bool a;
        std::vector<JsonValue> tab;
        struct obj
        {
            std::map<std::string, JsonValue> ma;
        };
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H

//
// Created by agnieszka on 25.03.17.
//

#include "SimpleJson.h"
#include <iostream>
#include <string>
#include <sstream>
#include <experimental/optional>
#include <map>

namespace nets {

    JsonValue::JsonValue(int a) {
        value1 = a;
    }

    JsonValue::JsonValue(double a) {
        value2 = a;
    }

    JsonValue::JsonValue(std::string a) {
        value3 = a;
    }

    JsonValue::JsonValue(bool a) {
        value4 = a;
    }

    JsonValue::JsonValue(std::vector<JsonValue> a) {
        vector = a;
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> a) {
        map.insert(a.begin(), a.end());
    }

    JsonValue::~JsonValue()
    {

    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {

        std::experimental::optional<JsonValue> a = std::experimental::make_optional(this->map.find(name)->second);
        return a;
       return std::experimental::optional<JsonValue>{};
    }

    std::string JsonValue::ToString() const {

        if(value1) return std::to_string(value1.value());
        if(value2)// return std::to_string(value2.value());
        {
            std::stringstream ss;
            ss<<value2.value();
            return ss.str();
        }
        if(value4)
        {
            if (value4.value()==1)
                return "true";
                    else return "false";
        }
        if(value3) return value3.value();
    }

}



//    JsonValue::JsonValue() {}
//    JsonValue::~JsonValue() {}
//    JsonValue::JsonValue(int value)
//    {
//        this->num=value;
//    }
//    JsonValue::JsonValue(double value)
//    {
//        this->number=value;
//    }
//    JsonValue::JsonValue(bool value)
//    {
//        this->a=value;
//    }
//    JsonValue::JsonValue(std::string value)
//    {
//        this->strin=value;
//    }
//    JsonValue::JsonValue(std::vector<JsonValue> value)
//    {
//        this->tab=value;
//    }
//    JsonValue::JsonValue(obiekt value)
//    {
//        this->obj=value;
//    }
//    JsonValue::JsonValue(std::string str, int value)
//    {
//        this->obj.mapa.emplace(str, JsonValue(value));
//    }
//    JsonValue::JsonValue(std::string str, double value)
//    {
//        this->obj.mapa.emplace(str, JsonValue(value));
//    }
//    JsonValue::JsonValue(std::string str, bool value)
//    {
//        this->obj.mapa.emplace(str, JsonValue(value));
//    }
//    JsonValue::JsonValue(std::string str, std::string value)
//    {
//        this->obj.mapa.emplace(str, JsonValue(value));
//    }
//    JsonValue::JsonValue(std::string str, std::vector<JsonValue> value)
//    {
//        this->obj.mapa.emplace(str, JsonValue(value));
//    }
//    JsonValue::JsonValue(std::string str, obiekt value)
//    {
//        this->obj.mapa.emplace(str, JsonValue(value));
//    }
//    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const
//    {
//
//    }
//    std::string JsonValue::ToString() const
//    {
//
//    }

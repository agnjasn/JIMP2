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
     //   this->value1 = a;
    }

    JsonValue::JsonValue(double a) {
       // this->value2 = a;
    }

    JsonValue::JsonValue(std::string a) {
     //   this->value3 = a;
    }

    JsonValue::JsonValue(bool a) {
       // this->value4 = a;
    }

    JsonValue::JsonValue(std::vector<JsonValue> a) {
        //this->vector1 = a;
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> a) {
    //    this->map1.insert(a.begin(), a.end());
    }

    JsonValue::~JsonValue()
    {

    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {

    }

    std::string JsonValue::ToString() const {


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

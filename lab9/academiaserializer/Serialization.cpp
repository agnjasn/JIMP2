//
// Created by agnieszka on 09.05.17.
//

#include "Serialization.h"

namespace academia {
    using namespace std::string_literals;
    Serializer::Serializer(std::ostream *out_) : out_(out_) {}

    std::string Room::EnumToString() const {
        switch(type_) {
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Type::CLASSROOM:
                return "CLASSROOM";
        }


    }
    void Room::Serialize (Serializer *serial) const
    {
        serial->Header("room");
        serial->IntegerField("id", this->Id);
        serial->StringField("name", this->name_);
        serial->StringField("type", this->EnumToString());
        serial->Footer("room");
    }

    void Building::Serialize(Serializer *serializer) const
    {
        serializer->Header("building");
        serializer->IntegerField("id", Id);
        serializer->StringField("name", number_);
        serializer->ArrayField("rooms", room_);
        serializer->Footer("building");
    }


    void XmlSerializer::IntegerField(const std::string &field_name, int value)
    {
        std::string value_str=std::to_string(value);
        *out_<<"<"<<field_name<<">"<<value_str<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value)
    {
        std::string value_str=std::to_string(value);
        *out_<<"<"<<field_name<<">"<<value_str<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value)
    {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value)
    {
        std::string value_str=std::to_string(value);
        *out_<<"<"<<field_name<<">"<<value_str<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value)
    {
        *out_<<"<"<<field_name<<">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value)
    {
        *out_<<"<"<<field_name<<">";
        for(const Serializable &ser : value)
        {
            XmlSerializer serial{out_};
            ser.Serialize(&serial);
        }
        *out_<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::Header(const std::string &object_name)
    {
        *out_<<"<"<<object_name<<">";
    }

    void XmlSerializer::Footer(const std::string &object_name)
    {
        *out_<<"<\\"<<object_name<<">";
    }



    void JsonSerializer::IntegerField(const std::string &field_name, int value)
    {
        std::string value_str=std::to_string(value);
        *out_<<"\""<<field_name<<"\": "<<value_str<<", ";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value)
    {
        std::string value_str=std::to_string(value);
        *out_<<"\""<<field_name<<"\": \""<<value_str<<"\", ";
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value)
    {
        if(field_name=="name") *out_<<"\""<<field_name<<"\": \""<<value<<"\", ";
        else *out_<<"\""<<field_name<<"\": \""<<value<<"\"";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value)
    {
        std::string value_str = std::to_string(value);
        *out_ << "\"" << field_name << "\": []";

    }
    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value)
    {
        *out_<<"["<<field_name<<"]";
    }

    void JsonSerializer::ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const academia::Serializable>> &value)
    {
        *out_<<"\""<<field_name<<"\": [";
        bool coma=false;
        for(const Serializable &ser : value)
        {
            if(coma!=false) *out_<<", ";
            else coma=true;
            JsonSerializer serial{out_};
            ser.Serialize(&serial);

        }
        *out_<<"]";
    }

    void JsonSerializer::Header(const std::string &object_name)
    {
        *out_<<"{";
    }

    void JsonSerializer::Footer(const std::string &object_name)
    {
        *out_<<"}";
    }

    void BuildingRepository::StoreAll(Serializer *serializer)
    {

    }

    void BuildingRepository::Add(Building bu)
    {
        buildings_.push_back(bu);
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int b_id) const
    {

    }



}
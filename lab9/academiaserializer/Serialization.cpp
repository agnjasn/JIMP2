//
// Created by agnieszka on 09.05.17.
//

#include "Serialization.h"

namespace academia {
    Serializer::Serializer(std::ostream *out_) : out_(out_) {}

    Serializer::~Serializer() {}

    Serializer::Serializer() {}

    Serializable::Serializable() {}

    Serializable::~Serializable() {

    }
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
        serial->Header("Room");
        serial->IntegerField("id", this->id_);
        serial->StringField("name", this->name_);
        serial->StringField("type", this->EnumToString());
        serial->Footer("/Room");
    }


  //  XmlSerializer::XmlSerializer(std::ostream *out) : out_(out) {}
}
//
// Created by agnieszka on 09.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <iostream>
#include <vector>

namespace academia
{
    class Serializer;
    class Serializable {
    public:
        virtual ~Serializable();

        Serializable();

        virtual void Serialize (Serializer *serial) const=0;
    };

    class Serializer {
    public:
        Serializer();

        virtual ~Serializer();

        virtual void IntegerField(const std::string &field_name, int value)=0;

        virtual void DoubleField(const std::string &field_name, double value)=0;

        virtual void StringField(const std::string &field_name, const std::string &value)=0;

        virtual void BooleanField(const std::string &field_name, bool value)=0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;

        virtual void ArrayField(const std::string &field_name, const std::vector <std::reference_wrapper<const academia::Serializable>> &value)=0;

        virtual void Header(const std::string &object_name)=0;

        virtual void Footer(const std::string &object_name)=0;

        Serializer(std::ostream *out_);
    private:
        std::ostream* out_;
    };

    class XmlSerializer: public Serializer{};

    class Room: public Serializable
    {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        std::string EnumToString() const;
        Room() {}
        Room(int id, std::string name, Type type): id_(id), name_(name), type_(type){}
        void Serialize (Serializer *serial) const override ;

    private:
        int id_;
        std::string name_;
        Type type_;
    };

    class Building: public  Serializable
    {};



}
#endif //JIMP_EXERCISES_SERIALIZATION_H

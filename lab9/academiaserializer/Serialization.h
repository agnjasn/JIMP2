//
// Created by agnieszka on 09.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include<iostream>
#include<string>
#include <vector>
#include <initializer_list>
#include <sstream>
#include <functional>
#include <experimental/optional>

namespace academia
{
    class Serializer;
    class Serializable {
    public:
        virtual ~Serializable(){}

        Serializable(){}

        virtual void Serialize (Serializer *serial) const=0;
    };

    class Serializer {
    public:
        Serializer(){}

        virtual ~Serializer(){}

        virtual void IntegerField(const std::string &field_name, int value)=0;

        virtual void DoubleField(const std::string &field_name, double value)=0;

        virtual void StringField(const std::string &field_name, const std::string &value)=0;

        virtual void BooleanField(const std::string &field_name, bool value)=0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;

        virtual void ArrayField(const std::string &field_name, const std::vector <std::reference_wrapper<const academia::Serializable>> &value)=0;

        virtual void Header(const std::string &object_name)=0;

        virtual void Footer(const std::string &object_name)=0;

        Serializer(std::ostream *out);

    protected:
        std::ostream* out_;
    };

    class XmlSerializer: public Serializer
    {
    public:
        XmlSerializer(){}
        virtual ~XmlSerializer(){}
        XmlSerializer(std::ostream *out):Serializer(out){}
        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;

    };

    class JsonSerializer: public Serializer
    {
    public:
        JsonSerializer(){};
        virtual ~JsonSerializer(){};
        JsonSerializer(std::ostream *out):Serializer(out){}
        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };


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
        int Id() const { return id_;}

    private:
        int id_;
        std::string name_;
        Type type_;
    };

    class Building: public  Serializable
    {
    public:
       // friend  BuildingRepository;
        Building(){}
        virtual ~Building(){}
        Building(int id, std::string number, std::vector<Room> rooms):
                id_(id), number_(number)
        {
            for (int i; i<=rooms.size(); i++)
            {
                rooms_.emplace_back(rooms[i]);
            }

        }
        void Serialize(Serializer*) const override;
        int Id() const { return id_;}

    private:
        int id_;
        std::string number_;
        std::vector<std::reference_wrapper<const Serializable>> rooms_;
    };

    class BuildingRepository
    { public:
        //friend Building;
        BuildingRepository(){}
        virtual ~BuildingRepository(){}
        BuildingRepository(const std::initializer_list<Building> &buildings) : buildings_{buildings}{}
        void Add(Building bu);
        void StoreAll(Serializer *serializer);
        std::experimental::optional<Building> operator[](int b_id) const;

    private:
        std::vector<Building> buildings_;

    };

}
#endif //JIMP_EXERCISES_SERIALIZATION_H


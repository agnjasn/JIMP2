//
// Created by agnieszka on 21.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <iostream>
#include <vector>
namespace academia
{
    class SchedulingItem
    {
    public:
        virtual ~SchedulingItem() {}
        SchedulingItem(){}
        SchedulingItem(int course_id_,int teacher_id_,
                       int room_id_, int time_slot_,int year_) :
                course_id_(course_id_), teacher_id_(teacher_id_),
                room_id_(room_id_), time_slot_(time_slot_), year_(year_){}

        int CourseId() const {return course_id_;}
        int TeacherId() const {return teacher_id_;}
        int RoomId()const {return room_id_;}
        int TimeSlot()const { return  time_slot_;}
        int Year()const { return year_;}

    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };


    class Schedule
    {
    public:
        Schedule(){}
        virtual ~Schedule(){};
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;

        SchedulingItem operator[] (int val) const;

    private:
        std::vector<SchedulingItem> courses_;

    };


    class Scheduler
    {
    public:

    private:
    };

}
#endif //JIMP_EXERCISES_SCHEDULER_H

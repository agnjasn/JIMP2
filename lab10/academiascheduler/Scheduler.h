//
// Created by agnieszka on 21.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <iostream>
#include <vector>
namespace academia
{
    class SchedulingItem;
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

        const Schedule &operator[] (int val) const {}

    private:
    };

    class SchedulingItem: public Schedule
    {
    public:
        virtual ~SchedulingItem() {}
        SchedulingItem(){}
        SchedulingItem(int course_id_,int teacher_id_,int room_id_,int time_slot_,int year_): course_id(course_id_), teacher_id(teacher_id_), room_id(room_id_), time_slot(time_slot_), year(year_){}
        int CourseId() const {return course_id;}
        int TeacherId() const {return teacher_id;}
        int RoomId()const {return room_id;}
        int TimeSlot()const { return  time_slot;}
        int Year()const { return year;}

    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    };



    class Scheduler
    {
    public:

    private:
    };

}
#endif //JIMP_EXERCISES_SCHEDULER_H

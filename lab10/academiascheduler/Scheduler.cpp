//
// Created by agnieszka on 21.05.17.
//

#include "Scheduler.h"

namespace academia
{

    Schedule Schedule::OfTeacher(int teacher_id) const {
        return Schedule();
    }

    Schedule Schedule::OfRoom(int room_id) const {
        return Schedule();
    }

    Schedule Schedule::OfYear(int year) const {
        return Schedule();
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        return std::vector<int>();
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {

    }

    size_t Schedule::Size() const {
        return 0;
    }

}
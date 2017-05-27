//
// Created by agnieszka on 21.05.17.
//

#include "Scheduler.h"
#include <algorithm>
#include <map>

namespace academia
{

    Schedule Schedule::OfTeacher(int teacher_id) const {

        Schedule teacher_schedule{};
        std::vector<SchedulingItem>tmp;
        std::copy_if(courses_.begin(), courses_.end(), std::back_inserter(teacher_schedule.courses_), [teacher_id](SchedulingItem arg)
        {if (arg.TeacherId()==teacher_id)
            return true; else return false; } );
        return teacher_schedule;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule room_schedule{};
        std::vector<SchedulingItem>tmp;
        std::copy_if(courses_.begin(), courses_.end(), std::back_inserter(room_schedule.courses_), [room_id](SchedulingItem arg)
        {if (arg.RoomId()==room_id)
            return true; else return false; } );
        return room_schedule;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule year_schedule{};
        std::vector<SchedulingItem>tmp;
        std::copy_if(courses_.begin(), courses_.end(), std::back_inserter(year_schedule.courses_), [year](SchedulingItem arg)
        {if (arg.Year()==year)
            return true; else return false; } );
        return year_schedule;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> vec;
        for(int time=1; time<=n_time_slots; time++)
        {
            auto tmp=std::find_if(courses_.begin(), courses_.end(), [time](SchedulingItem arg)
            {
                if (arg.TimeSlot()!=time) return false;
                else return true;
            });
            if(tmp==courses_.end()) vec.push_back(time);
        }
        return vec;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {

        courses_.push_back(item);
    }

    size_t Schedule::Size() const {
        return courses_.size();
    }

    SchedulingItem Schedule::operator[](int val) const {
        return courses_[val];
    }

    Schedule Scheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                           const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                           const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) {
        return Schedule();
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {

        for (auto crs: courses_of_year)
        {
            if (!(crs.second.size() < n_time_slots))
            {
                throw NoViableSolutionFound();
            }
        }
        for (auto crs: teacher_courses_assignment)
        {
            if (!(crs.second.size() < n_time_slots))
            {
                throw NoViableSolutionFound();
            }
        }

        Schedule final_schedule{};

        int time=0;
        int room = 0;

        for (auto teacher:teacher_courses_assignment)
        {
            for(auto teacher_course:teacher.second)
            {
                for (auto y:courses_of_year)
                {
                    for (auto course:y.second)
                    {
                        if (teacher_course==course )
                        {
                            final_schedule.InsertScheduleItem(SchedulingItem{course ,teacher.first,rooms[room],time, y.first});
                            room++;
                            time++;
                            break;
                        }

                    }
                }

            }
        }


        return final_schedule;
    }
}

// linijka nietschego

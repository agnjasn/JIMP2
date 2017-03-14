//
// Created by Kinga on 14.03.2017.
//

#include "CCounter.h"
namespace ccounter {
std::unique_ptr<Counter> Init() {
    return std::make_unique<Counter>();

}

void Inc(std::string key, std::unique_ptr<Counter> *counter) {

    (*counter)->counter_map[key]++;
}

int Counts(const std::unique_ptr<Counter> &counter, std::string key) {
            return counter->counter_map[key];
}

void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter) {
    (*counter)->counter_map[key]=value;
}

}
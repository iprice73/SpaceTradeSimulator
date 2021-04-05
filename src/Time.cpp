#include "Time.hpp"

void Time::addObserver(Observer* obs) {
    observer_.push_back(obs);
}

void Time::removeObserver(Observer* obs) {
    observer_.remove(obs);
}

Time& Time::operator++() {
    time_++;
    for (const auto& el : observer_) {
        el->nextDay();
    }
    return *this;
}

#include "Time.hpp"

Time::Time()
    : time_(0) {}

void Time::addObserver(Observer* obs) {
    observer_.push_back(obs);
}

void Time::removeObserver(Observer* obs) {
    observer_.remove(obs);
}

void Time::notify(int days) {
    time_ += days;
    for (const auto& el : observer_) {
        el->nextDay(days);
    }
}

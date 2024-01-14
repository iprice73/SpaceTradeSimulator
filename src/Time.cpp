#include "Time.hpp"

Time::Time()
    : m_time(0) {}

void Time::addObserver(Observer* obs) {
    m_observer.push_back(obs);
}

void Time::removeObserver(Observer* obs) {
    m_observer.remove(obs);
}

void Time::notify(int days) {
    m_time += days;
    for (const auto& el : m_observer) {
        el->nextDay(days);
    }
}

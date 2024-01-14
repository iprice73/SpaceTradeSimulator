#pragma once
#include <list>

class Observer {
public:
    virtual void nextDay(int days) = 0;
    virtual ~Observer() = default;
};

class Time {
private:
    std::list<Observer*> m_observer{};
    std::size_t m_time{};

public:
    Time();
    std::size_t getTime() const { return m_time; }

    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);
    void notify(int days);
};

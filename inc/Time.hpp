#pragma once
#include <list>

class Observer {
public:
    virtual void nextDay(int days) = 0;
    virtual ~Observer() = default;
};

class Time {
private:
    std::list<Observer*> observer_{};
    std::size_t time_{};

public:
    Time();
    std::size_t getTime() const { return time_; }

    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);
    void notify(int days);
};

#pragma once
#include <list>

class Observer {
public:
    virtual void nextDay() = 0;
    virtual ~Observer() = default;
};

class Time {
private:
    std::list<Observer*> observer_{};
    size_t time_{};

public:
    size_t getTime() const { return time_; }

    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);

    Time& operator++();
};

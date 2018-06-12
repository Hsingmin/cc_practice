
// timefriend.h

#ifndef _TIMEFRIEND_H_
#define _TIMEFRIEND_H_

#include <iostream>

class Time{
    public:
        Time();
        Time(int h, int m=0);
        void AddMin(int m);
        void AddHour(int h);
        void Reset(int h=0, int m=0);
        Time operator+(const Time& t) const;
        Time operator-(const Time& t) const;
        Time operator*(double n) const;
        // Time Sum(const Time& t) const;
        void Show() const;
        ~Time();
        friend Time operator*(double m, const Time& t){
            return t*m;
        }
        friend std::ostream &operator<<(std::ostream &os, const Time& t);
    private:
        int hours;
        int minutes;
};

#endif




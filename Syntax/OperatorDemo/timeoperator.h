
// timeoperator.h

#ifndef _TIMEOPERATOR_H_
#define _TIMEOPERATOR_H_

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
    private:
        int hours;
        int minutes;
};

#endif




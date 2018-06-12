
// TimeFriend.cc

#include "timefriend.h"

using namespace std;

Time::Time(){
    hours = minutes = 0;
    cout<<"create Time class..."<<endl;
}

Time::Time(int h, int m){
    hours = h;
    minutes = m;
    cout<<"initialize Time class..."<<endl;
}

Time::~Time(){
    hours = minutes = -1;
    cout<<"delete Time class..."<<endl;
}

void Time::AddMin(int m){
    minutes += m;
    hours += minutes/60;
    minutes %= 60;
}

void Time::AddHour(int h){
    hours += h;
}

void Time::Reset(int h, int m){
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time& t) const{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes/60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time& t) const{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60*t.hours;
    tot2 = minutes + 60*hours;
    diff.minutes = (tot2 - tot2) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double mult) const{
    Time result;
    long totalminutes = hours*mult*60 + minutes*mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

std::ostream &operator<<(std::ostream &os, const Time& t){
    os<<t.hours<<" hours, "<<t.minutes<<" minutes";
    return os;
}

void Time::Show() const{
    cout<<hours<<" hours. "<<minutes<<" minutes";    
}









// exceptmean.h

#include <iostream>

class BadHMean{
    public:
        BadHMean(double a=0, double b=0): v1(a), v2(b){}
        void Mesg();
    private:
        double v1;
        double v2;
};

inline void BadHMean::Mesg(){
    std::cout<<"HMean("<<v1<<", "<<v2<<"): "
        <<"invalid arguments: a = -b\n";
}

class BadGMean{
    public:
        double v1;
        double v2;
        BadGMean(double a=0, double b=0): v1(a), v2(b){}
        const char *Mesg();
};

inline const char *BadGMean::Mesg(){
    return "GMean() arguments should be >= 0\n";
}

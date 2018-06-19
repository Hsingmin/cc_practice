
// VariableTest.cc

#include <iostream>
#include <string>
#include "variable.h"

// using namespace std;

void VariableTest(){
    string op = "minus";
    std::cout<<op<<" has "<<(expression::numOpArgs(op))<<" arguments.\n";

    op = "none";
    std::cout<<op<<" has "<<(expression::numOpArgs(op))<<" arguments.\n";
    op = "convolute";
    std::cout<<op<<" has "<<(expression::numOpArgs(op))<<" arguments.\n";
}

int main(int args, char **argv){
    VariableTest();
}

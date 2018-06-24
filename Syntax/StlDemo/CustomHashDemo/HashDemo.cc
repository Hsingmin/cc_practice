
// HashDemo.cc

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iomanip>
#include <functional>
#include <unordered_set>
#include "hash.h"

void HashTest(){
    expression::HashContent plus_op("plus", 2);
    expression::HashContent minus_op("minus", 2);
    expression::HashContent multiply_op("multiply", 2);
    expression::HashContent divide_op("divide", 2);
    expression::HashContent exponent_op("exponent", 1);
    expression::HashContent polynomial_op("polynomial", 1);

    expression::HashContent plus_op_vice = plus_op;
    
    std::cout<<plus_op.getOperation()<<" : "<<plus_op.getValue()<<"\n";

    expression::HashContent object = {"convolute", 256};

    std::cout<<object.getOperation()<<" : "<<object.getValue()<<"\n";
    std::cout<<"plus_op"<<" == "<<"convolute ? "<<(plus_op == object)<<"\n";

    std::cout<<"plus_op"<<" == "<<"plus_op_vice ? "<<(plus_op == plus_op_vice)<<"\n";
    
    std::cout<<std::hash<expression::HashContent>{}(object)<<"\n";

    /*
    std::unordered_set<expression::HashContent> ops = {plus_op,
                                           minus_op,
                                           multiply_op,
                                           divide_op,
                                           exponent_op,
                                           polynomial_op,
                                           plus_op_vice};
    for(auto& s: ops){
        std::cout<<s.getOperation()<<" "<<s.getValue()<<"\n";
    }
    */
}

int main(int args, char **argv){
    HashTest();
}







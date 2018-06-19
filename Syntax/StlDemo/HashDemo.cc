
// HashDemo.cc

#include <iostream>
#include <memory>
#include <vector>
#include "hash.h"

void HashTest(){
    expression::HashContent plus_op("plus", 2);
    expression::HashContent minus_op("minus", 2);
    expression::HashContent multiply_op("multiply", 2);
    expression::HashContent divide_op("divide", 2);
    expression::HashContent exponent_op("exponent", 1);
    expression::HashContent polynomial_op("polynomial", 1);

    expression::HashContent plus_op_vice = plus_op;


}

int main(int args, char **argv){
    HashTest();
}







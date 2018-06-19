
// Hash.cc

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "hash.h"

namespace expression{
    HashContent::HashContent(std::string op, int val):
        pImplement(new Implement(op, val)){}
    HashContent::~HashContent(){}

    HashContent::HashContent(const HashContent&) = default;
    HashContent& HashContent::operator=(const HashContent&) = default;
            
    // getter and setter
    std::string HashContent::getOperation() const{
        return pImplement->operation;
    }

    int HashContent::getValue() const{
        return pImplement->value;
    }
    
    bool HashContent::operator==(const HashContent& rhc) const{
        return pImplement.get() == rhc.pImplement.get();
    }

    HashContent::Implement::Implement(std::string op, int val):
        operation(op),
        value(val){};
}

namespace std{
    template<>
        size_t hash<expression::HashContent>::operator()
            (const expression::HashContent& hc) const{
                return std::hash<std::shared_ptr<expression::HashContent::Implement>>{}(hc.pImplement);
    }
}

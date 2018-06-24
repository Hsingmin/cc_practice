
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
    /*
    template<>
        struct hash<expression::HashContent>{
            size_t operator()(const expression::HashContent& hc) const noexcept{
                return std::hash<std::shared_ptr<expression::HashContent::Implement>>{}(hc.pImplement);
            }

        };
    */

    template<>
        struct hash<expression::HashContent>{
            typedef expression::HashContent argument_type;
            typedef std::size_t result_type;
            result_type operator()(argument_type const& hc) const noexcept{
                result_type const h(std::hash<std::shared_ptr
                        <argument_type::Implement>>{}(hc.pImplement));
                return h;
            }
    };

}

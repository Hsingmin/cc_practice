
// Variable.cc

#include <iostream>
#include <map>
#include <string>
#include "variable.h"

namespace expression{
    int numOpArgs(string op){
        static const std::map<string, int> op_args = {
            {"plus", 2},
            {"minus", 2},
            {"multiply", 2},
            {"divide", 2},
            {"exponent", 1},
            {"polynomial", 1},
            {"none", 0},
        };

        return op_args.find(op)->second;
    };
    
    // default 
    Variable::Variable(Variable&&) noexcept = default;
    Variable& Variable::operator=(Variable&&) noexcept = default;
    Variable::~Variable() = default;

    Variable::Variable(const Variable&) = default;
    Variable& Variable::operator=(const Variable&) = default;

    Variable Variable::clone(){
        return Variable(std::make_shared<Implement>(*pImpl));
    }

    Variable::Variable(std::shared_ptr<Implement> _pImpl): pImpl(_pImpl){};
    Variable::Variable(double _val): pImpl(new pImplement(_val)){}

    Variable::Variable(string _op, const std::vector<Variable>& _children):
        pImpl(new Implement(_op, _children)){}

    // getter and setter
    double Variable::getValue() const{
        return pImpl->value;
    }

    void Variable::setValue(double _val){
        pImpl->value = _val;
    }

    string Variable::getOperation() const{
        return pImpl->operation;
    }

    void Variable::setOperation(string _op){
        pImpl->operation = _op;
    }

    std::vector<Variable>& Variable::getParents() const{
        std::vector<Variable> _parents;
        for(std::weak_ptr<Implement> parent : pImpl->parents){
            _parents.emplace_back(parents.lock());
        }
        return _parents;
    }

    long Variable::getUseCount() const{
        return pImpl.use_count();
    }

    bool Variable::operator==(const Variable& rhs) const{
        return pImpl.get() == rhs.pImpl.get();
    }

    Variable::Implement::Implement(string _op, const std::vector<Variable>& _children):
        operation(_op){
            for(const Variable& v : _children){
                children.emplace_back(v.pImpl);
            }
        }
}

namespace std{
    size_t hash<expression::Variable>::operator()(const expression::Variable& v) const{
        return std::hash<std::shared_ptr<expression::Variable::Implement>>{}(v.pImpl);
    }
}



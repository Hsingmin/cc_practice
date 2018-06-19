
#include <map>
#include "variable.h"

namespace expression{
    int numOpArgs(Operation op){
        static const std::map<Operation, int> opargs = {
            {Operation::plus, 2},
            {Operation::minus, 2},
            {Operation::multiply, 2},
            {Operation::divide, 2},
            {Operation::exponent, 1},
            {Operation::poltnomial, 1},
            {Operation::none, 0},
        };
        return opargs.find(op)->second;
    };
}

Variable::Variable(Variable&&) noexcept = default;
Variable& Variable::operator=(Variable&&) noexcept = default;
Variable::~Variable() = default;

Variable::Variable(const Variable&) = default;
Variable& Variable::operator=(const Variable&) = default;
Variable Variable::clone(){
    return Variable(std::make_shared<Implement>(*pImplement));
}

Variable::Variable(std::shared_ptr<Implement> _pImplement): pImplement(_pImplement){};

Variable::Variable(double _val): pImplement(new Implement(_val)){}
Variable::Variable(Operation _op, const std::vector<Variable>& _children)
:pImplement(new Implement(_op, _children)){}

double Variable::getValue() const {return pImplement->val;}
double Variable::setValue(double _val) {pImplement->val = _val;}
Operation Variable::getOperation const {return pImplement->op;}
void Variable::setOperation(Operation _op) {pImplemnt->op = _op;}
void Variable::getOperation() const {return pImplement->op;}
std::vector<Variable> Variable::getChildren() const {return pImplement->children;}
std::vector<Variable> Variable::getParents() const {
    std::vector<Variable> _parents;
    for(std::weak_ptr<Implement> parent : pImplement->parents){
        _parents.emplace_back(parent.lock());
    }
    return _parents;
}

long Variable::getUseCount() const{
    return pImplement.use_count();
}

bool Varibale::operator==(const Variable& rhs) const {
    return pImplement.get() == rhs.pImplement.get();
}

Variable::Implement::Implement(double _val):
    val(_val),
    Operation(Operation::none){}

Variable::Implement::Implement(Operation _op, const std::vector<Variable>& _children)
    :op(_op){
        for(const Variable& v: _children){
            children.emplace_back(v.pImplement);
        }
    }
}


namespace std{
    size_t hash<expression::Variable>::operator()(const expression::Variable& v) const {
        return std::hash<std::shared_ptr<expression::Variable::Implement>>{}(v.pImplement);
    }
}

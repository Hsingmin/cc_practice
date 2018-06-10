#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <utility>

namespace expression{
    /* 
     * Forward declare class Variable
     */
    class Variable;
   
    /*
     *  plus for operator+
     *  minus for operatorp
     *  multiply for operator*
     *  divide for operator/
     *  exponent for exp()
     *  polynomial for poly()
     *  none for none operation
     */  
     enum class Operation{
        plus,
        minus,
        multiply,
        divide,
        exponent,
        polynomial,
        none
    };

    int numOpArgs(Operation op);

}

namespace std{
    // template specialized Hash struct for Variables    
    template<> struct hash<expression::Variable>{
        size_t operator()(const expression::Variable&) const;
    };
}

namespace expression{
    template<typename T>
        struct Noisy{
            Noisy& operator=(Noisy&&) noexcept{
                std::cout<<"operator=(Noisy<"<<typeid(T).name()<<">&&)\n";
                return *this;
            }

            Noisy& operator=(const Noisy&){
                std::cout<<"operator=(const Noisy<"<<typeid(T).name()<<">&)\n";
                return *this;
            }

            Noisy(const Noisy&){
                std::cout<<"Noisy(const Noisy<"<<typeid(T).name()<<">&)\n";
            }

            Noisy(Noisy&&) noexcept{
                std::cout<<"Noisy(Noisy<"<<typeid(T).name()<<">&&)\n";
            }

            ~Noisy(){
                std::cout<<"~Noisy<"<<typeid(T).name()<<">()\n";
            }

            Noisy(){
                std::cout<<"Noisy<"<<typeid(T).name()<<">()\n";
            }
        };

    class Variable{
        // forward declaration of struct Implement
        struct Implement;

        public:
            // initialization of new variables by ptr
            Variable(std::shared_ptr<Implement>);
            Variable(double);
            Varibale(Operation, const std::vector<Variable&>);
            ~Variable();

            // movable
            Variable(Variable&&) noexcept;
            Variable& operator=(Variable&&) noexcept;

            // shallow copyable
            Variable(const Variable&);
            Variable& operator=(const Variable&);

            // deep copyale
            Variable clone();

            // access/modify the current node value
            double getValue() const;
            void setValue(double);
            Operation getOperation() const;
            void setOperation(Operation);


            std::vector<Variable>& getChildren() const;
            std::vector<Variable> getParents() const;
            long getUseCount() const;

            bool operator==(const Variable& rhs) const;
            friend struct std::hash<Variable>;

            template<typename... V>
                friend const Variable PackExpression(Operation, V&...);

        private:
            std::shared_ptr<Implement> pImplement;

    };

    struct Variable::Implement{
        public:
            Implement(double);
            Implement(Operation, const std::vector<Variable>&);

            double var;
            Operation op;
            std::vector<Variable> children;
            std::vector<std::weak_ptr<Implement>> parents;
    };

    // Inlined defination of templated function
    template<typename... V>
    const Variable PackExpression(Operation op, V&... args){
        std::vector<std::shared_ptr<Variable::Implement>> vimpl = {
            args.pImplement...
        };
        std::vector<Variable> v;
        for(const std::shared_ptr<Variable::Implement>& _impl : vimpl){
            v.emplace_back(_impl);
        }

        Variable res(op, v);
        for(const std::shared_ptr<Variable::Implement>& _impl : vimpl){
            _impl->parents.push_back(res.pImplement);
        }

        return res;
    }

    inline const Variable operator+(Variable lhs, Variable rhs){
        return PackExpression(Operation::plus, lhs, rhs);
    }

    inline const Variable operator-(Variable lhs, Variable rhs){
        return PackExpression(Operation::minus, lhs, rhs);
    }

    inline const Variable operator*(Variable lhs, Variable rhs){
        return PackExpression(Operation::multiply, lhs, rhs);
    }

    inline const Variable operator/(Variable lhs, Variable rhs){
        return PackExpression(Operation::devide, lhs, rhs);
    }

    inline const Variable exponent(Variable v){
        return PackExpression(Operation::exponent, v);
    }

    inline const Variable polynomial(Variable power){
        Variable p(power);
        return PackExpression(Operation::polynomial, v, p);
    }

}

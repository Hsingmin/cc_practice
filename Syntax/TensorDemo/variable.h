
// variable.h

#include <iostream>

using namespace std;

namespace expression{
    
    class Variable{
        struct Implement;
        public:
            Variable(std::shared_ptr<Implement>);
            Variable(double);
            Variable(string, const std::vector<Variable>&);
            ~Variable();

            // movable
            Variable(Variable&&) noexcept;
            Variable& operator=(Variable&&) noexcept;

            // shallow copyable
            Variable(const Variable&);
            Variable& operator=(const Variable&);

            // deep copyable
            Variable clone();

            // function getter and setter
            double getValue() const;
            void setValue(double);
            string getOperation() const;
            void setOperation(string);

            std::vector<Variable>& getChildren() const;
            std::vector<Variable> getParents() const;
            long getUseCount() const;

            bool operator==(const Variable& rhs) const;
            friend struct std::hash<Variable>;

            template<typename... V>
                friend const Variable PackExpression(string, V&...);

        private:
            std::shared_ptr<Implement> pImpl;

    };

    int numOpArgs(string name);

    struct Variable::Implement{
        public:
            Implement(double);
            Implement(string, const std::vector<Variable>&);

            double value;
            string operation;
            std::vector<Variable> children;

            std::vector<std::weak_ptr<Implement>> parents;
    };


}


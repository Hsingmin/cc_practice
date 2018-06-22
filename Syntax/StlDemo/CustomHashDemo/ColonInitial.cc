
// ColonInitial.cc

#include <iostream>
#include <string>
#include <memory>

namespace expression{
    class HashContent{
        struct Implement;
        public:
            HashContent(std::string, int);
            ~HashContent();

            std::string getOperation() const;
            int getValue() const;

        private:
            std::shared_ptr<Implement> pImp;

    };

    struct HashContent::Implement{
        public:
            Implement(std::string, int);

            std::string operation;
            int number;
    };

    HashContent::HashContent(std::string op, int num):
        pImp(new Implement(op, num)){}
    HashContent::~HashContent(){}
    
    std::string HashContent::getOperation() const{
        return pImp->operation;
    }

    int HashContent::getValue() const{
        return pImp->number;
    }

    HashContent::Implement::Implement(std::string op, int num):
        operation(op),
        number(num){};

}

int main(){
    expression::HashContent h("add", 2);
    std::cout<<h.getOperation()<<" : "<<h.getValue()<<"\n";
}








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
        pImp(new Implement(op, num)){};
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

namespace std{
    class Queue{
        public:
            Queue(std::string, int);
            ~Queue();
            std::string getName() const;
            int getNumber() const;
        private:
            std::string name;
            int number; 
    };
    
    Queue::Queue(std::string name, int number):
        name(name), number(number){};
    Queue::~Queue(){};

    std::string Queue::getName() const{
        return name;
    }

    int Queue::getNumber() const{
        return number;
    }

}

int main(){
    expression::HashContent h("add", 2);
    std::cout<<h.getOperation()<<" : "<<h.getValue()<<"\n";

    expression::HashContent p("plus", 2);
    std::cout<<p.getOperation()<<" : "<<p.getValue()<<"\n";
    
    expression::HashContent conv("conv", 1024);
    std::cout<<conv.getOperation()<<" : "<<conv.getValue()<<"\n";

    std::Queue q("queue", 10);
    std::cout<<q.getName()<<" : "<<q.getNumber()<<"\n";

}








// hash.h

#include <iostream>
#include <string>
#include <vector>

namespace expression{
    class HashContent{
        struct Implement;  // class struct member 
        public:
            // constructor and operator
            HashContent(std::string, int);
            ~HashContent();

            HashContent(const HashContent&);
            HashContent& operator=(const HashContent&);
            
            // getter and setter
            std::string getKey() const;
            int getValue() const;
            std:: string getOperation() const;
            // friend struct and function
            bool operator==(const HashContent& rhc) const;
            friend struct std::hash<HashContent>;

        private:
            // private member pointer
            std::shared_ptr<Implement> pImplement;
    };

    struct HashContent::Implement{
        public:
            // constructor
            Implement(double);
            Implement(std::string, int);

            // data member
            int value;
            std::string operation;
    };

}

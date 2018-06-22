
// StdHashDemo.cc

#include <iostream>
#include <string>
#include <iomanip>
#include <functional>
#include <unordered_set>

int HashSimple(){
    std::string s = "Standard back! I've got jimies!";
    std::hash<std::string> hash_fn;

    size_t h = hash_fn(s);

    std::cout<<h<<'\n';

    return 0;
}

struct HashContent{
    std::string head;
    std::string tail;
};

bool operator==(const HashContent& lhs, const HashContent& rhs){
    return lhs.head == rhs.head && lhs.tail == rhs.tail;
}

// custom hash can be a standalone functional object
struct CustomHash{
    std::size_t operator()(HashContent const& c) const noexcept{
        // h1 and h2 are both hash containing std::string type
        std::size_t h1 = std::hash<std::string>{}(c.head);
        std::size_t h2 = std::hash<std::string>{}(c.tail);
        return h1^(h2<<1);
    }
};

// custom specialization of std::hash can be injected in namespace std
namespace std{
    template<>
        struct hash<HashContent>{
            typedef HashContent argumentType;
            typedef std::size_t resultType;
            resultType operator()(argumentType const& c) const noexcept{
                resultType const h1(std::hash<std::string>{}(c.head));
                resultType const h2(std::hash<std::string>{}(c.tail));
                return h1^(h2<<1);
            }
        };
}

int HashComplex(){

    // simple usage of hash<Type>
    std::string str = "Meet the new boss...";
    std::size_t str_hash = std::hash<std::string>{}(str);
    std::cout<<"hash("<<std::quoted(str)<<") = "<<str_hash<<'\n';

    // usage of custom hash
    HashContent object = {"Hubert", "Farnsworth"};
    std::cout<<"hash("<<std::quoted(object.head)<<", "
        <<std::quoted(object.tail)<<") = "
        <<CustomHash{}(object)<<" (using CustomHash)\n or "
        <<std::hash<HashContent>{}(object)
        <<" (using injected std::hash<HashContent> specialization)\n";

    // custom hash makes it possible to use custom types in unordered containers
    // 
    std::unordered_set<HashContent> names = {
        object,
        {"Bender", "Rodriguez"},
        {"Leela", "Turanga"}};
    for(auto& s: names){
        std::cout<<std::quoted(s.head)<<" "<<std::quoted(s.tail)<<"\n";
    }
    return 0;
}

int main(){
    HashComplex();
}

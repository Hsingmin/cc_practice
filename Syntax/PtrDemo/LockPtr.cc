
// LockPtr.cc

#include <iostream>
#include <memory>

int main(int args, char **argv){
    std::shared_ptr<int> sp1, sp2;
    std::weak_ptr<int> wp;

    sp1 = std::make_shared<int>(20);  // sp1 = new int(20)
    wp = sp1;  // *wp = 20

    sp2 = wp.lock();  // *sp2 = 20
    sp1.reset();  // sp1 delete

    sp1 = wp.lock();  // *sp1 = 20
    //sp1 = wp;

    std::cout<<"*sp1 = "<<(*sp1)<<"\n";
    std::cout<<"*sp2 = "<<(*sp2)<<"\n";

    return 0;
}

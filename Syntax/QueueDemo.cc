
// STL <queue> usage

#include <iostream>
#include <queue>
// #include <assert.h>

using namespace std;

int main(int args, char **argv){
    queue<int> myQueue;
    cout<<"Is myQueue empty?"<<myQueue.empty()<<endl;

    for(int i=0; i<10; ++i){
        myQueue.push(i);
    }
    for(int i=0; i<myQueue.size(); ++i){
        cout<<"myQueue.size(): "<<myQueue.size()<<endl;
        cout<<myQueue.front()<<endl;
        myQueue.pop();
    }

    // system("PAUSE");
    return 0;
}


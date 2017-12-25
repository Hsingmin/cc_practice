
//带有额外整型参数的operator new重载 
#include<new>
using namespace std;

class MemoryDemo
{
  public:
    MemoryDemo();
    ~MemoryDemo();
    void* operator new(size_t size) throw(bad_alloc);
    void operator delete(void* ptr) throw();
    void* operator new[](size_t size) throw(bad_alloc);
    void operator delete[](void* ptr)throw();
    void* operator new(size_t size,const nothrow_t&) throw();
    void operator delete(void* ptr,const nothrow_t&) throw();
    void* operator new[](size_t size,const nothrow_t&) throw();
    void operator delete[](void* ptr,const nothrow_t&) throw();
    void* operator new(size_t size,int extra) throw(bad_alloc);
};

void* MemoryDemo::operator new(size_t size,int extra) throw(bad_allcoc)
{
  cout<<"operator new with extra int arg\n";
  return (::operator new(size));
}


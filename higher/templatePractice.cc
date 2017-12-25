//在头文件中定义模板
template<typename T>
class Grid
{
        //Omitted for brevity.
} ;
#include"GridDefinations.h" //模板的方法定义放在一个单独的头文件中 

//将方法的定义放在源文件中
template<typename T>
class Grid
{
  //Omitted .      
} ;
#include"Grid.cpp" //保证方法定义对于使用模板的代码是可见的

//实例化Grid
Grid<int> myGrid;
Grid<int,10> anotherGrid;
Grid<int,10,10> thirdGrid; 

//��ͷ�ļ��ж���ģ��
template<typename T>
class Grid
{
        //Omitted for brevity.
} ;
#include"GridDefinations.h" //ģ��ķ����������һ��������ͷ�ļ��� 

//�������Ķ������Դ�ļ���
template<typename T>
class Grid
{
  //Omitted .      
} ;
#include"Grid.cpp" //��֤�����������ʹ��ģ��Ĵ����ǿɼ���

//ʵ����Grid
Grid<int> myGrid;
Grid<int,10> anotherGrid;
Grid<int,10,10> thirdGrid; 

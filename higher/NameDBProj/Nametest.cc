#include"NameDB.h"
#include"NameDB.cpp"

int main(int argc,char** argv)
{
  NameDB boys("boys_long.txt");

  cout<<boys.getNameRank("Daniel")<<endl;
  cout<<boys.getNameRank("Jacobi")<<endl;
  cout<<boys.getNameRank("William")<<endl;

  return (0);
}

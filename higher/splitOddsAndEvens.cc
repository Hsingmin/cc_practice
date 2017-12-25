#include<iostream>
using namespace std;

void separateOddsAndEvens(const int arr[],int size,int*& odds,int& numOdds,int*& evens,int& numEvens)
{
  int i;
  numOdds=numEvens=0;
  for(i=0;i<size;i++)
  {
    if(arr[i]%2==1)
    {
      numOdds++;
    }
    else
      numEvens++;
  }

odds=new int[numOdds];
evens=new int[numEvens];

int oddsPos=0,evensPos=0;
for(i=0;i<size;i++)
{
  if(arr[i]%2==1)
  {
    odds[oddsPos++]=arr[i];
  }
  else
    {
      evens[evensPos++]=arr[i];
    }
}

}
int main()
{
  int unSplit[10]={1,2,3,4,5,6,6,8,9,10};
  int *oddNums,*evenNums;
  int numOdds,numEvens;
  separateOddsAndEvens(unSplit,10,oddNums,numOdds,evenNums,numEvens);
  cout<<*oddNums<<endl;
  cout<<*evenNums<<endl;
  cout<<numOdds<<endl;
  cout<<numEvens<<endl; 
}

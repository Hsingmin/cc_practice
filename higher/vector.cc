#include<vector>
#include<iostream>
using namespace std;

int main(int argc,char** argv)
{
  vector<double> doubleVector(10); //Create a vector.
  double max;
  int i;

  for(i=0;i<10;i++)
  {
    doubleVector[i]=0;
  }

  //Read the first score before the loop in order to initialize the max.
  cout<<"Enter score 1:"<<endl;
  cin>>doubleVector[0];
  max=doubleVector[0];

  for(i=1;i<10;i++)
  {
    cout<<"Enter score "<<i+1<<": "<<endl;
    cin>>doubleVector[i];
    if(doubleVector[i]>max)
    {
      max=doubleVector[i];
    }
  }

  max /=100;
  for(i=0;i<10;i++)
  {
    doubleVector[i] /=max;
    cout<<doubleVector[i]<<" ";
  }
  cout<<endl;
  return (0);
}

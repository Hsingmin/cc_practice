#include<iostream>
using std::cin;
using std::cout;
using std::endl;

float GetValueBetween(float min,float max)
{
  float temp,accept;
  cout<<"Enter a value between"<<min<<","<<max;
  cin>>temp;
  accept=1.0;
  while(accept>0.0)
  {
    if(temp>=min)
      if(temp<=max) accept=0.0;
    if(accept>0.0)
    {
       cout<<"**Illegal value,enter again:"<<endl;
       cin>>temp;
    }
  }
  return (temp);
}

void CalcTable(float startperiod,float endperiod)
{
  //void operation
}

main()
{
  float amount,rate,startperiod,endperiod;
  amount=GetValueBetween(0.0,30000.0);
  rate=GetValueBetween(0.0,1.0);
  startperiod=GetValueBetween(1.0,71.0);
  endperiod=GetValueBetween(startperiod,72);
  
  CalcTable(startperiod,endperiod);
}



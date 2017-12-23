#include<math.h>

float RateExpr(float rate,float k)
{
  float temp;
  temp=1.0+rate;
  return (pow(temp,-k));
}

float Payment(float principal,float rate,float num_pay)
{
  float paymnt;
  paymnt=principal*(rate/(1.0-RateExpr(rate,num_pay)));
  return (paymnt);
}

void Amortize(float& accum,float& bal,float rate,float pmnt,float prin,float num)
{
  float temp;
  temp=RateExpr(rate,num);
  bal=(1.0/temp)*((pmnt*(temp-1.0)/rate)+prin);
  accum=bal+num*pmnt-prin;
}




















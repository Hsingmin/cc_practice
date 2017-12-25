
//对象数组 
class Sample
{
  public:
         void Sample() {cout<<"This is a sample!"<<endl;}      
};

int main(int argc,char** argv)
{
  Sample* mySampleArray=new Sample[4];  
  delete [] mySampleArray;  
}

//指针数组

int main(int argc,char** argv)
{
  Sample** mySampleArray=new Sample*[4];
  for(i=0;i<4;i++)
  {
    mySampleArray[i]=new Sample();                
  }
  
  for(i=0;i<4;i++)
  {
    delete mySampleArray[i];                
  }
  
  delete [] mySampleArray;
} 

//为二维数组分配内存
char** allocateCharacterBoard(int xDemension,int yDemension)
{
  char** myArray=new char*[xDemension];
  for(int i=0;i<xDemension;i++)
  {
    myArray[i]=new char[ydDemension];        
  }       
  return (myArray);
}

//Release the memory.
char** releaseCharacterBoard(int xDemension,int yDemension)
{
  for(int i=0;i<xDemension;i++)
  {
    delete [] myArray[i];        
  }       
  
  delete [] myArray; 
}

//指针与数组
int main(int argc,char** argv)
{
  int myArray[10];
  int* myPtr=myArray;
  
  myPtr[4]=8;
} 

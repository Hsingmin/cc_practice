
//�������� 
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

//ָ������

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

//Ϊ��ά��������ڴ�
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

//ָ��������
int main(int argc,char** argv)
{
  int myArray[10];
  int* myPtr=myArray;
  
  myPtr[4]=8;
} 

/*************************************
*�ṩ������캯�� 
*
*/ 
class SpreadsheetCell
{
  public:
         SpreadsheetCell(double initialValue);
         SpreadsheetCell(string initialValue);
         SpreadsheetCell(const SpreadsheetCell& src);//���ƹ��캯�� 
  protected:
            double mValue;
            string inString;
   
} 

/*****************************************
*string���͵Ĺ��캯��ʵ�� 
*/

SpreadsheetCell::SpreadsheetCell(string initialValue) 
{
  setString(initialValue);
}


/**************************************
*ʹ�ù��캯�� 
*
*/ 
SpreadsheetCell aThirdCell(3.9);
SpreadsheetCell aForthCell("test");
SpreadsheetCell *aThirdCellp=new SpreadsheetCell("3.9");
cout<<"aTirdCell: "<<aThirdCell.getValue()<<endl;
cout<<"aForthCell: "<<aForthCell.getValue()<<endl;
cout<<"aThirdCell: "<<aThirdCell->getValue()<<endl;
delete aThirdCellp;

/********************************************
*Ĭ�Ϲ��캯�� 
*/ 

class SpreadsheetCell
{
  SpreadsheetCell();
  SpreadsheetCell(double initialValue);
  SpreadsheetCell(string initialValue);      
} 

/*****************************************
*��Ĭ�Ϲ��캯����ʵ�� 
*/
SpreadsheetCell::SpreadsheetCell()
{
  mValue=0;
  mString="";                                  
}

/********************************************
*���ƹ��캯��ʵ�� 
*/ 

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src):
mValue(src.mValue),mString(src.mString)
{
}
/********************************
*��ʽ���ø��ƹ��캯�� 
*/
SpreadsheetCell myCell2(2.9);
SpreadsheetCell anotherCell(myCell2);

/*********************************************
*�������������������� 
*/ 
int main(int argc,char** argv)
{
  SpreadsheetCell myCell(4);
  if(myCell.getValue()==4)
  {
    SpreadsheetCell anotherCell(5);                        
  }    //anotherCell will be deleted
  
  cout<<"myCell: "<<myCell.getValue()<<endl;
  return (0);
} //myCell will be deleted

/**********************************
*ʹ��delte���������������������ͷ��ڴ� 
*/
int main(int argc,char** argv)
{
  SpreadsheetCell *myCellp1=new SpreadsheetCell(5);
  SpreadsheetCell *myCellp2=new SpreadsheetCell(4);

  cout<<"myCellp1: "<<myCell->getValue()<<endl;
  delete myCellp1;  
  return (0);
} //myCellp2 ���ᱻ��������Ϊû�е���delete

/*********************************************
*��д���ƹ��캯�� 
*/ 
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
{
  mValue=src.mValue;
  mString=src.mString;                                       
} 

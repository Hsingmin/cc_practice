/*************************************
*提供多个构造函数 
*
*/ 
class SpreadsheetCell
{
  public:
         SpreadsheetCell(double initialValue);
         SpreadsheetCell(string initialValue);
         SpreadsheetCell(const SpreadsheetCell& src);//复制构造函数 
  protected:
            double mValue;
            string inString;
   
} 

/*****************************************
*string类型的构造函数实现 
*/

SpreadsheetCell::SpreadsheetCell(string initialValue) 
{
  setString(initialValue);
}


/**************************************
*使用构造函数 
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
*默认构造函数 
*/ 

class SpreadsheetCell
{
  SpreadsheetCell();
  SpreadsheetCell(double initialValue);
  SpreadsheetCell(string initialValue);      
} 

/*****************************************
*对默认构造函数的实现 
*/
SpreadsheetCell::SpreadsheetCell()
{
  mValue=0;
  mString="";                                  
}

/********************************************
*复制构造函数实现 
*/ 

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src):
mValue(src.mValue),mString(src.mString)
{
}
/********************************
*显式调用复制构造函数 
*/
SpreadsheetCell myCell2(2.9);
SpreadsheetCell anotherCell(myCell2);

/*********************************************
*对象撤销：按建立的逆序 
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
*使用delte调用析构函数撤销对象，释放内存 
*/
int main(int argc,char** argv)
{
  SpreadsheetCell *myCellp1=new SpreadsheetCell(5);
  SpreadsheetCell *myCellp2=new SpreadsheetCell(4);

  cout<<"myCellp1: "<<myCell->getValue()<<endl;
  delete myCellp1;  
  return (0);
} //myCellp2 不会被撤销，因为没有调用delete

/*********************************************
*编写复制构造函数 
*/ 
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
{
  mValue=src.mValue;
  mString=src.mString;                                       
} 

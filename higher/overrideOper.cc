//重载-操作符
class SpreadsheetCell
{
  //Omitted for brevity.
  const SpreadsheetCell operator-() const;      
  //Omitted for brevity.
} ;

//The difination for operator -
const SpreadsheetCell SpreadsheetCell::operator-() const
{
  SpreadsheetCell newCell(*this);
  newCell.set(-mValue);
  return(newCell);      
}

//SpreadsheetCell类中operator<<和operator>>的实现
ostream& operator<<(ostream& ostr,const SpreadsheetCell& cell) 
{
  ostr<<cell.mString;
  return(ostr);         
}

istream& operator>>(istream& istr,const SpreadsheetCell& cell)
{
  string temp;
  istr>>temp;
  cell.set(temp);
  return(istr);         
}

//重载下标操作符的实现
int& Array::operator [] (int x)
{
       if(x<0)
       throw out_of_range("");
       
       if(x>=mSize)
       //将数组的长度增加到用户所需要的值 
       resize(x+kAllocSize);
       
       return (mElems[x]); 
} 

//重载spring
class SpreadhseetCell 
{
  public:
         //Omitted for brevity.
         operator string() const;
         //Omitted for brevity.      
} ;

SpreadsheetCell::operator string() const
{
  return(mString);                          
}

// 引用 
SpreadsheetCell cell1;
string str1=cell1;

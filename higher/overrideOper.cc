//����-������
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

//SpreadsheetCell����operator<<��operator>>��ʵ��
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

//�����±��������ʵ��
int& Array::operator [] (int x)
{
       if(x<0)
       throw out_of_range("");
       
       if(x>=mSize)
       //������ĳ������ӵ��û�����Ҫ��ֵ 
       resize(x+kAllocSize);
       
       return (mElems[x]); 
} 

//����spring
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

// ���� 
SpreadsheetCell cell1;
string str1=cell1;

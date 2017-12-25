//Spreadsheet.h

#include"SpreadsheetCell.h"

class Spreadsheet
{
  public:
    Spreadsheet(int inWidth,int inHeight);
    ~Spreadsheet();//析构函数 
    void setCellAt(int x,int y,const SpreadsheetCell& cell);
    SpreadsheetCell getCellAt(int x,int y);
    Spreadsheet& operator=(const Spreadsheet& rhs);

  protected:
    bool inRange(int val,int upper);
    int mWidth,mHeight;
    SpreadsheetCell** mCells;
};

/***********************************************************
*析构函数的实现 
*/
Spreadsheet::~Spreadsheet()
{
  for(i=0;i<mWidth;i++)
  {
    delete[] mCells[i];                     
  }                    
  delete[] mCells;       
}


/***********************************************************
*动态分配二维数组 
*/ 
#include"Spreadsheet.h"

Spreadsheet::Spreadsheet(int inWidth,int inHeight):
  mWidth(inWidth),mHeight(inHeight)
{
  mCells=new SpreadsheetCell* [mWidth];
  for(int i=0;i<mWidth;i++)
  {
    mCells[i]=new SpreadsheetCell[mHeight];
  }
}

/*************************************************************
*二维数组实现 
*/ 
void Spreadsheet::setCellAt(int x,int y,const SpreadsheetCell& cell)
{
  if(!inRange(x,mWidth)||!inRange(y,mHeight))
  {
    return ;
  }
  mCells[x][y]=cell;
}

  SpreadsheetCell Spreadsheet::getCellAt(int x,int y)
  {
    SpreadsheetCell empty;
    if(!inRange(x,mWidth)||!inRange(y,mHeight))
    {
      return (empty);
    }
    return (mCells[x][y]);
  } 
  
/************************************************
*复制操作符的实现 
*/
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
  int i,j;
  if(this=&rhs)
  {
    return (*this);             
  }     //检查是否为自赋值        
  
  //释放旧内存
  for(i=0;i<mWidth;i++)
  {
    delete[] mCells[i];                     
  } 
  delete[] mCells;
  
  //重新分配内存 
  mWidth=rhs.mWidth;
  mHeight=rhs.mHeight;
  mCells=new SpreadsheetCell* [mWidth];
  
  for(i=0;i<mWidth;i++)
  {
    mCells[i]=new SpreadsheetCell[mHeight];                     
  }   
  for(i=0;i<mWidth;i++)
  {
    for(j=0;j<mHeight;j++)
    {
      mCells[i][j]=rhs.Cells[i][j];                      
    }                     
  }
  return (*this);
  
}

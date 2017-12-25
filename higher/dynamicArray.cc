//Spreadsheet.h

#include"SpreadsheetCell.h"

class Spreadsheet
{
  public:
    Spreadsheet(int inWidth,int inHeight);
    ~Spreadsheet();//�������� 
    void setCellAt(int x,int y,const SpreadsheetCell& cell);
    SpreadsheetCell getCellAt(int x,int y);
    Spreadsheet& operator=(const Spreadsheet& rhs);

  protected:
    bool inRange(int val,int upper);
    int mWidth,mHeight;
    SpreadsheetCell** mCells;
};

/***********************************************************
*����������ʵ�� 
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
*��̬�����ά���� 
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
*��ά����ʵ�� 
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
*���Ʋ�������ʵ�� 
*/
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
  int i,j;
  if(this=&rhs)
  {
    return (*this);             
  }     //����Ƿ�Ϊ�Ը�ֵ        
  
  //�ͷž��ڴ�
  for(i=0;i<mWidth;i++)
  {
    delete[] mCells[i];                     
  } 
  delete[] mCells;
  
  //���·����ڴ� 
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

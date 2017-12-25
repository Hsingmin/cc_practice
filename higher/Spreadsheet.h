//Spreadsheet.h

#include"SpreadsheetCell.h"

class Spreadsheet
{
  public:
    Spreadsheet(int inWidth,int inHeight);
    void setCellAt(int x,int y,const SpreadsheetCell& cell);
    SpreadsheetCell getCellAt(int x,int y);

  protected:
    bool inRange(int val,int upper);
    int mWidth,mHeight;
    SpreadsheetCell** mCells;
};

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


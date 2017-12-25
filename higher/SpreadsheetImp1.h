//SpreadsheetImp1.h
#include"SpreadsheetCell.h"

class SpreadsheetApplication;//Forward reference

class SpreadsheetImp1
{
  public:
    SpreadsheetImp1(const SpreadsheetApplication& theApp,
      int inWidth=kMaxwidth,int inHeight=kMaxHeight);
    SpreadsheetImp1(const SpreadsheetImp1& src);
    ~SpreadsheetImp1();
    SpreadsheetImp1 &operator=(const SpreadsheetImp1& rhs);
    
    void setCellAt(int x,int y,const SpreadsheetCell& inCell);
    SpreadsheetCell getCellAt(int x,int y);

    int getID();
    
    static const int kMaxHeight=100;
    static const int kMaxWidth=100;

    protected:
      bool inRange(int val,int upper);
      void copyFrom(const SpreadsheetImp1& src);

      int mWidth,mHeight;
      int mID;
      SpreadsheetCell** mCells;
      const SpreadsheetApplication& mTheApp;

      static int sCounter;
};

//New Spreadsheet class

#include"SpreadsheetCell.h"
//Forward declarations
class SpreadsheetImp1;
class SpreadsheetApplication;

class Spreadsheet
{
  public:
    Spreadsheet(const SpreadsheetApplication& theApp,int inWidth,int inHeight);
    Spreadsheet(const SpreadsheetApplication& theApp);
    Spreadsheet(const Spreadsheet& src);
    ~Spreadsheet();
    Spreadsheet& operator=(const Spreadsheet& rhs);
    void setCellAt(int x,int y,const SpreadsheetCell& inCell);
    SpreadsheetCell getCellAt(int x,int y);
    int getID();
  
  protected:
    SpreadsheetImp1* mImp1;
}

//这个类只有一个数据成员：指向SpreadsheetImp1的数据指针 

void Spreadsheet::setCellAt(int x,int y,const SpreadsheetCell& inCell)
{
  mImp1->setCellAt(x,y,inCell);
}

SpreadsheetCell Spreadsheet::getCellAt(int x,int y)
{
  return (mImp1->getCellAt(x,y));
}

int Spreadsheet::getID()
{
  return (mImp1->getID());
}



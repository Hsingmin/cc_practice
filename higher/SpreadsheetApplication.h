class SpreadsheetApplication;

class Spreadsheet
{
  public:
    Spreadsheet(int inWidth,int inHeight,SpreadsheetApplication& theApp);
    //Code omitted for brevity.

  protected:
    //Code omitted for brevity.
    SpreadsheetAppliction& mTheApp;

    static int sCounter;
}

//在构造函数的初始化列表中为mTheApp给定一个值;

Spreadsheet::Spreadsheet(int inWidth,int inHeight,SpreadsheetApplication& theApp)
:mwidth(inWidth<kMaxWidth?inWidth:kMaxWidth),
mHeight(inHeight<kMaxHeight?inHeight:kMaxHeight)
{
  //Code omitted for brevity.
}

//在复制构造函数中初始化引用成员 

Spreadsheet::Spreadsheet(const Spreadsheet& src):
mTheApp(src.mTheApp)
{
  mID=sCounter++;
  copyFrom(src);
}



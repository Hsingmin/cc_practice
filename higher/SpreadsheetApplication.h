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

//�ڹ��캯���ĳ�ʼ���б���ΪmTheApp����һ��ֵ;

Spreadsheet::Spreadsheet(int inWidth,int inHeight,SpreadsheetApplication& theApp)
:mwidth(inWidth<kMaxWidth?inWidth:kMaxWidth),
mHeight(inHeight<kMaxHeight?inHeight:kMaxHeight)
{
  //Code omitted for brevity.
}

//�ڸ��ƹ��캯���г�ʼ�����ó�Ա 

Spreadsheet::Spreadsheet(const Spreadsheet& src):
mTheApp(src.mTheApp)
{
  mID=sCounter++;
  copyFrom(src);
}



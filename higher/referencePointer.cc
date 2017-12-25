//引用 
int  x=3,y=5;
int& iRef=x;
iRef=y;//x的值将会改变成5.诡异。

//来自指针的引用
int x=3,y=4;
int *xp=&x,*yp=&y;
Swap(*xp,yp*);

//
typedef Grid<SpreadsheetCell> Spreadsheet;

int main()
{
      Spreadsheet mySpreadsheet;
      //Rest of the program...
}

void ProcessSpreadsheet(const Spreadsheet& mySpreadsheet)
{
  //Body omitted...     
}

//创建短名称，用来在Spreadsheet作用域中引用SpreadsheetCell类型 
typedef Spreadsheet::SpreadsheetCell SCell;

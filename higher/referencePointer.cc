//���� 
int  x=3,y=5;
int& iRef=x;
iRef=y;//x��ֵ����ı��5.���졣

//����ָ�������
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

//���������ƣ�������Spreadsheet������������SpreadsheetCell���� 
typedef Spreadsheet::SpreadsheetCell SCell;

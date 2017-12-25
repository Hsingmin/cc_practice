/***********************************
*在栈上使用构造函数 
*/

SpreadsheetCell myCell(4),anotherCell(5);
cout<<" cell1: "<<myCell.getValue()<<endl;
cout<<" cell2: "<<anotherCell.getValue()<<endl;

/************************************
*在堆上使用构造函数
*/

SpreadsheetCell *myCellp=SpreadsheetCell(4);
SpreadsheetCell *anotherCellp;
anotherp=new SpreadsheetCell(5);
delete anotherCellp;

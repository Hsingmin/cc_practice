/***********************************
*��ջ��ʹ�ù��캯�� 
*/

SpreadsheetCell myCell(4),anotherCell(5);
cout<<" cell1: "<<myCell.getValue()<<endl;
cout<<" cell2: "<<anotherCell.getValue()<<endl;

/************************************
*�ڶ���ʹ�ù��캯��
*/

SpreadsheetCell *myCellp=SpreadsheetCell(4);
SpreadsheetCell *anotherCellp;
anotherp=new SpreadsheetCell(5);
delete anotherCellp;

SpreadsheetCell myCell(4);

cout<<myCell.getValue()<<endl;//correct
myCell.setString("9.0");

const SpreadsheetCell& anotherCell=myCell;//correct
cout<<anotherCell.getValue()<<endl;
anotherCell.setString("9.0");//incorrect

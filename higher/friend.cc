//定义友元 
class Spreadsheet
{
  public:
         friend class SpreadsheetCell;
         //SpreadsheetCell可以访问Spreadsheet的private和public      
} 

//add方法
class SpreadsheetCell
{
  public:
         //Omitted for brevity. 
         const SpreadsheetCell add(const SpreadsheetCell& cell) const;
         //Omitted for brevity.
} 

//add实现

const SpreadsheetCell SpreadsheetCell::add(const SpreadsheetCell& cell) const
{
        SpreadsheetCell newCell;
        newCell.set(mValue+Cell.mValue);
        return (newCell);
}

SpreadsheetCell myCell(4),anoterCell(5);
SpreadsheetCell aThirdCell=myCell.add(anotherCell);

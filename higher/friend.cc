//������Ԫ 
class Spreadsheet
{
  public:
         friend class SpreadsheetCell;
         //SpreadsheetCell���Է���Spreadsheet��private��public      
} 

//add����
class SpreadsheetCell
{
  public:
         //Omitted for brevity. 
         const SpreadsheetCell add(const SpreadsheetCell& cell) const;
         //Omitted for brevity.
} 

//addʵ��

const SpreadsheetCell SpreadsheetCell::add(const SpreadsheetCell& cell) const
{
        SpreadsheetCell newCell;
        newCell.set(mValue+Cell.mValue);
        return (newCell);
}

SpreadsheetCell myCell(4),anoterCell(5);
SpreadsheetCell aThirdCell=myCell.add(anotherCell);

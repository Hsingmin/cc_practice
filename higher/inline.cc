//������������������ 

inline SpreadsheetCell::getValue() const
{
  mNumAccess++;
  return (mValue);      
} 
inline SpreadsheetCell::getString() const
{
  mNumAccess++;
  return (mString);      
}

//ֱ�ӽ����������������ඨ����
class SpreadsheetCell
{
  public:
         SpreadsheetCell();
         ~SpreadsheetCell();
         SpreadsheetCell(double initialValue);
         SpreadsheetCell(const string& initialString);
         SpreadsheetCell(const SpreadsheetCell& src);
         SpreadsheetCell operator=(const SpreadsheetCell& rhs);
         void set(double inValue);
         void set(const string& inString);
        
        //����inline���������� 
         double getValue() const
         {
           numAccess++;
           return (mValue);       
         }
         
         string getString() const
         {
           numAccess++;
           return (mString);       
         }
         
  protected:
            double mValue;
            string mString;
            
            mutable int numAccess;//������ 
          
               
} 


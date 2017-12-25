//内联函数与内联方法 

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

//直接将内联方法放置在类定义中
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
        
        //不用inline的内联函数 
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
            
            mutable int numAccess;//计数器 
          
               
} 


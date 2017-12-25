class Person
{
  public:
    Person();
    Person(const string& inFirstName,const string& inLastNme,int inAge);
    string getFirstName() {return firstName;}
    string getLastName() {return lastName;}
    int getAge() {return age;}

  private:
    string firstName,lastName;
    int age;
};

//按引用传递 
void processPerson(const Person& p)
{
  //Process the person.
}

Person me("Nicholas","Solter",18);
processPerson(me);

//全局operator+
class SpreadsheetCell
{
  public:
         //The other constructors Omitted for brevity.
         SpreadsheetCell(double inValue);
         
         friend const SpreadsheetCell operator+(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
         //Remainder Omitted for brevity.        
} ;

//使用全局operator+，进行其他类型的转换
SpreadsheetCell myCell(4),aThirdCell;
aThirdCell=myCell+6.7;
aThirdCell=myCell+4; 

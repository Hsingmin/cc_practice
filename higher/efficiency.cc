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

//�����ô��� 
void processPerson(const Person& p)
{
  //Process the person.
}

Person me("Nicholas","Solter",18);
processPerson(me);

//ȫ��operator+
class SpreadsheetCell
{
  public:
         //The other constructors Omitted for brevity.
         SpreadsheetCell(double inValue);
         
         friend const SpreadsheetCell operator+(const SpreadsheetCell& lhs,const SpreadsheetCell& rhs);
         //Remainder Omitted for brevity.        
} ;

//ʹ��ȫ��operator+�������������͵�ת��
SpreadsheetCell myCell(4),aThirdCell;
aThirdCell=myCell+6.7;
aThirdCell=myCell+4; 


//Muffin.h

class Muffin
{
  public:
    string getDescription() const;
    void setDescription(const string& inDescription);
    int getSize() const;
    void setSize(int inSize);
    bool getHasChocolateChips() const;
    void setHasChocolateChips(bool inChips);
    void output(); //Add a function for use of "printf".

  protected:
    string mDescription;
    int mSize;
    bool mHasChocolateChips;
};

string Muffin::getDescription() const {return mDescription;}
void Muffin::setDescription(const string& inDescription)
{
  mDescription=inDescription;
}

int Muffin::getSize() const {return mSize;}
void Muffin::setSize(int inSize) {mSize=inSize;}
bool Muffin::getHasChocolateChips() const {return mHasChocolateChips;}
void Muffin::setHasChocolateChips(bool inChocolateChips) {mHasChocolateChips=inChocolateChips;}  
void Muffin::output()
{
  printf("%s,Size is %s\n",getDescription().c_str(),getSize(),(getHasChocolateChips()? "Has Chips":"No Chips"))
}

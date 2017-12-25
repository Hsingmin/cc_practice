#include<string>
#include<stdexcept>
#include<vector>
using std::string;

class NameDB
{
  public:
    NameDB(const string& nameFile) throw(std::invalid_argument);
    
    int getNameRank(const string& name) const;
    int getAbsoluteNumber(const string &name) const;  
  //Protected and private members and methods are not shown here.

  protected:
    std::vector<std::pair<string,int> > mNames;
    //Helper methods
    bool nameExists(const string& name) const;
    void incrementNameCount(const string& name);
    void addNewName(const string& name);

  private:
    //Prevent assignment and pass-by-value.
    NameDB(const NameDB& src);
    NameDB& operator=(const NameDB& rhs);
};

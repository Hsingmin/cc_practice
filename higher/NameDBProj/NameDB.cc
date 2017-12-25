
//NameDB.cpp

NameDB::NameDB(const string& nameFile) throw (invalid_argument)
{
  
  //Open the file and check for errors.
  ifstream inFile(nameFile.c_str());
  if(!inFile)
  {
    throw invalid_argument ("Unable to open file\n");
  }

  //Read the names one at a time.
  string name;
  while(inFile>>name)
  {
    if(!nameExistsAndIncrement(name))
    {
      addNewName(name);
    }
  }
  inFile.close();
}

//Returns true if the name exists in the database.
bool NameDB::nameExistsAndIncrement(const string& name)
{
  //Find the name in the map.
  map<string,int>::iterator res=mNames.find(name);
  if(res!=mValues.end())
  {
    res->second++;
    return (true);
  }
  else 
    return (false);
}

//Add a new name to database.
void NameDB::addNewName(const string& name)
{
  mNames.insert(make_pair<string,int>(name,1));
}

//Returns the rank of name.
int NameDB::getNameRank(const string& name) const
{
  int num=getAbsoluteNumber(name);
  //Check if we found the name.
  if(num==-1)
  {
    return(-1);
  }
  int rank=1;
  for(map<string,int>::const_iterator it=mNames.begin();it !=mNames.end();i++)
  {
    if(it->second > num)
    {
      rank++;
    }
  }

  return (rank);
}

//getAbsoluteNumber
//Returns the count associated with this name.
int NameDB::getAbsoluteNumber(const string& name) const
{
  map<string,int>::const_iterator res=mNames.find(name);
  if(res !=mNames.end())
  {
    return (res-> second);
  }
  return (-1);
}

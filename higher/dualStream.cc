void changeNumberForID(const string& inFilename,int ID,const string& inNewNumber)
{
  fstream ioData(inFilename.c_str());
  if(!ioData)
  {
    cerr<<"Error while opening file "<<inFilename<<endl;
    exit(1);
  }

  while(ioData.good())
  {
    int id;
    string number;

    ioData>>id;
    if(id==inID)
    {
      ioData.seekp(ioData.tellg());
      ioData<<" "<<inNewNumber;
      break ;
    }

    ioData>>number;
  }
}

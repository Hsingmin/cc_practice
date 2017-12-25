
//将意外异常转化成意料中的异常 
void  unexpected()
{
  cout<<"Unexpected exception.\n";
  throw runtime_error("");
} 


//标准异常层次体系 
void readIntegerFile(const string& filename,vector<int>& dest)
throw(invalid_argment,runtime_error)
{
  ifstream istr;
  int temp;

  istr.open(filename.cstr());
  if(istr.fail())
  {
    //Failed to open the file: throw an exception.
    string error="Unable to open file"+filename;
    throw invalid_argument(error); 
  }

  //Read the integers one by one and add them to the vector.
  while(istr>>temp)
  {
    dest.push_back(temp);
  }

  if(istr.eof())
  {
    //We reach the end-of-file.
    istr.close();
  }
  else
  {
    string error="Unable to read file "+filename;
    throw runtime_error(error);
  }
}

int main(int argc,char** argv)
{
  //Code omitted for brevity.
  try {
       readIntegerFile(filename,myInts);
  } catch (const invalid_argument& e) {
     cerr<<e.what()<<endl;
     exit(1);
  } catch (const runtime_error& e) {
     cerr<<e.what()<<endl;
     exit(1);
  }
//Code omitted for brevity.
}

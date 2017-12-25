class FileError : public runtime_error
{
  public:
    FileError(const string& fileIn) : runtime_error(""),mFile(fileIn) {}
    virtual ~FileError() throw() {}

    virtual const char* what() const throw() {return mMsg.c_str();}
    string getFilename() {return mFile;}

  protected:
    string mFile,mMsg;
};

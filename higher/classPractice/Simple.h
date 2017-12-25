//Simple.h
#ifndef _simple_h_
#define _simple_h_

class Simple
{
  public:
    Simple(); //Constructor
    virtual ~Simple(); //Destructor
    
    virtual void publicMethod(); //Public method
    int mPublicInteger; //Public data member

  protected:
    int mProtectedInteger; //Protected data member

  private:
    int mPrivateInteger; //Private data member

    static const int mConstant=2; //Private constant
    static int sStaticInt; //Private static data

    //Disallow assignment and pass-by-value
    Simple(const Simple& src);
    Simple& operator=(const Simple& rhs);
};
#endif

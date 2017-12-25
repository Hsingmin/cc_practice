
//条件宏机制 
#ifndef _LOGGER_
#define _LOGGER_

#include"Preference.h"
class Logger
{
  public:
         const void setPreference(const Preference& inPrefer);      
         const void logErr(const char* inErr);
};

#endif //_LOGGER_

//引用类，但不包含其头文件

#ifndef _LOGGER_
#define _LOGGER_

class Preference;

class Logger
{
  public:
         const void setPreference(const Preference& inPrefer);
         const void logErr(const char* inErr);      
} ;

#endif // _LOGGER_


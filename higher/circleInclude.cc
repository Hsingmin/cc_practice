
//��������� 
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

//�����࣬����������ͷ�ļ�

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


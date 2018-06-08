
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class Singleton{
private:
	static Singleton* pInstance; //the only instance to keep Object
	Singleton(); //private constructor
public:
	static Singleton* Instance();
	static void Destroy();
};

#endif

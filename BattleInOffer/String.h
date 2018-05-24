
#ifndef STRING_H_
#define STRING_H_

#include <iostream>
using namespace std;

class String{
	public:
		String(const char * s); //constructor
		String();		//default constructor
		String(const String &s);//copy constructor
		~String();		//destructor
		int GetLength() const {return len};

		//overloaded operator
		String & operator=(const String &);
		String & operator=(const char *);
		char & operator[](int i);
		const char & operator[](int i) const;

		//overloaded operator friends
		friend bool operator<(const String &st1, const String &st2);
		friend bool operator>(const String &st1, const String &st2);
		friend bool operator==(const String &st1, const String &st2);
		friend ostream & operator<<(ostream &os, const String &st);
		friend istream & operator>>(istream &is, String &st);
		
		//static function
		static int HowMany();
	private:
		char * str;
		int len;
		static int num_strings;
		static const int CINLIM = 80;
};

#endif











































#include "String.h"
#include <cstring>

using namespace std;

//Class static member
int String::num_strings = 0;

//Class static methods
int String::HowMany(){
	return num_strings;
}

//Class methods
String::String(const char * s){
	len = strlen(s);
	str = new char[len+1];	//allot storage
	strcpy(str, s);
	num_strings++;
}

String::String(){
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String &st){
	num_strings++;
	len = st.len;
	str = new char[len+1];
	strcpy(str, st.str);
}

String::~String(){
	--num_strings;
	delete [] str;
}

String & String::operator=(const String & st){
	if(this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len+1];
	strcpy(str, st);
	return *this;
}

String & String::operator=(const char * s){
	delete [] str;
	len = strlen(s);
	str = new char[len+1];
	strcpy(str, s);
	return *this;
}
//read-write string 
char & String::operator[](int i){
	return str[i];
}
//read-only string
const char & String::operator[](int i) const{
	return str[i];
}

//overload operator friends 
bool operator<(const String &st1, const String &st2){
	return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2){
	return (strcmp(st2.str, st1.str) < 0);
}

bool operator==(const String &st1, const String &st2){
	return (strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream &os, const String &st){
	os<<st.str;
	return os;
}

istream & operator>>(istream &is, const String &st){
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if(is)
		st = temp;
	while(is && is.get() != '\0')
		continue;
	return is;
}



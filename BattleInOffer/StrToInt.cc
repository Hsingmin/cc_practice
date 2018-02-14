
// StrToInt.cc
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <limits>
using namespace std;

int StrToInt(char* string){
	int number = 0;
	int i;
	int len;
	bool minus = false;

	printf("string : %s\n", string);
	
	len = strlen(string);

	if(NULL == string){
		printf("Argument Error: NULL Pointer . \n");
		return 0;
	}

	if('+' == *string){
		string ++;
	}
	else if('-' == *string){
		string ++;
		minus = true;
	}
	
	while(*string != '\0'){
		if(*string >= '0' && *string <= '9'){
			number = number * 10 + *string - '0';
			
			if(number > numeric_limits<int>::max()){
				printf("Argument Error: Exceeds limits .\n");
				number = 0;
				break;
			}

			string ++;
		}
		else{
		
			printf("Argument Error: Illegal character : %s. \n", *string);
			number = 0;
			return 0;
		}
	}
	
	if(minus){
		number = 0 - number;
	}

	return static_cast<int>(number);
}

int main(int argc, char **argv){

	// char* string = "053184272516";
	// char* string = NULL;
	//char* string = "84272516";
	char* string = "-845781042";

	int number;
	
	number = StrToInt(string);
	printf("%d\n", number);

	return 0;
}













































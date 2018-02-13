
// StrToInt.cc
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int StrToInt(char* string){
	int number = 0;
	int i;
	int len;

	printf("string : %s\n", string);
	
	len = strlen(string);

	if(NULL == string){
		printf("Argument Error: NULL Pointer . \n");
		return 0;
	}
	
	
	if(10 < len){
		printf("Argument Error: String length exceeds . \n");
		return 0;
	}

	while(*string != '\0'){
		if(*string >= '0' && *string <= '9'){
			number = number * 10 + *string - '0';
			string ++;
		}
		else{
		
			printf("Argument Error: Illegal character : %s. \n", *string);
			return 0;
		}
	}

	return number;
}

int main(int argc, char **argv){

	// char* string = "053184272516";
	// char* string = NULL;
	//char* string = "84272516";
	char* string = "845781042";

	int number;
	
	number = StrToInt(string);
	printf("%d\n", number);

	return 0;
}













































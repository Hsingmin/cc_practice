
#include <stdio.h>
#include <stdlib.h>

void foo(const char **fp){
	
	*fp = (char *)malloc(20);
	snprintf(*fp, 20, "hello google!");
}

int main(int argc, char** argv){
	const char *p = "hey";
	
	// const char must be assigned when initialization 
	// *p = "hey";
	printf("Before foo(), *p=%s\n ", p);
	
	// assignment of read-only location '*p'
	// p[0] = 'a';

	foo(&p);
	printf("After foo(), *p=%s\n ", p);

	return 0;
}

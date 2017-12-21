
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
int main(void){
	int *p, **pt;
	int a[4] = {1, 2, 3, 4};

	p = a;
	**pt = a[1];
	printf("(*p) = %d\n", (*p));
	printf("(**pt) = %d\n", (**pt));
}
*/
/*
void fut(int **s, int p[2][3]){
	**s = p[1][1];
}

int main(void){
	int a[2][3] = {1,2,3,4,5,6};
	int *p;
	//int **pt;
	p = (int *)malloc(sizeof(int));
	//**pt = a[1][1];
	fut(&p, a);

	cout<<"(*p) = "<<*p<<endl;
	//cout<<"(**pt) = "<<**pt<<endl;
	free(p);
	
	return 0;
}
*/
/**
void func(char **p){
	int i;
	for(i=0; i<4; i++){
		printf("%s", p[i]);
	}
}

int main(void){
	char *s[6] = {"ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX"};
	func(s);
	printf("\n");
}
*/

void foobar(int a, int *b, int **c){
	int *p = &a;
	*p = 101;
	*c = b;
	b = p;
}

int main(void){
	int a = 1;
	int b = 2;
	int c = 3;
	int *p = &c;
	foobar(a, &b, &p);
	printf("a = %d, b = %d, c = %d, *p = %d\n", a, b, c, *p);
	return 0;
}








































#include<stdio.h>

int main(){
	int a = 1;
	printf("---- int2float ---- \n");
	printf(" (int) &a = %d\n", (int) &a);
	printf(" int a to float a = %d\n", (a == (int) &a));

	int b = 0;
	printf("(int) b = %d\n", (int) a);
	printf(" int b to float b = %d\n", (b == (int) b));
}

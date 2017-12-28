
/* 1220.cc */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define M 5
#define N 20

class A{
	public:
		A(){
			cout<<"class A created."<<endl;
		}
		~A(){
			cout<<"class A deleted."<<endl;
		}
};

class B: public A{
	public:
		B(){
			cout<<"class B created."<<endl;
		}
		~B(){
			cout<<"class B deleted."<<endl;
		}
};

class C: public B{
	public:
		C(){
			cout<<"class C created."<<endl;
		}
		~C(){
			cout<<"class C deleted."<<endl;
		}
};

void prim(int m, int n){
	if(m >= n){
		while(m%n)
			n++;
		m /= n;
		prim(m, n);
		cout<<n<<endl;
	}
}
//string array
int func(char(* ss)[N], int *n){
	int i, k = 0, len = N;
	for(i=0; i<M; i++){
		len = strlen(ss[i]);
		if(len < *n){
			*n = len;
			k = i;
		}
	}
	return k;
}

void GetMemory(char* p){
	p = (char*)malloc(100);
}

int main(int argc, char **argv){
	/*
	B *b = new B();
	C *c = new C();
	A *pab = dynamic_cast<B*>(b);
	A *pac = dynamic_cast<C*>(c);
	B *pbc = dynamic_cast<C*>(c);
	
	//B *pb = dynamic_cast<A*>(a);// downward cast failed
	delete(b);
	delete(c);
	*/
	/*
	char a; // 1byte
	int b; //2byte
	int pm = 12456;
	int pn = 24;
	float c; //4byte
	double d; //8byte

	printf("sizeof(char)=%d\n", sizeof(a));
	printf("sizeof(int)=%d\n", sizeof(b));
	printf("sizeof(float)=%d\n", sizeof(c));
	printf("sizeof(double)=%d\n", sizeof(d));
	
	prim(pm, pn);
	
	char ss[M][N] = {"shanghai", "guangzhou", "beijing", "tianjing", "chongqing"};
	int n, k, i;
	printf("\nThe originalb string are: \n");
	for(i=0; i<M; i++)
		puts(ss[i]); //print to the screen
	k = func(ss, &n);
	printf("\nThe length of shortest string is: %d\n", n);
	printf("\nThe shortes string is : %s\n", ss[k]);
	*/
	/*
	char ccString1[] = "Is Page Fault??";
	char ccString2[] = "No Page Fault??";
	strcpy(ccString1, "No"); //"No\0Page Fault??"
	if(strcmp(ccString1, ccString2)==0) //returns when strcmp counter '\0'
		cout<<ccString2<<endl;
	else
		cout<<ccString1<<endl;
	*/
	/*
	char *str = NULL;
	GetMemory(str);
	str = (char*)malloc(100);
	strcpy(str, "Thunder");
	strcat(str+2, "Downloader"); //append string to source string
	printf(str);
	*/

	FILE *fp; //define a file pointer
	int i, a[6]={1,2,3,4,5,6}, k;
	fp = fopen("data.dat", "w+b"); //open a rw file in binary
	for(i=0; i<6; i++){
		//overwrite
		fseek(fp, 0L, 0); //point to begining of the file
		fwrite(&a[5-i], sizeof(int), 1, fp); //write data array into file reversely
	}
		rewind(fp); //point to head of the file
		fread(&k, sizeof(int), 1, fp); //read an int data into k
		fclose(fp);
		printf("%d\n", k);

	return 0;
}





























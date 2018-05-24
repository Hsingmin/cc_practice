
// tspOptimalPath.cc -- Get the optimal path with Greedy Algorithm.

#include<iostream>

using namespace std;
#define N 5

void tsp(){
	int i, j, k, l;
	int S[N];	// visited customer
	int D[N][N];	// distance between customers
	int sum = 0;	// calculate optimal path of visited customer
	int Dtemp;	// temporary defined distance
	int flag;	// visited flag

	i = 1;		// start node
	S[0] = 0;
	/*
	D[0][1] = 9; D[0][2] = 6; D[0][3] = 5; D[0][4] = 8;
	D[1][0] = 2; D[1][2] = 4; D[1][3] = 4; D[1][4] = 8;
	D[2][0] = 6; D[2][1] = 4; D[2][3] = 2; D[2][4] = 10;
	D[3][0] = 5; D[3][1] = 4; D[3][2] = 2; D[3][4] = 2;
	*/
	D[0][1] = 9; D[0][2] = 9; D[0][3] = 9; D[0][4] = 9;
	D[1][0] = 8; D[1][2] = 8; D[1][3] = 8; D[1][4] = 8;
	D[2][0] = 9; D[2][1] = 9; D[2][3] = 9; D[2][4] = 9;
	D[3][0] = 10; D[3][1] = 10; D[3][2] = 10; D[3][4] = 10;
	while(i < N){
		k = 1;
		Dtemp = 9999;
		while(k < N){
			l = 0;
			flag = 0;
			while(l < i){
				if(S[l] == k){
					flag = 1;
					break;
				}
				else
					l++;
			}
			if(flag==0 && D[k][S[i-1]] < Dtemp){
				j = k; //visited customer
				Dtemp = D[k][S[i-1]];
			}
			k++;
		}
		S[i] = j;	// visited customer stored into S[i]
		i++;
		sum += Dtemp;
	}

	sum += D[0][j];
	for(j=0; j<N; j++){
		cout<<j<<" ";
	}
	cout<<"\n"<<sum<<endl;
}

int main(int args, char **argv){
	tsp();
	
	/*
	int i = 0;
	int j = 0;
	
	do{
		cout<<i<<endl;
		i++;
	}while(i < 10);
	cout<<"===================="<<endl;
	while(j < 10){
		cout<<j<<endl;
		j++;
	}
	*/
}
































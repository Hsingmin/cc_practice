
// LeastCommonAncestor.cc

#include <iostream>
using namespace std;

#define N 10000

int getIndex(int key, int *input, int length, int *res){
	int occur = 0;
	int i = 0;
	while(i<length){
		if(input[i] == key){
			occur++;
			*res = i;
			res++;
		}
		if(occur==3)
			break;
		i++;
	}

	return occur;
}

int pickAsChild(int *res){
	int i = 0;
	while(i<sizeof(res)/sizeof(int)){
		if(res[i]/2)
			break;
		i++;
	}

	return res[i];
}

int getLine(int key, int *input, int *line){
	int occur;
	int index[3];
	int aschild;
	while(key != 1){
		occur = getIndex(key, input, sizeof(input)/sizeof(int), index);
		aschild = pickAsChild(index);
		*line = key;
		line++;
		key = input[aschild-1];
	}
	*line = 1;

	if(sizeof(line)/sizeof(int) == 1)
		return 0;
	return 1;
}

int main(int argc, char **argv){
	int input[] = {1,2,1,3,2,4,3,5,3,6,4,7,7,12,5,9,5,8,6,10,6,11,11,13};
	// cout<<(sizeof(input)/sizeof(int))<<endl;
	
	int key1 = 13;
	int key2 = 8;
	int *line1;
	int *line2;
	int status;

	status = getLine(key1, input, line1);
	status = getLine(key2, input, line2);
	
	/*
	int occur1;
	int key1 = 13;
	int index1[3] = {0};
	int *line1;
	int aschild;
	while(key1 != 1){
		occur1 = getIndex(key1, input, sizeof(input)/sizeof(int), index1);
		aschild = pickAsChild(index1);
		*line1 = key1;
		cout<<(*line1)<<endl;
		line1++;
		key1 = input[aschild-1];
	}
	*line1 = 1;
	
	int occur2;
	int key2 = 13;
	int index2[3] = {0};
	int *line2;
	//int aschild2;
	while(key2 != 1){
		occur2 = getIndex(key2, input, sizeof(input)/sizeof(int), index2);
		aschild = pickAsChild(index2);
		//*line2 = key2;
		cout<<(*line2)<<endl;
		line2++;
		key2 = input[aschild-1];
	}
	*line2 = 1;
	*/

	

	int pivot1 = sizeof(line1)/sizeof(int);
	int pivot2 = sizeof(line2)/sizeof(int);

	while(pivot1 != 0 && pivot2 != 0){
		if(line1[pivot1] != line2[pivot2])
			break;
		pivot1--;
		pivot2--;
	}

	cout<<"Common Ancestor = "<<line1[pivot1+1]<<endl;
		

	// cout<<"key "<<key<<" occur in "<<occur<<" times on index of ";
	// cout<<res[0]<<", "<<res[1]<<", "<<res[2]<<endl;
	// cout<<"As child node on position "<<pickAsChild(res)<<endl;
		
}
















































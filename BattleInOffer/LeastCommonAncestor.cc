
// LeastCommonAncestor.cc

#include <iostream>
using namespace std;

#define N 10000

int getIndex(int &key, const int *input, const int length, int *index){
	int occur = 0;
	int i = 0;
	int j = 0;
	while(i<length){
		if(input[i] == key){
			occur++;
			index[j++] = i;
		}
		if(occur==3)
			break;
		i++;
	}

	return occur;
}

int pickAsChild(const int *index){
	for(int i=0; i<3; ++i){
		if(index[i]%2)
			return index[i];
	}

	return -1;
}

int getLine(int &key, int *input, const int size, int *line){
	int occur;
	// Each element would occur in 3 times at most.
	int index[3] = {0};
	int aschild;
	int l = 0;
	while(key != 1){
		occur = getIndex(key, input, size, index);
		aschild = pickAsChild(index);
		*line = key;
		cout<<"*line = "<<(*line)<<endl;
		l++;
		line++;
		key = input[aschild-1];
	}
	*line = 1;
	l++;
	cout<<"*line = "<<(*line)<<endl;
	return l;
}

int main(int argc, char **argv){
	int input[] = {1,2,1,3,2,4,3,5,3,6,4,7,7,12,5,9,5,8,6,10,6,11,11,13};
	int key1 = 13;
	int key2 = 12;
	int *line1 = new int;
	int *line2 = new int;
	int pivot1;
	int pivot2;
	int size = sizeof(input)/sizeof(int);

	pivot1 = getLine(key1, input, size, line1);
	pivot2 = getLine(key2, input, size, line2);
	
	cout<<"pivot1 = "<<pivot1<<endl;
	cout<<"pivot2 = "<<pivot2<<endl;

	while(pivot1>0 && pivot2>0){
		if(line1[--pivot1] != line2[--pivot2])
			break;
	}
	cout<<"Common Ancestor = "<<line1[pivot1+1]<<endl;
	delete line1;
	delete line2;
		
}

















































// Pointer.cc

# include<iostream>
using namespace std;

int GetSize(const int *data){
	return (sizeof(data)/sizeof(int));
}

int GetLine(int &key, int *input, const int size, int *line){
	
}

int main(int argc, char **argv){
	int night = 1001;
	int *ptr = new int[3];
	ptr[0] = 1001;
	ptr[1] = 1002;
	ptr[2] = 1003;
	
	cout<<"night value = "<<night<<" , at location: "<<&night<<endl;
	cout<<"ptr[0] value = "<<ptr[0]<<" , at location: "<<(&ptr[0])<<endl;
	ptr++;
	cout<<"Now, ptr[0] value = "<<ptr[0]<<" , at location: "<<(&ptr[0])<<endl;

	ptr--;	// point back to beginning
	delete[] ptr;

	int res[10];
	for(int i=0; i<10; ++i){
		res[i] = i;
		cout<<"*res = "<<(res[i])<<" , at location "<<(&res[i])<<endl;
		// res++;
	}
	int *line = NULL;
	int key;
	for(int k=0; k<10; ++k){
		key = res[k];
		line = &key;
		cout<<"line"<<k<<" = "<<(*line)<<endl;
		line++;
	}

	int input[] = {1,2,3,4,5,6,7,8,9};
	cout<<"length of input : "<<(sizeof(input)/sizeof(int))<<endl;
	cout<<"GetSize(input): "<<GetSize(input)<<endl;

	return 0;
}









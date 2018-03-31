
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
int ArrayPartition(int* array, int low, int high){
	if(NULL == array || low > high){
		cout<<"Invalid Parameters . "<<endl;
	}
	int pivot;
	pivot = array[low];
	while(low < high){
		while(low < high && array[high] >= pivot)
			high --;
		array[low] = array[high];

		while(low < high && array[low] <= pivot)
			low ++;
		array[high] = array[low];
	}
	array[low] = pivot;
	return low;
}
*/

void QuickSort(int* array, int start, int end){
	if(NULL == array){
		cout<<"Invalid array transfered in !"<<endl;
		return ;
	}

	int mid;
	int pivot;
	int low;
	int high;

	if(start < end){
		low = start;
		high = end;
		pivot = array[start];
		while(low < high){
			while(low < high && array[high] >= pivot)
				--high;
			array[low] = array[high];
			while(low < high && array[low] <= pivot)
				++low;
			array[high] = array[low];
		}
		array[low] = pivot;
		mid = low;
		QuickSort(array, start, mid-1);
		QuickSort(array, mid+1, end);
	}
}

int main(int args, char** argv){
	int array[] = {3, 5, 9, 2, 1, 3, 9, 13, 1};
	int i;
	int start = 0;
	int end = sizeof(array)/sizeof(int) - 1;
	QuickSort(array, start, end);
	for(i=0; i <= end; i++){
		cout<<array[i]<<" ";		
	}
	cout<<endl;
}



































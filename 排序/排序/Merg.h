#pragma once

#include <malloc.h>
#include <string.h>
#include <stdio.h>

int MergData(int* array, int left, int mid, int right, int* temp){

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = 0;


	while (begin1 <= end1 && begin2 <= end2){
		if (array[begin1] < array[begin2]){
			temp[i] = array[begin1];
			begin1++;
			
		}
		else{
			temp[i] = array[begin2];
			begin2++;

		}

	}


	while (begin1 <= end1){
		temp[i++] = array[begin1];
		begin1++;
	}

	while (begin2 <= end2){
		temp[i++] = array[begin2];
		begin2++;
	}

	
}

void _Mergsort(int* array, int left,int right,int* temp){
	if (right - left > 1){
		int mid = left + ((right - left) >> 1);

		_Mergsort(array, left, mid, temp);
		_Mergsort(array, mid, right, temp);
		MergData(array, left, mid, right, temp);
		memcpy(array + left, temp + left, sizeof(array)/sizeof(array[0]));
	}

}


void Mergsort(int* array, int left ,int right){
	int* temp = (int*)malloc(sizeof(int)*array[0]);

	if (temp == NULL){
		return;
	}

	_Mergsort(array, left,right,temp);

	free(temp);


}

int merge(int* array, int* temp, int left, int mid, int right){

	int begin1 = left;
	int begin2 = mid + 1;
	int pos = left;
	while (begin1 <= mid &&begin2 <= right){

	}

}


void test4(){
	int array[] = { 4, 5, 7, 8, 2, 3, 1, 0, 9, 6 };
	int size = sizeof(array) / sizeof(array[0]);
	int left = 0;
	int right = size - 1;
	Print(array, size);
	// Bubble_sort(array, size);
	Mergsort(array, left, right);
	Print(array, size);
}
#pragma once 
#include <stdio.h>

void PrintArray(int array[], int size){
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);

	}
	printf("\n");
}


void InsertSort(int array[], int size){
	int i = 0;
	
	for (i = 1; i < size; i++){
		int key = array[i];
		int end = i - 1;
		
		while (end >= 0 && key<array[end]){
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
	
}

void TestSort(){
	int array[] = { 2, 3, 5, 7, 1, 6, 0, 8, 9, 4 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArray(array, size);
	InsertSort(array, size);
	PrintArray(array, size);
}


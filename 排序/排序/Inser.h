#pragma once

#include <stdio.h>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
// ²åÈëÅÅĞò
void Inser_sort(int* array, int size){
	// ÕÒ´ı²åÈëÔªËØÎ»ÖÃ

	for (int i = 0; i < size; i++){
		int key = array[i];
		int end = i - 1;
		
		// °áÒÆÔªËØ 
		while (end >= 0 && key < array[end]){
			array[end + 1] = array[end];
			
			end--;
		}

		array[end + 1] = key;

	}
}



// Ï£¶ûÅÅĞò

void Shell_sort(int* array, int size){
	int gap = size;
	while (gap > 1){
		gap = gap / 3 + 1;
		for (int i = gap; i < size; i++){
			int key = array[i];
			int end = i - gap;

			while (end >= 0 && key < array[i]){
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;

		}
		gap--;
	}
}

// Ñ¡ÔñÅÅĞò

void Select_sort(int* array, int size){
	int maxpos = 0;

	for (int i = 0; i<size; i++){

		for (int j = 0; j<size; j++){
			if (array[maxpos]<array[i]){
				swap(&array[maxpos], &array[i]);
			}
		}
	}



}
void Print(int* array, int size){
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);

	}
	printf("\n");

}


void test(){
	int array[] = { 2, 5, 7, 6, 8, 1, 3, 4, 0, 9 };
	int size = sizeof(array) / sizeof(array[0]);
	Print(array, size);
	// Inser_sort(array, size);
	Select_sort(array, size);
	Print(array, size);
}
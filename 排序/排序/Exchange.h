#pragma once



// 冒泡排序：
// 相邻两个元素进行比较后交换

void Bubble_sort(int* array, int size){

	for (int i = 0; i < size; i++){
		int Mark = 0;   

		for (int j = 1; j < size; j++){

			if (array[j - 1]>array[j]){
				swap(&array[j - 1], &array[j]);

				Mark = j + 1;

			}

		}

		// 一趟比较完

		if (Mark == 0){
			break;
		}

		i = size - 1 - Mark;
	}
}

// 冒泡排序算法总结：
// 时间复杂度：O(N^2)
// 空间复杂度：O(1)
// 稳定性：稳定
// 应用场景：有序数列冒泡排序最快

// 快速排序
// 区间分割法
// 取一个基准值
// 将剩余元素与基准值进行比较分组


int Partition(int* array, int left, int right){

	int begin = left;
	int end = right;

	int key = array[right];

	while (begin < end){

		while (begin < end && array[begin] <= key){
			begin++;
		}

		while (begin < end && array[end] >= key){
			end--;
		}

		
		swap(&array[begin], &array[end]);
		
		
	}

	swap(&array[begin], &array[right-1]);
	return begin;

}

// 挖坑法：









void Quick_sort(int* array, int left, int right){

	if (right - left > 1){
		int div = Partition(array, left, right);
		Quick_sort(array, left, div-1);
		Quick_sort(array, div+1, right);
	}
}




void test3(){

	int array[] = { 4, 5, 7, 8, 2, 3, 1, 0, 9, 6 };
	int size = sizeof(array) / sizeof(array[0]);
	int left = 0;
	int right = size - 1;
	Print(array, size);
	// Bubble_sort(array, size);
	Quick_sort(array, left, right);
	Print(array, size);
}
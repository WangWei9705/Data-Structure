#pragma once 





// 选择排序
// 每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完 。
// 直接选择排序：
// 在元素集合array[i]--array[n-1]中选择关键码最大(小)的数据元素
// 若它不是这组元素中的最后一个(第一个)元素，则将它与这组元素中的最后一个（第一个）元素交换
// 在剩余的array[i]--array[n - 2]（array[i + 1]--array[n - 1]）集合中，重复上述步骤，直到集合剩余1个元素

void Select_sort(int* array, int size){
	

	for (int i = 0; i<size; i++){
		int maxpos = i;

		for (int j = i; j < size; j++){
			if (array[maxpos]<array[j]){
				maxpos = j;

			}

			if (maxpos != i){
				swap(&array[maxpos], &array[i]);
			}
		}
	}

}


// 堆排序
// 利用堆得删除操作来实现序列的排序，升序用大堆，降序用小堆
// 1、建堆
//		找最后一个非叶子结点，不断的调整，直到最后一个父节点

//		调整过程： 
//			拿当前父节点与左右孩子比较大小，然后交换

// 2、排序
//   拿堆顶元素与最后一个元素进行交换，交换后最后一个元素不参与调整
//   将对顶元素作为调整起点做向下调整
//   重复以上步骤

// 堆调整，以大堆为例：

void HeapAdjust(int* array, int size, int last){
	
	int parent = size;
	// 默认为左孩子
	int child = parent * 2 + 1;

	while (child <= last){

		// 开始比较
		if (child + 1 < last && array[child] < array[child + 1]){
			child++;
		}

		if (array[parent]>array[child]){
			return;
		}
		else{
			swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}

	}
}


// 堆排序：以升序为例
void Heap_sort(int* array,int size){


	// 建堆
	for (int i = size / 2 - 1; i >= 0; i--){
		HeapAdjust(array, size, i);
	}


	// 排序

	for (int i = size - 1; i >= 0; i--){
		swap(&array[0], &array[i]);
		HeapAdjust(array, i, 0);
	}
}




void test2(){

	int array[] = { 4, 6, 8, 2, 3, 1, 0, 9, 7, 5 };
	int size = sizeof(array) / sizeof(array[0]);

	Print(array, size);
	// Select_sort(array, size);
	Heap_sort(array, size);
	Print(array, size);


}
#pragma once 





// ѡ������
// ÿһ�δӴ����������Ԫ����ѡ����С������󣩵�һ��Ԫ�أ���������е���ʼλ�ã�ֱ��ȫ�������������Ԫ������ ��
// ֱ��ѡ������
// ��Ԫ�ؼ���array[i]--array[n-1]��ѡ��ؼ������(С)������Ԫ��
// ������������Ԫ���е����һ��(��һ��)Ԫ�أ�����������Ԫ���е����һ������һ����Ԫ�ؽ���
// ��ʣ���array[i]--array[n - 2]��array[i + 1]--array[n - 1]�������У��ظ��������裬ֱ������ʣ��1��Ԫ��

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


// ������
// ���öѵ�ɾ��������ʵ�����е����������ô�ѣ�������С��
// 1������
//		�����һ����Ҷ�ӽ�㣬���ϵĵ�����ֱ�����һ�����ڵ�

//		�������̣� 
//			�õ�ǰ���ڵ������Һ��ӱȽϴ�С��Ȼ�󽻻�

// 2������
//   �öѶ�Ԫ�������һ��Ԫ�ؽ��н��������������һ��Ԫ�ز��������
//   ���Զ�Ԫ����Ϊ������������µ���
//   �ظ����ϲ���

// �ѵ������Դ��Ϊ����

void HeapAdjust(int* array, int size, int last){
	
	int parent = size;
	// Ĭ��Ϊ����
	int child = parent * 2 + 1;

	while (child <= last){

		// ��ʼ�Ƚ�
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


// ������������Ϊ��
void Heap_sort(int* array,int size){


	// ����
	for (int i = size / 2 - 1; i >= 0; i--){
		HeapAdjust(array, size, i);
	}


	// ����

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
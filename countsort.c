// 计数排序的实现


void countsort(int* array, int size){


	int minval = array[0];
	int maxval = array[0];
	int i = 0;
	int index = 0;

	// 找区间
	for (i = 0; i < size; i++){
		if (array[i] < minval){
			minval = array[i];
		}

		if (array[i] > maxval){
			maxval = array[i];
		}
	}

	int range = maxval - minval + 1;


	// 给空间

	int* temp = (int*)malloc(sizeof(int)*size);
	if (temp == NULL){
		assert(0);
		return;
	}

	memset(temp, 0, sizeof(int)* range);
	// 统计每个数据出现次数
	for (i = 0; i < size; i++){

		temp[array[i]] = minval++;
	}
	// 回收数据
	for (i = 0; i < range; i++){
		while (temp[i]--){
			array[index++] = i + minval;
		}
	}


	free(temp);
}


void print(int* array, int size){
	for (int i = 0; i < size; i++){
		printf("%d ");
	}
	printf("\n");
}




int main()
{
	int array[10] = { 4, 4, 6, 7, 3, 0, 9, 3, 5, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	print(array, size);
	countsort(array, size);
	print(array, size);

	system("pause");
	return 0;
}



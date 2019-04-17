// 插入排序

void Insert_Sort(int* array,int size){
	// 找待插入元素的位置
	
	for(int i = 0 ;i < size ; i++){
		int key = array[i];
		int end = i - 1;
		
		
		// 搬移元素
		
		while(end >= 0 && key < array[end]){
			array[end+1] = array[end];
			end++;
		}
		
		array[end+1] = key;
	}
 			
}


// 希尔排序

void  Shell_Sort(int* array, int size){
	// 定义一个间隔
	int gap = size;
	while(gap > 1){
		gap=gap / 3 + 1;
		for(int i = 0; i < size; i++){
			int key = array[gap];
			int end = i - gap;
			while(end >= 0 && key < array[i]){
				// 搬移元素
				array[end+gap] = array[end];
				end -= gap;
			}
			
			array[end+gap] = gap;
		}
		gap--;
	}
}
	
	

// 选择排序

void Select_sort(int* array,int size){
	int maxpos=0;
	
	for(int i=0;i<size;i++){
		
		for(int j=i;j<size;j++){
			if(array[maxpos]<array[i]){
				swap(&array[maxpos],&array[i]);
			}
		}
	}
	

	
}
	
	
	
// 归并排序

// 1、每次找中间位置，均分序列
// 2、递归左半边、右半边排序
// 3、归并数据到临时空间
// 4、memcpy拷贝临时空间中的元素到原空间

void MergData(int *array,int left,int mid,int right, int *temp){
	
	
	
	
	
	
	
}
	
	
	
	
void MergSort(int *array,int left,int right,int *temp){
	if(right - left >1){
		int mid = left + ((right - left) >> 1);
		MergSort(array,left,mid,temp);
		MergSort(array,mid,right,temp);
		MergData(array,left,mid,right,temp);
		memcpy(array + left, temp + left,sizeof(array[0])*size);
	}
}
	
void mergsort(int *array,int size){
	int *temp = malloc(sizeof(array[0])*size);	
	if(temp == NULL){
		assert(0);
		return ;
	}
	MergSort(array,left,right,temp);
	free(temp);
}
	
		

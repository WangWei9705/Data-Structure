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
	
	
	
// 堆调整

void HeapAdjust(int* array,int szie,int last){
	
	int parent = size;
	int child = parent*2+1;
	
	while(child<=last){
		
		if(child+1<=last && array[child]<array[child+1]){
			child++;
		}
		
		
		if(array[parent]>array[child]){
			return ;
		}
		
		else{
			
			swap(array[parent],array[child]);
			parent = child;
			child = parent*2+1;
		}
	}
}

















}	
// 堆排序

void Heap_sort(int** array,int size){
	
	// 建堆
	
	// 从最后一个非叶子结点开始
	for(int i=size/2-1;i>=0;i--){
		HeapAdjust(array,szie,i);
	}
	
	
	// 排序
	// 从最后一个结点开始，直到父节点
	for(int i=szie-1;i>=0;i--){
		swap(&array[0],&array[i]);
		HeapAdjust(array,i,0);
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
	
		

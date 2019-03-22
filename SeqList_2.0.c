//静态顺序表

typedef int SLDataType;

// 动态顺序表（在程序运行期间可以动态控制容量的大小
typedef struct SeqList {
	SLDataType *array;		// 指向 堆上空间，存放数据
	int capacity;	// 容量
	int size;		// 有效个数
}	SeqList;

// 服务列表，函数列表

// 创建 | 销毁
void SeqListInit(SeqList *pSeqList){
	// 设置容量和size
	
	pSeqList->capacity capacity =10;
	pSeqList->array=(int *)malloc(sizeof(SLDataType)*pSeqList->capacity);
	pSeqList->szie=0;
}


void SeqListDestroy(SeqList *pSeqList){
	// 释放capacity
	free(pSeqList->capacity);
	pSeqList->array=NULL;
	pSeqList->capacity=0;
	pSeqList->size=0;
}


// 扩容

 static void CheckCapacity(){
	 if(pSeqList->size>=pSeqList->capacity){
		 int newCapacity=pSeqList->capacity;
		 SLDataType *newArray=(SLDataType *)malloc(sizeof(SLDataType)*newCapacity);
		 
		 // 搬家
		 
		 for (int i=0;i<pSeqList->size;i++){
			 newArray[i]=pSeqList->array[i];
		 }
		 
		 // 释放老空间，绑定新空间
		 free(pSeqList->array);
		 pSeqList->array=newArray;
		 pSeqList->capacity=newCapacity;
	 }
		 

 }


// 增 删 查 改
// 尾插
void SeqListPushBack(SeqList *pSeqList, SLDataType value){
	assert(pSeqList!=NULL);
	CheckCapacity();
	pSeqList->array[pSeqList->size]=value;
	
	pSeqList->size++;
}

// 头插
void SeqListPushFront(SeqList *pSeqList, SLDataType value){
	assert(pSeqList!=NULL);
	assert(pSeqList->array!=NULL);
	assert(pSeqList->size>0);
	CheckCapacity();
	
	for(int i=pSeqList->size;i>0;i--){
		pSeqList->array[i]=pSeqList->array[i-1];
	}
	pSeqList->array[0]=value;
	pSeqList->size++;
}
// 根据下标 pos 做插入
void SeqListInsert(SeqList *pSeqList, int pos, SLDataType value){
	
	assert(pSeqList!=NULL);
	CheckCapacity();
	
	for(int i=pSeqList->size-1;i>=pos;i--){
		pSeqList->array[i+1]=pSeqList->array[i];
	}
	pSeqList->array[pos]=value;
	pSeqList->szie++;
	
}

// 尾删
void SeqListPopBack(SeqList *pSeqList){
	assert(pSeqaList!=NULL);
	
	pSeqList->size--;
}

// 头删
void SeqListPopFront(SeqList *pSeqList){
	assert(pSeqaList->size>0);
	
	for(int i=0;i<size-1;i++){
		pSeqList->array[i]=pSeqList->array[i+1];
	}
	pSeqList->size--;
	
	
}

	

// 根据下标 pos 做删除
void SeqListErase(SeqList *pSeqList, int pos){
	
	for(int i=pos+1;i<pSeqList->size;i++){
		pSeqList->array[i-1]=pSeqList->array[i];
	}
	pSeqList->size--;
}

// 查找
int SeqListSearch(const SeqList *pSeqList, SLDataType value){
	
	assert(pSeqList!=NULL);
	for(int i=0;i<pSeqList->size;i++){
		if(pSeqList->array[i]=value){
			return i;
		}
	}
	return -1;
}

// 修改
// 修改 pos 下标所在的值为 value
void SeqListModify(SeqList *pSeqList, int pos, SLDataType value){
	assert(pos>0&&pos<pSeqList->size);
	
	pSeqList->array[pos]=value;
	
	
}

// 删除遇到的第一个 value
void SeqListRemove(SeqList *pSeqList, SLDataType value){
	int pos = SeqListFind(ps, value);
	if (pos != -1) {
		SeqListErase(ps, pos);
	}

}

// 删除遇到的所有 value
void SeqListRemoveAll(SeqList *ps, SLDataType value){
	assert(pSeqList!=NULL);
	
	for(int i=0;i<pSeqList->size;i++){
		if(pSeqList->array[i]=value){
			for(int j=i;j>=pSeqList->size-1;i--){
				pSeqList->array[j]=pSeqList->array[j+1];
			}
			pSeqList->size--;
		}
	}
	pSeqList->size=j;
}
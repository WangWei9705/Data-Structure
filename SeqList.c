// 动态顺序表的实现

typedef int SLDataType;

// 动态顺序表（在程序运行期间可以动态控制容量的大小
typedef struct SeqList {
	SLDataType *array;		// 指向 堆上空间，存放数据
	int capacity;	// 容量
	int size;		// 有效个数
}	SeqList;

// 服务列表，函数列表

// 创建 | 销毁
void SeqListInit(SeqList *pSeqList)
{
	assert(pSeqList!=NULL);
	pSeqList->capacity=20;       // 设置容量
	pSeqList->array=(int *)malloc(sizeof(SLDataType)*SeqList->capacity);
	pSeqList->size=0;
	
}

void SeqListDestroy(SeqList *pSeqList)
{
	assert(pSeqList);
	assert(pSeqList->array);
	free(pSeqList->array);
	
	pSeqList->array=NULL;
	pSeqList->capacity=0;
	pSeqList->size=0;

// 增 删 查 改
// 尾插
void SeqListPushBack(SeqList *pSeqList, SLDataType value)
{
	pSeqList->array[pSeqList->size]=value;
	pSeqList->size++;
}

// 头插
void SeqListPushFront(SeqList *pSeqList, SLDataType value)
{
	assert(pSeqList!=NULL);
	for(int i=pSeqList->size;i>=1;i--)
	{
		pSeqList->array[i]=pSeqList->array[i-1];
	}
	pSeqList->array[0]=value;
	pSeqList->size++;
}


// 根据下标 pos 做插入
void SeqListInsert(SeqList *pSeqList, int pos, SLDataType value)
{
	assert(pSeqList!=NULL);
	for(int i=pSeqList->size;i>pos+1;i--)
	{
		pSeqList->array[i]=pSeqList->array[i-1];
	}
	pSeqList[pos]=value;
	pSeqList->size++;
	
}


// 尾删
void SeqListPopBack(SeqList *pSeqList)
{
	assert(pSeqList->size>0);
	pSeqList->size--;
}

// 头删

void SeqListPopFront(SeqList *pSeqList)
{
	assert(pSeqList->size>0);
	for(int i=0;i<pSeqList->size-1;i++)
	{
		pSeqList->array[i]=pSeqList->array[i+1];
	}
	pSeqList->size--;
}


// 根据下标 pos 做删除
void SeqListErase(SeqList *pSeqList, int pos)
{
	assert(pSeqList->size>0);
	for(int i=pos+1;i<pSeqList->size;i++)
	{
		pSeqList->array[i-1]=pSeqList->array[i];
	}
	pSeqList->size--;
}

// 查找
int SeqListSearch(const SeqList *pSeqList, SLDataType value)
{
	assert(pSeqList!=NULL);
	for(int i=0;i<pSeqList->size;i++)
		
		{
			if(pSeqList->array[i]=value)
				return i;

		}
		return -1;
}


// 修改
// 修改 pos 下标所在的值为 value
void SeqListModify(SeqList *pSeqList, int pos, SLDataType value)
{
	assert(pSeqList->size>pos&&pos>0);
	pSeqList->array[pos]=value;
}

// 删除遇到的第一个 value
void SeqListRemove(SeqList *pSeqList, SLDataType value)
{
	assert(pSeqList!=NULL);
	int pos=SeqListSearch(pSeqList,value);
	if(pos !=-1)
	{
		SeqListErase(pSeqList,pos);
	}
	
}

// 删除遇到的所有 value
void SeqListRemoveAll(SeqList *pSeqList, SLDataType value)
{
	assert(pSeqList!=NULL);
	for(int i=0,int j=0;i<pSeqList->size;i++)
	{
		if(pSeqList->array[i]!=value)
		{
			pSeqList->array[i]=pSeqList->array[j];
		}
		j++;
	}
	pSeqList->size=j;
	
}
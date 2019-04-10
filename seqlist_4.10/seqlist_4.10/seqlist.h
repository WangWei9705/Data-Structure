#pragma once 

#include <assert.h>
#include <malloc.h>
#include <string.h>
typedef int DataType;

typedef struct SeqList
{
	DataType* _array; // 保存顺序表中有效元素个数 
	int _capacity; // 空间总大小 
	int _size; // 有效元素个数 
}SeqList, *PSeqList;


void CheckCapacity(PSeqList ps){
	assert(ps);
	
	if (ps->_capacity == ps->_size){
		int Newcapacity = ps->_capacity * 2;
		DataType* NewArray = (DataType*)malloc(sizeof(DataType)*Newcapacity);
		// 开始搬家
		for (int i = 0; i < ps->_size; i++){
			NewArray[i] = ps->_array[i];

		}

		// 释放老空间，绑定新空间
		free(ps->_array);
		ps->_array = NewArray;
		ps->_capacity = Newcapacity;

	}
	
}
void SeqListInit(PSeqList ps){

	assert(ps);

	ps->_array = (DataType*)malloc(sizeof(DataType));
	ps->_size = 0;
	ps->_capacity = 10;
	
}

void SeqListDestroy(PSeqList ps){
	assert(ps);

	free(ps->_array);
	ps->_array = NULL;
	ps->_size = 0;
	ps->_capacity = 0;
}

// 尾插 
void SeqListPushBack(PSeqList ps, DataType data){
	assert(ps);
	CheckCapacity(ps);

	ps->_array[ps->_size] = data;
	ps->_size++;

}
// 尾删 
void SeqListPopBack(PSeqList ps){
	assert(ps->_size>0);
	ps->_size--;
}

// 头插 (整体后移）
void SeqListPushFront(PSeqList ps, DataType data){
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size; i >= 1; i--){
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[0] = data;
	ps->_size++;

}
// 头删 
void SeqListPopFront(PSeqList ps){
	assert(ps);

	for (int i = 0; i < ps->_size; i++){
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

// 任意位置插入 
void SeqListInsert(PSeqList ps, int pos, DataType data){
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size; i >= pos; i--){
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = data;
	ps->_size++;

}

// 任意位置删除 
void SeqListErase(PSeqList ps, int pos){
	assert(ps);

	for (int i = pos; i < ps->_size; i++){
		ps->_array[i] = ps->_array[i + 1];
	}

	ps->_size--;
}

// 检测data是否在顺序表中 
int SeqListFind(PSeqList ps, DataType data){
	assert(ps);
	for (int i = 0; i < ps->_size; i++){
		if (ps->_array[i] == data){
			return i;
		}
		else
			return 0;

	}
}

// 移除顺序表中第一个值为data的元素 
void SeqListRemove(PSeqList ps, DataType data){
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->_size; i++){
		if (ps->_array[i] == data){
			ps->_array[i] = ps->_array[i + 1];
			break;
	
		}
	}
	ps->_size--;


}

// 移除顺序表中所有值为data的元素 
void SeqListRemoveAll(PSeqList ps, DataType data){
	assert(ps);
	for (int i = 0; i < ps->_size; i++){
		if (ps->_array[i] == data){
			ps->_array[i] = ps->_array[i + 1];
			ps->_size--;
		}
	}
}

// 获取顺序表有效元素个数 
int SeqListSize(PSeqList ps){
	assert(ps);

	for (int i = 0; i < ps->_size; i++){
		return i;

	}
}

// 获取顺序表的容量 
int SeqListCapacity(PSeqList ps){
	assert(ps);

	return ps->_capacity;
}

// 检测顺序表是否为空 
int SeqListEmpty(PSeqList ps){
	if (ps->_size == 0){
		return 0;
	}
	else
		return 1;
}

// 获取顺序表中第一个元素 
DataType SeqListFront(PSeqList ps){
	assert(ps);
	return ps->_array[0];
}

// 获取顺序表中最后一个元素 
DataType SeqListBack(PSeqList ps){
	assert(ps);
	return ps->_array[ps->_size - 1];
}
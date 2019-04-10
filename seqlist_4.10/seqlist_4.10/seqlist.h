#pragma once 

#include <assert.h>
#include <malloc.h>
#include <string.h>
typedef int DataType;

typedef struct SeqList
{
	DataType* _array; // ����˳�������ЧԪ�ظ��� 
	int _capacity; // �ռ��ܴ�С 
	int _size; // ��ЧԪ�ظ��� 
}SeqList, *PSeqList;


void CheckCapacity(PSeqList ps){
	assert(ps);
	
	if (ps->_capacity == ps->_size){
		int Newcapacity = ps->_capacity * 2;
		DataType* NewArray = (DataType*)malloc(sizeof(DataType)*Newcapacity);
		// ��ʼ���
		for (int i = 0; i < ps->_size; i++){
			NewArray[i] = ps->_array[i];

		}

		// �ͷ��Ͽռ䣬���¿ռ�
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

// β�� 
void SeqListPushBack(PSeqList ps, DataType data){
	assert(ps);
	CheckCapacity(ps);

	ps->_array[ps->_size] = data;
	ps->_size++;

}
// βɾ 
void SeqListPopBack(PSeqList ps){
	assert(ps->_size>0);
	ps->_size--;
}

// ͷ�� (������ƣ�
void SeqListPushFront(PSeqList ps, DataType data){
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size; i >= 1; i--){
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[0] = data;
	ps->_size++;

}
// ͷɾ 
void SeqListPopFront(PSeqList ps){
	assert(ps);

	for (int i = 0; i < ps->_size; i++){
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

// ����λ�ò��� 
void SeqListInsert(PSeqList ps, int pos, DataType data){
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size; i >= pos; i--){
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = data;
	ps->_size++;

}

// ����λ��ɾ�� 
void SeqListErase(PSeqList ps, int pos){
	assert(ps);

	for (int i = pos; i < ps->_size; i++){
		ps->_array[i] = ps->_array[i + 1];
	}

	ps->_size--;
}

// ���data�Ƿ���˳����� 
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

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
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

// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data){
	assert(ps);
	for (int i = 0; i < ps->_size; i++){
		if (ps->_array[i] == data){
			ps->_array[i] = ps->_array[i + 1];
			ps->_size--;
		}
	}
}

// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(PSeqList ps){
	assert(ps);

	for (int i = 0; i < ps->_size; i++){
		return i;

	}
}

// ��ȡ˳�������� 
int SeqListCapacity(PSeqList ps){
	assert(ps);

	return ps->_capacity;
}

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList ps){
	if (ps->_size == 0){
		return 0;
	}
	else
		return 1;
}

// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList ps){
	assert(ps);
	return ps->_array[0];
}

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList ps){
	assert(ps);
	return ps->_array[ps->_size - 1];
}
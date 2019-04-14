#pragma once 
#include <malloc.h>
#include <string.h>

// ջ��һ���Ƚ���������ݽṹ

// ʹ��˳���ʵ��ջ

typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _size;
	int _capacity;
	int _top; // ���ջ��λ�� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps){
	ps->_array = NULL;
	ps->_capacity = 10;
	ps->_size = 0;

}

void Checkcapacity(Stack* ps){
	
	int  Newcapacity = ps->_capacity * 2;

	if (ps->_size >= ps->_capacity){
		// ����ռ�
		SDataType* Newarray = (SDataType*)malloc(sizeof(SDataType)*Newcapacity);

		// ���

		int i = 0;
		for (i = 0; i < ps->_size; i++){
			Newarray[i] = ps->_array[i];
		}

		// �ͷ��Ͽռ䣬���¿ռ�
		free(ps->_array);
		ps->_array = Newarray;
		ps->_capacity = Newcapacity;
		

	}
}
// ��ջ 
void StackPush(Stack* ps, SDataType data){
	Checkcapacity(ps);
	ps->_array[ps->_size] = data;

}

// ��ջ 
void StackPop(Stack* ps){
	ps->_size--;

}

// ��ȡջ��Ԫ�� 
SDataType StackTop(Stack* ps){
	return ps->_array[0];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps){
	return ps->_size;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps){
	if (ps->_size == 0){
		return 1;
	}
	return 0;
}

// ����ջ 
void StackDestroy(Stack* ps){
	free(ps->_array);
	ps->_array = NULL;
	ps->_size = 0;
	ps->_capacity = 0;

}



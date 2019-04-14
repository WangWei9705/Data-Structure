#pragma once 
#include <malloc.h>
#include <string.h>

// 栈：一种先进后出的数据结构

// 使用顺序表实现栈

typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _size;
	int _capacity;
	int _top; // 标记栈顶位置 
}Stack;

// 初始化栈 
void StackInit(Stack* ps){
	ps->_array = NULL;
	ps->_capacity = 10;
	ps->_size = 0;

}

void Checkcapacity(Stack* ps){
	
	int  Newcapacity = ps->_capacity * 2;

	if (ps->_size >= ps->_capacity){
		// 申请空间
		SDataType* Newarray = (SDataType*)malloc(sizeof(SDataType)*Newcapacity);

		// 搬家

		int i = 0;
		for (i = 0; i < ps->_size; i++){
			Newarray[i] = ps->_array[i];
		}

		// 释放老空间，绑定新空间
		free(ps->_array);
		ps->_array = Newarray;
		ps->_capacity = Newcapacity;
		

	}
}
// 入栈 
void StackPush(Stack* ps, SDataType data){
	Checkcapacity(ps);
	ps->_array[ps->_size] = data;

}

// 出栈 
void StackPop(Stack* ps){
	ps->_size--;

}

// 获取栈顶元素 
SDataType StackTop(Stack* ps){
	return ps->_array[0];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps){
	return ps->_size;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps){
	if (ps->_size == 0){
		return 1;
	}
	return 0;
}

// 销毁栈 
void StackDestroy(Stack* ps){
	free(ps->_array);
	ps->_array = NULL;
	ps->_size = 0;
	ps->_capacity = 0;

}



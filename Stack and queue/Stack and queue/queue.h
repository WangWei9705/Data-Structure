#pragma once
#include <malloc.h>
#include <string.h>

// 队列：一种先进先出的数据结构
// 由于队列只允许从一端进行操作，所以更适合用链表实现

typedef int  QDataType;

// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;   // 队首
	QNode* _rear;    // 队尾
}Queue;

// 初始化队列 
void QueueInit(Queue* q){
	q->_front = q->_rear = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data){
	QListNode* node = (QListNode*)malloc(sizeof(QListNode));
	node->_data = data;
	node->_pNext = NULL;

	// 如果队首为空就直接入队
	if (q->_front == NULL){    
		q->_front = node;
		q->_rear = node;
	
	}

	// 如果队首不为空，就让队尾和队尾->next=node
	else{
		q->_rear->_pNext = node;
		q->_rear = node;
	}


}

// 队头出队列 
void QueuePop(Queue* q){
	QListNode* node = q->_front->_pNext;    // 存储队首的下一个结点
	free(q->_front);   // 释放队首
	q->_front = node;
	if (q->_front == NULL){
		q->_rear = NULL;

	}
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q){

	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q){
	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q){
	int size = 0;
	QListNode* cur = q->_front;
	while (cur!=NULL)
	{
		cur = cur->_pNext;
		size++;
	}
	return size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q){

	if (q->_front == NULL){
		return 1;
	}
	return 0;
}

// 销毁队列 
void QueueDestroy(Queue* q){
	// 删除所有结点
	QListNode* cur = q->_front;

	while (cur != NULL){
		cur = cur->_pNext;
		free(cur);

	}
}
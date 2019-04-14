#pragma once
#include <malloc.h>
#include <string.h>

// ���У�һ���Ƚ��ȳ������ݽṹ
// ���ڶ���ֻ�����һ�˽��в��������Ը��ʺ�������ʵ��

typedef int  QDataType;

// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;   // ����
	QNode* _rear;    // ��β
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q){
	q->_front = q->_rear = NULL;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data){
	QListNode* node = (QListNode*)malloc(sizeof(QListNode));
	node->_data = data;
	node->_pNext = NULL;

	// �������Ϊ�վ�ֱ�����
	if (q->_front == NULL){    
		q->_front = node;
		q->_rear = node;
	
	}

	// ������ײ�Ϊ�գ����ö�β�Ͷ�β->next=node
	else{
		q->_rear->_pNext = node;
		q->_rear = node;
	}


}

// ��ͷ������ 
void QueuePop(Queue* q){
	QListNode* node = q->_front->_pNext;    // �洢���׵���һ�����
	free(q->_front);   // �ͷŶ���
	q->_front = node;
	if (q->_front == NULL){
		q->_rear = NULL;

	}
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q){

	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q){
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q){

	if (q->_front == NULL){
		return 1;
	}
	return 0;
}

// ���ٶ��� 
void QueueDestroy(Queue* q){
	// ɾ�����н��
	QListNode* cur = q->_front;

	while (cur != NULL){
		cur = cur->_pNext;
		free(cur);

	}
}
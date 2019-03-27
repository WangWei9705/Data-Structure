#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int SListDataType;

// 定义的不是链表的结构体，而是链表中一个结点的结构体
typedef struct ListNode {
	SListDataType	value;	// 保存的值
	struct ListNode *next;	// 保存下一个结点的地址
}	Node;



// 定义链表的头指针
typedef struct SList {
	Node *first;	// Node *head;
}	SList;

// 初始化
void SListInit(SList * s) {
	assert(s != NULL);
	s->first = NULL;
}

// 插入
// 头插
// O(1)
void SListPushFront(SList *s, SListDataType v) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = s->first;
	s->first = node;
}

// 尾插
void SListPushBack(SList *s, SListDataType v) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;

	if (s->first == NULL) {
		// 链表中为空的情况
		s->first = node;
		return;
	}
	// 链表中至少有一个结点的情况

	// 如何找到最后一个结点，隐含着链表中一定有结点
	Node *cur = s->first;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	// cur->next 一定是  NULL，也就是最后一个结点
	cur->next = node;
}

// O(n)
void SListPushBack2(SList *s, SListDataType v) {
	Node * node = (Node *)malloc(sizeof(Node)); 
	node->value = v;
	node->next = NULL;

	// 链表中一个结点都没有
	// 第一个结点的地址就是 NULL
	// s->first
	if (s->first == NULL) {
		s->first = node;
	}
	else {
		Node *cur = s->first;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = node;
	}
}

// 头删
// O(1)
void SListPopFront(SList *s) {
	assert(s != NULL);			// 不能没有链表
	assert(s->first != NULL);	// 不能没有结点

	Node *next = s->first->next;
	free(s->first);
	s->first = next;
}

// 尾删
// O(n)
void SListPopBack(SList *s) {
	assert(s != NULL);			// 不能没有链表
	assert(s->first != NULL);	// 不能没有结点

	if (s->first->next == NULL) {
		// 链表中只有一个结点
		free(s->first);
		s->first = NULL;
		return;
	}

	Node *cur;
	for (cur = s->first; cur->next->next != NULL; cur = cur->next) {
	}

	// cur 就是倒数第二个结点
	// cur->next->next = NULL;
	free(cur->next);
	cur->next = NULL;
}

void SListPopBack2(SList *s) {
	if (s->first->next == NULL) {
		free(s->first);
		s->first = NULL;
	}
	else {
		Node *cur = s->first;
		while (cur->next->next != NULL) {
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *newHead = NULL;

	struct ListNode *cur = head;
	while (cur != NULL) {
		struct ListNode *node = cur;
		cur = cur->next;

		// 把 node 插入到新链表 newHead
		node->next = newHead;
		newHead = node;
	}

	return newHead;
}

void PushBack2(SList *s, SListDataType v) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	if (s->first == NULL) {
		s->first = node;
	}
	else {
		// 找最后一个结点
		Node *p;
		p = s->first;
		while (p->next != NULL) {
			p = p->next;
		}
		// p 是最后一个结点
		p->next = node;
	}
}

void PopBack2(SList *s) {
	// 没有结点，直接 assert
	// 只有一个结点
	// 多于一个结点的情况
	if (s->first->next == NULL) {
		free(s->first);
		s->first = NULL;
	}
	else {
		// 删最后一个结点，找倒数第二个结点
		Node *p = s->first;
		while (p->next->next != NULL) {
			p = p->next;
		}

		free(p->next);
		p->next = NULL;
	}
}

/*
1. 操作的是 cur 结点，实际要更改的地方一般是 cur 的前驱（前一个）结点
2. 往往第一个结点是特殊情况

一种方法：
	1 -> 2 -> 3 -> NULL
	() -> 1 -> 2 -> 3 -> NULL

	Node *fake_node = malloc(sizeof(Node));
	fake_node->next = first;

	// 进行需要的操作，所有真实结点都有前驱结点

	free(fake_node);
*/


Node * SListFind(SList *s, SListDataType v) {
	for (Node *cur = s->first; cur != NULL; cur = cur->next) {
		if (cur->value == v) {
			return cur;
		}
	}

	return NULL;
}

// pos 一定是链表中的结点
void SListInsertAfter(SList *s, Node *pos, SListDataType v) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

// pos 一定是链表中的结点，并且 pos 不是链表的最后一个结点
void SListEraseAfter(SList *s, Node *pos) {
	Node *next = pos->next;
	pos->next = pos->next->next;
	free(next);
}

void SListDestroy(SList *s) {
	Node *next;
	for (Node *cur = s->first; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}

	s->first = NULL;
}

void SListRemove(SList *s, SListDataType v) {
	if (s->first == NULL) {
		// 链表为空
		return;
	}

	if (s->first->value == v) {
		// v 就是第一个结点的情况
		Node *next = s->first->next;
		free(s->first);
		s->first = next;
		return;
	}

	Node *cur = s->first;
	while (cur->next != NULL) {
		if (cur->next->value == v) {
			Node *next = cur->next->next;
			free(cur->next);
			cur->next = next;
			return;
		}

		cur = cur->next;
	}
}

#if 0
void SListRemove2(SList *s, SListDataType v) {
	if (s->first == NULL) {
		// 链表为空
		return;
	}

	Node *fake = (Node *)malloc(sizeof(Node));
	fake->next = s->first;

	Node *cur = fake;
	while (cur->next != NULL) {
		if () {
			...
		}

		cur = cur->next;
	}

	free(fake);
}
#endif

void Test() {
	SList list;
	SListInit(&list);

	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	// 1 2 3
	SListPushFront(&list, 30);
	SListPushFront(&list, 20);
	SListPushFront(&list, 10);
	// 10 20 30 1 2 3
	Node *pos = SListFind(&list, 30);
	SListInsertAfter(&list, pos, 100);
	// 10 20 30 100 1 2 3
	SListEraseAfter(&list, pos);
	// 10 20 30 1 2 3
	SListPopFront(&list);
	// 20 30 1 2 3
	SListPopBack(&list);
	// 20 30 1 2
	SListRemove(&list, 2);

	SListDestroy(&list);
}

// 删除链表中等于给定值 val 的所有节点。
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL) {
		return NULL;
	}

	// 先不管第一个结点的情况
	struct ListNode *cur = head;
	while (cur->next != NULL) {
		if (cur->next->value == val) {
			struct ListNode *next = cur->next->next;
			free(cur->next);
			cur->next = next;
		}
		else {
			cur = cur->next;
		}
	}

	if (head->value == val) {
		Node *newHead = head->next;
		free(head);
		return newHead;
	}
	else {
		return head;
	}
}

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode *front = pListHead;
		ListNode *back = pListHead;
		unsigned int i;
		for (i = 0; front != NULL && i < k; i++) {
			front = front->next;
		}

		if (i < k) {
			return NULL;
		}

		while (front) {
			front = front->next;
			back = back->next;
		}

		return back;
	}
};

struct ListNode *Merge(struct ListNode *l1, struct ListNode *l2) {
	if (l1 == NULL) {
		return l2;
	}

	if (l2 == NULL) {
		return l1;
	}

	struct ListNode *c1 = l1;
	struct ListNode *c2 = l2;
	struct ListNode *result = NULL;	// 结果链表的第一个结点地址
	struct ListNode *tail = NULL;	// 结果链表的最后一个结点地址
	while (c1 != NULL && c2 != NULL) {
		if (c1->val <= c2->val) {
			// 取 l1 链表的结点
			if (tail == NULL) {
				result = tail = c1;
			}
			else {
				tail->next = c1;
				tail = c1;
			}

			c1 = c1->next;
		}
		else {
			// 取 l2 链表的结点
			if (tail == NULL) {
				result = tail = c2;
			}
			else {
				tail->next = c2;
				tail = c2;
			}

			c2 = c2->next;
		}
	}

	// l1 或者 l2 有一条链表的所有结点被去完了
	if (c1 != NULL) {
		tail->next = c1;	// c1 代表的不是一个结点，代表的是链表从 c1 的后序所有结点
	}
	else {
		tail->next = c2;
	}

	return result;
}





// 反转单链表
Node * Reverse(Node *head) {
	Node *prev = NULL;
	Node *cur = head;

	while (cur != NULL) {
		Node *next = cur->next;

		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}


ListNode* partition(ListNode* pHead, int x) {
	ListNode *small = NULL;	// <
	ListNode *small_last = NULL;	// 比 x 小的最后一个结点
	ListNode *big = NULL;	// >=
	ListNode *big_last = NULL;	// 比 x 大于等于的最后一个结点

	for (ListNode *c = pHead; c != NULL; c = c->next) {
		if (c->val < x) {
			if (small_last == NULL) {
				small = small_last = c;
			}
			else {
				small_last->next = c;
				small_last = c;
			}
		}
		else {
			if (big_last == NULL) {
				big = big_last = c;
			}
			else {
				big_last->next = c;
				big_last = c;
			}
		}
	}

	if (small_last != NULL) {
		small_last->next = big;
	}

	if (big_last != NULL) {
		big_last->next = NULL;
	}

	if (small != NULL) {
		return small;
	}
	else {
		return big;
	}
}



ListNode* partition(ListNode* pHead, int x) {
	ListNode *small = NULL;	// <
	ListNode *big = NULL;	// >=
	ListNode *next;
	for (ListNode *c = pHead; c != NULL; c = next) {
		next = c->next;
		if (c->val < x) {
			c->next = small;
			small = c;
		}
		else {
			c->next = big;
			big = c;
		}
	}

	small = Reverse(small);
	big = Reverse(big);

	// ...
}

// 删除重复结点
ListNode* deleteDuplication(ListNode* pHead) {
	if (pHead == NULL) {
		return NULL;
	}

	ListNode *fake = (ListNode *)malloc(sizeof(ListNode));
	fake->next = pHead;

	ListNode *prev = fake;	// 永远是 p1 的前驱
	ListNode *p1 = pHead;	// p1 和 p2 负责进行 val 的比较
	ListNode *p2 = pHead->next;	// p2 还有个职责，找第一个不相等的结点

	while (p2 != NULL) {
		if (p1->val != p2->val) {
			prev = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else {
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}

			// 删除的就是 [p1, p2)
			// 笔试题里先不考虑内存泄漏
			prev->next = p2;

			p1 = p2;
			if (p2 != NULL) {
				p2 = p2->next;
			}
		}
	}

	pHead = fake->next;
	free(fake);

	return pHead;
}


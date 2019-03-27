#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int SListDataType;

// ����Ĳ�������Ľṹ�壬����������һ�����Ľṹ��
typedef struct ListNode {
	SListDataType	value;	// �����ֵ
	struct ListNode *next;	// ������һ�����ĵ�ַ
}	Node;



// ���������ͷָ��
typedef struct SList {
	Node *first;	// Node *head;
}	SList;

// ��ʼ��
void SListInit(SList * s) {
	assert(s != NULL);
	s->first = NULL;
}

// ����
// ͷ��
// O(1)
void SListPushFront(SList *s, SListDataType v) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = s->first;
	s->first = node;
}

// β��
void SListPushBack(SList *s, SListDataType v) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;

	if (s->first == NULL) {
		// ������Ϊ�յ����
		s->first = node;
		return;
	}
	// ������������һ���������

	// ����ҵ����һ����㣬������������һ���н��
	Node *cur = s->first;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	// cur->next һ����  NULL��Ҳ�������һ�����
	cur->next = node;
}

// O(n)
void SListPushBack2(SList *s, SListDataType v) {
	Node * node = (Node *)malloc(sizeof(Node)); 
	node->value = v;
	node->next = NULL;

	// ������һ����㶼û��
	// ��һ�����ĵ�ַ���� NULL
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

// ͷɾ
// O(1)
void SListPopFront(SList *s) {
	assert(s != NULL);			// ����û������
	assert(s->first != NULL);	// ����û�н��

	Node *next = s->first->next;
	free(s->first);
	s->first = next;
}

// βɾ
// O(n)
void SListPopBack(SList *s) {
	assert(s != NULL);			// ����û������
	assert(s->first != NULL);	// ����û�н��

	if (s->first->next == NULL) {
		// ������ֻ��һ�����
		free(s->first);
		s->first = NULL;
		return;
	}

	Node *cur;
	for (cur = s->first; cur->next->next != NULL; cur = cur->next) {
	}

	// cur ���ǵ����ڶ������
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

		// �� node ���뵽������ newHead
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
		// �����һ�����
		Node *p;
		p = s->first;
		while (p->next != NULL) {
			p = p->next;
		}
		// p �����һ�����
		p->next = node;
	}
}

void PopBack2(SList *s) {
	// û�н�㣬ֱ�� assert
	// ֻ��һ�����
	// ����һ���������
	if (s->first->next == NULL) {
		free(s->first);
		s->first = NULL;
	}
	else {
		// ɾ���һ����㣬�ҵ����ڶ������
		Node *p = s->first;
		while (p->next->next != NULL) {
			p = p->next;
		}

		free(p->next);
		p->next = NULL;
	}
}

/*
1. �������� cur ��㣬ʵ��Ҫ���ĵĵط�һ���� cur ��ǰ����ǰһ�������
2. ������һ��������������

һ�ַ�����
	1 -> 2 -> 3 -> NULL
	() -> 1 -> 2 -> 3 -> NULL

	Node *fake_node = malloc(sizeof(Node));
	fake_node->next = first;

	// ������Ҫ�Ĳ�����������ʵ��㶼��ǰ�����

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

// pos һ���������еĽ��
void SListInsertAfter(SList *s, Node *pos, SListDataType v) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

// pos һ���������еĽ�㣬���� pos ������������һ�����
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
		// ����Ϊ��
		return;
	}

	if (s->first->value == v) {
		// v ���ǵ�һ���������
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
		// ����Ϊ��
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

// ɾ�������е��ڸ���ֵ val �����нڵ㡣
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL) {
		return NULL;
	}

	// �Ȳ��ܵ�һ���������
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
	struct ListNode *result = NULL;	// �������ĵ�һ������ַ
	struct ListNode *tail = NULL;	// �����������һ������ַ
	while (c1 != NULL && c2 != NULL) {
		if (c1->val <= c2->val) {
			// ȡ l1 ����Ľ��
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
			// ȡ l2 ����Ľ��
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

	// l1 ���� l2 ��һ����������н�㱻ȥ����
	if (c1 != NULL) {
		tail->next = c1;	// c1 ����Ĳ���һ����㣬������������ c1 �ĺ������н��
	}
	else {
		tail->next = c2;
	}

	return result;
}





// ��ת������
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
	ListNode *small_last = NULL;	// �� x С�����һ�����
	ListNode *big = NULL;	// >=
	ListNode *big_last = NULL;	// �� x ���ڵ��ڵ����һ�����

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

// ɾ���ظ����
ListNode* deleteDuplication(ListNode* pHead) {
	if (pHead == NULL) {
		return NULL;
	}

	ListNode *fake = (ListNode *)malloc(sizeof(ListNode));
	fake->next = pHead;

	ListNode *prev = fake;	// ��Զ�� p1 ��ǰ��
	ListNode *p1 = pHead;	// p1 �� p2 ������� val �ıȽ�
	ListNode *p2 = pHead->next;	// p2 ���и�ְ���ҵ�һ������ȵĽ��

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

			// ɾ���ľ��� [p1, p2)
			// ���������Ȳ������ڴ�й©
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


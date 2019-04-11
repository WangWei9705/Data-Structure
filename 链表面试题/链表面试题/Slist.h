#pragma once

#include <malloc.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode *next;
	
};
//	����������
//	1. ɾ�������е��ڸ���ֵ val �����нڵ㡣 
struct ListNode* removeElements(struct ListNode* head, int val) {

	// �������Ϊ�գ����ؿ�
	if (head == NULL){
		return NULL;
	}

	// �Ȳ����ǵ�һ����㣬�൱��βɾ

	struct ListNode* cur = head;
	while (cur->next != NULL){
		if (cur->next->val == val){
			struct ListNode* next = cur->next->next;
			free(cur->next);
			cur->next = next;
		}
		else{
			cur = cur->next;
		}
	}

	// �����һ�����ֵΪval���൱��ͷɾ

	if (head->val == val){
		struct ListNode* newHead = head->next;
		free(head);
		return newHead;

	}
	else
		return head;

}
//	2. ��תһ�������� 
// �Ⱥ�ָ�룬������ָ�뷨
struct ListNode* reverseList(struct ListNode* head) {
	struct  ListNode *prev = NULL;
	struct ListNode *cur = head;

	while (cur != NULL) {
		struct ListNode *next = cur->next;

		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;

}
//	3. ����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м���
//	����ָ�룬��ÿ��������
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast != NULL&&fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;

	}
	return slow;

}
//	4. ����һ����������������е�����k����㡣 
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* front = pListHead;
		ListNode* back = pListHead;
		unsigned int i;
		for (i = 0; front != NULL&&i<k; i++){
			front = front->next;
		}
		if (i<k){
			return NULL;
		}
		while (front != NULL){
			front = front->next;
			back = back->next;
		}
		return back;

	}
};
//	5. ��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		// �������l1��l2Ϊ��
		if (l1 == NULL){
			return l2;
		}
		if (l2 == NULL){
			return l1;
		}
		ListNode* newHead = NULL; // ��������׽��
		ListNode* newTail = NULL; // �������β���

		// ����l1��l2����Ϊ�գ��ֱ�ȡ��������Ľ��ƴ����һ������µ�����

		while (l1 != NULL&&l2 != NULL){

			// ȡ��һ������Ľ��
			if (l1->val <= l2->val){
				if (newTail != NULL){
					newTail->next = l1;
					newTail = l1;
				}
				else{
					newHead = newTail = l1;
				}
				l1 = l1->next;
			}
			// ȡ�ڶ�������Ľ��
			else{
				if (newTail != NULL){
					newTail->next = l2;
					newTail = l2;
				}
				else{
					newHead = newTail = l2;
				}
				l2 = l2->next;
			}

			// ���һ������ȡ����
			if (l1 != NULL){
				newTail->next = l1;
			}
			else{
				newTail->next = l2;
			}
		}
		return newHead;

	}
};
//	6. ��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ .
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode* small = NULL;
		ListNode* small_last = NULL;
		ListNode* big = NULL;
		ListNode* big_last = NULL;

		ListNode* cur;
		for (cur = pHead; cur != NULL; cur = cur->next){

			// �и�����
			if (cur->val<x){
				if (small_last == NULL){
					small = small_last = cur;
				}
				else{
					small_last->next = cur;
					small_last = cur;
				}
			}

			else{
				if (big_last == NULL){
					big = big_last = cur;
				}
				else{
					big_last->next = cur;
					big_last = cur;
				}
			}
		}

		// ƴ������

		if (small_last != NULL){
			small_last->next = big;
		}
		if (big_last != NULL){
			big_last->next = NULL;
		}
		if (small != NULL){
			return small;
		}
		else{
			return big;
		}
	}
};
//	7. ��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		// ����Ϊ��
		if (pHead == NULL)
		{
			return NULL;
		}
		ListNode* fask = (ListNode*)malloc(sizeof(ListNode));
		fask->next = pHead;
		ListNode* prev = fask;
		ListNode* p1 = pHead;
		ListNode* p2 = pHead->next;
		while (p2 != NULL)
		{
			if (p1->val != p2->val)
			{
				prev = p1;
				p1 = p2;
				p2 = p2->next;

			}
			else
			{
				while (p2 != NULL&&p2->val == p1->val)
				{
					p2 = p2->next;
				}
				// ��ʼɾ���ظ����
				prev->next = p2;
				p1 = p2;
				if (p2 != NULL)
				{
					p2 = p2->next;
				}

			}
		}
		pHead = fask->next;
		free(fask);   // ɾ���ٽ��

		return pHead;

	}
};
//	8. ����Ļ��Ľṹ��
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		// 0���������Ϊ�շ���false���������Ϊ�������򷵻�true

		if (A == NULL){
			return false;
		}
		else if (A->next == NULL){
			return true;
		}

		// 1���ҵ�������м���
		ListNode* fast = A;
		ListNode* slow = A;

		while (fast != NULL&&fast->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
		}

		// 2�����ú�벿��
		ListNode* p1 = slow;
		ListNode* p2 = p1->next;

		while (p1 != NULL){
			p1->next = slow;
			slow = p1;
			p1 = p2;
			p2 = p2->next;
		}

		// 3����ͷ��βָ�����м�������ж�A�Ƿ��ǻ��� 

		while (A != slow){
			if ((A->val) != (slow->val)){
				return false;
			}
			else{
				if (A->next == slow){
					return true;
				}
				A = A->next;
				slow = slow->next;
			}
		}

		return true;
	}
};
//	9. �������������ҳ����ǵĵ�һ��������㡣
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL){
		return NULL;
	}
	struct ListNode* p = headA;
	struct ListNode* q = headB;

	// ��������ָ��ͬʱ���������pΪNULL��p=headB,������p=p->next;
	// ���q==NULL,q=headA,����q=q->next;
	// ���p=qʱ����p,��Ϊ����
	while (p != q) {
		p = !p ? headB : p->next;   
		q = !q ? headA : q->next;
	}
	return p;
}
//	10. ����һ�������ж��������Ƿ��л��� 
// ����ָ�룬�������һ�����������ָ���������л�����֮�޻�
bool hasCycle(struct ListNode *head) {
	if (head == NULL){
		return false;
	}
	struct ListNode* fast = head->next;
	struct ListNode* slow = head;

	while (fast != NULL){
		if (fast == slow){
			return true;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;
	}
	return false;

}
//	11. ����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� NULL
// ����ָ�룬��ָ�����ָ���һ���������ָ��С����ָ�룬����л�����ʱ���ؿ�ָ�뼴Ϊ�뻷�ĵ�һ�����
struct ListNode *detectCycle(struct ListNode *head) {
	if (head == NULL){
		return NULL;
	}
	if (head->next == head){
		return head;
	}
	struct ListNode* fast = head->next;
	struct ListNode* slow = head;

	while (fast != NULL&& fast>slow){
		fast = fast->next;
		slow = slow->next;
	}
	return fast;


}


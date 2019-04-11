#pragma once

#include <malloc.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode *next;
	
};
//	链表面试题
//	1. 删除链表中等于给定值 val 的所有节点。 
struct ListNode* removeElements(struct ListNode* head, int val) {

	// 如果链表为空，返回空
	if (head == NULL){
		return NULL;
	}

	// 先不考虑第一个结点，相当于尾删

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

	// 如果第一个结点值为val，相当于头删

	if (head->val == val){
		struct ListNode* newHead = head->next;
		free(head);
		return newHead;

	}
	else
		return head;

}
//	2. 反转一个单链表。 
// 先后指针，或者三指针法
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
//	3. 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点
//	快慢指针，快每次走两步
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast != NULL&&fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;

	}
	return slow;

}
//	4. 输入一个链表，输出该链表中倒数第k个结点。 
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
//	5. 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		// 如果链表l1或l2为空
		if (l1 == NULL){
			return l2;
		}
		if (l2 == NULL){
			return l1;
		}
		ListNode* newHead = NULL; // 新链表的首结点
		ListNode* newTail = NULL; // 新链表的尾结点

		// 链表l1和l2都不为空，分别取两个链表的结点拼接在一起组成新的链表

		while (l1 != NULL&&l2 != NULL){

			// 取第一个链表的结点
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
			// 取第二个链表的结点
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

			// 如果一个链表被取完了
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
//	6. 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 .
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

			// 切割链表
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

		// 拼接链表

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
//	7. 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		// 链表为空
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
				// 开始删除重复结点
				prev->next = p2;
				p1 = p2;
				if (p2 != NULL)
				{
					p2 = p2->next;
				}

			}
		}
		pHead = fask->next;
		free(fask);   // 删除假结点

		return pHead;

	}
};
//	8. 链表的回文结构。
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		// 0、如果链表为空返回false，如果链表为单链表则返回true

		if (A == NULL){
			return false;
		}
		else if (A->next == NULL){
			return true;
		}

		// 1、找到链表的中间结点
		ListNode* fast = A;
		ListNode* slow = A;

		while (fast != NULL&&fast->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
		}

		// 2、逆置后半部分
		ListNode* p1 = slow;
		ListNode* p2 = p1->next;

		while (p1 != NULL){
			p1->next = slow;
			slow = p1;
			p1 = p2;
			p2 = p2->next;
		}

		// 3、从头、尾指针向中间遍历，判断A是否是回文 

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
//	9. 输入两个链表，找出它们的第一个公共结点。
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL){
		return NULL;
	}
	struct ListNode* p = headA;
	struct ListNode* q = headB;

	// 定义两个指针同时出发，如果p为NULL另p=headB,否则让p=p->next;
	// 如果q==NULL,q=headA,否则q=q->next;
	// 最后p=q时返回p,即为交点
	while (p != q) {
		p = !p ? headB : p->next;   
		q = !q ? headA : q->next;
	}
	return p;
}
//	10. 给定一个链表，判断链表中是否有环。 
// 快慢指针，快的先走一步，如果两个指针相遇则有环，反之无环
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
//	11. 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
// 快慢指针，快指针比慢指针快一步，如果快指针小于慢指针，则必有环，此时返回快指针即为入环的第一个结点
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


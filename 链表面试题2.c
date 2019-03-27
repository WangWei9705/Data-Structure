// 输入一个链表，输出该链表中倒数第k个结点。


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* front=pListHead;
		ListNode* back=pListHead;
		unsigned int i=0;
		for(i=0;i<k&&front!=NULL;i++){
			front =front->next;
		}
		
		
		if(i<k){
			return NULL;
		}
		
		while(front!=NULL){
			front=front->next;
			back=back->next;
		}
		return back;
    
    }
};


// 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
// 使用快慢指针


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
	ListNode* fast=head;
	ListNode* slow=head;
	
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		
	}
    return slow;
}


// 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

// 示例：

// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	// 如果链表l1或l2为空
	if(l1==NULL){
		return l2;
	}
	if(l2==NULL){
		return l1;
	}
	struct ListNode* newHead=NULL; // 新链表的首结点
	struct ListNode* newTail=NULL; // 新链表的尾结点
	
	// 链表l1和l2都不为空，分别取两个链表的结点拼接在一起组成新的链表
	
	while(l1!=NULL&&l2!=NULL){
		
		// 取第一个链表的结点
		if(l1->val<=l2->val){
			if(newTail!=NULL){
				newTail->next=l1;
				newTail=l1;
			}
			else{
				newHead=newTail=l1;
			}
			l1=l1->next;
		}
		// 取第二个链表的结点
		else{
				if(newTail!=NULL){
				newTail->next=l2;
				newTail=l2;
			}
			else{
				newHead=newTail=l2;
			}
			l2=l2->next;
		}
		
		// 如果一个链表被取完了
		if(l1!=NULL){
			newTail->next=l1;
		}
		else{
			newTail->next=l2;
		}
	}
		return newHead;
			
			
    
}



// 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前

// 给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
		
		ListNode* small=NULL;
		ListNode* small_last=NULL;
		ListNode* big=NULL;
		ListNode* big_last=NULL;
		
		ListNode* cur;
		for(cur=pHead;cur!=NULL;cur=cur->next){
			
			// 切割链表
			if(cur->val<x){
				if(small_last==NULL){
					small=small_last=cur;
				}
				else{
					small_last->next=cur;
					small_last=cur;
				}
			}
				
			else{
				if(big_last==NULL){
					big=big_last=cur;
				}
				else{
					big_last->next=cur;
					big_last=cur;
				}
			}
		}
			
		// 拼接链表
			
		if(small_last!=NULL){
			small_last->next=big;
		}
		if(big_last!=NULL){
			big_last->next=NULL;
		}
		if(small!=NULL){
			return small;
		}
		else{
			return big;
		}
	}
		
};

 // 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针		
		
		/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
		// 如果链表为空，返回空
		if(pHead==NULL; {
			return NULL;
		}
		
		// 创立假结点
		ListNode* fask=(ListNode*)malloc(sizeof(ListNode));
		fask->next=pHead;
		
		ListNode* prev=fask;
		ListNode* p1=pHead;
		ListNode* p2=pHead->next;
		
		while(p2!=NULL){
			if(p1->val!=p2->val){
				prev=p1;
				p1=p2;
				p2=p2->next;
			}
			
			// 开始删除重复结点
			else{
				while(p2!=NULL&&p1->val==p2->val){
					p2=p2->next;
				}
				
				prev->next=p2;
				p1=p2;
				if(p2!=NULL){
					p2=p2->next;
				}
			}
		}
		
		// 删除假结点
		pHead=fask->next;
		free(fask);
		return pHead;
		
		

    }
};		
	
// 链表的回文结构  1221

// 对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。

// 给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

// 测试样例：
// 1->2->2->1
// 返回：true	
			
			
	/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
		// 0、如果链表为空返回false，如果链表为单链表则返回true
		
		if(A==NULL){
			return false;
		}
		else if(A->next==NULL){
			return true;
		}
		
		// 1、找到链表的中间结点
		ListNode* fast=A;
		ListNode* slow=A;
		
		while(fast!=NULL&&fast->next!=NULL){
			fast=fast->next->next;
			slow=slow->next;
		}
		
		// 2、逆置后半部分
		ListNode* p1=slow;
		ListNode* p2=p1->next;
		
		while(p1!=NULL){
			p1->next=slow;
			slow=p1;
			p1=p2;
			p2=p2->next;
		}
			
		// 3、从头、尾指针向中间遍历，判断A是否是回文 
		
		while(A!=slow){
			if((A->val)!=(slow->val)){
				return false;
			}
			else{
				if(A->next==slow){
					return true;
				}
				A=A->next;
				slow=slow->next;
			}
		}
		
			return true;
	}
			

    			
};	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	









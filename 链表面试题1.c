// 链表基本操作
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


// 头插
void SListPushFront(SList *s, SListDataType v) {
	Node *node =(Node *)malloc(sizeof(Node));
	node->value=v;
	
	node->next=s->first;
	s->first=node;
}
// 尾插
void SListPushBack(SList *s, SListDataType v) {
	
	Node *node=(Node *)malloc(sizeof(Node));
	node->value=v;
	
	// 链表为空
	if(s->first==NULL){
		s->first=node;
	}
	// 链表中至少有一个结点
	else{
		// 先找到最后一个结点
		Node *cur=s->first;
		while(cur->next!=NULL){
			cur=cur->next;
		}
		cur->next=node;
	}
}
	
// 头删
void SListPopFront(SList *s, SListDataType v) {
	assert(s!=NULL);
	assert(s->first!=NULL);
	
	Node *next=s->first->next;
	free(s->first);
	s->first=next;
}
	
	

// 尾删
void SListPopFront(SList *s, SListDataType v) {
	assert(s!=NULL);
	assert(s->first!=NULL);
	
	// 如果只有一个结点，相当于头删
	
	if(s->first->next==NULL){
		free(s->first);
		s->first=NULL);
	}
	else{
		
		// 找到最后一个结点
		Node *cur =s->first;
		while(cur->next!=NULL){
			cur=cur->next;
		}
		
		free(cur->next);
		cur->next=NULL;
	}
		
	
	
}
// 逆置(三指针法，遍历加头插法）

void SListReverse(Node *head){
	
	Node *p1=NULL;
	Node *p2=head;
	Node *p3=head->next;
	
	while(p2!=NULL){
		p2->next =p1;
		if(p3!=NULL){
			p1=p2;
			p2=p3;
			p3=p3->next;
		}
		return p1;
	}
}

void SListReverse(Node *head){
	
	Node *result=NULL;
	Node *cur=head;
	while(cur!=NULL){
		Node *next=cur->next;
		
		cur->next=result;
		result=cur;
		cur=next;
	}
	return result'
}

// 删除链表中等于给定值 val 的所有节点
struct ListNode* removeElements(struct ListNode* head, int val) {
	// 如果链表为空
	if(head==NULL){
		return NULL;
	}
	

	
	// 如果第一个结点不为val
	
	struct ListNode* cur =head;
	while(cur->next!=NULL){
		if(cur->next->val==val){
					
		struct ListNode* next=cur->next->next;
		free(cur->next);
		cur->next=next;
		}
		
		else{
			
			cur=cur->next;
		}
	}
	
	
	// 如果第一个结点就是Val
	
	if(head->val==val){
		
		struct ListNode* Newhead=head->next;
		free(head);
		return Newhead;
	}
	else{
		
		return head;
	}
}
		
		














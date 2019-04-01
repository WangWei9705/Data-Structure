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


// 链表的初始化
void SListInit(SList * s){
	assert(s!=NULL);
	s->first=NULL;
	
	
}

// 头插

void SListPushFront(SList *s, SListDataType v) {
	assert(s!=NULL);
	
	Node *node =(Node*) malloc(sizeof(Node));
	node->value=v;
	
	node->next =s->first;
	s->first=node;
	
}


// 尾插
void SListPushBack(SList *s, SListDataType v) {
	
	Node* node =(Node*)malloc(sizeof(Node*));
	node ->value=v;
	
	// 链表为空
	if(s->first==NULL){
		s->first=node;
		return ;
	}
	
	// 链表中至少有一个结点
	
	Node* cur=s->first;
	if(cur->next!=NULL){
		cur =cur->next;
	}
	cur->next=node;
	
}

// 头删
void SListPopFront(SList *s) {
	asser(s!=NULL);
	assert(s->first!=NULL);
	
	Node* next =s->first->next;
	free(s->first);
	s->first=next;
}

// 尾删
void SListPopBack(SList *s) {
	asser(s!=NULL);
	assert(s->first!=NULL);
	
	
	// 只有一个结点
	
	if(s->first->next=NULL){
		free(s->first);
		s->first=NULL;
		return ;
	}
	
	// 不止有一个结点
	
	Node* cur=s->first;
	while(cur->next->next!=NULL){
		cur=cur->next;
	}
	
	free(cur->next);
	cur->next=NULL;
}
		


		
		
		
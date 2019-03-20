
// 1、无头单向非循环链表增删查改实现
typedef int SLTDataType;

typedef struct SListNode
{
 SLTDataType _data;
 struct SListNode* _next;
}SListNode;

typedef struct SList
{
 SListNode* _head;
}SList;


// 初始化
void SListInit(SList* plist)
{
	assert(plist!=NULL);
	plist->frist=NULL;       // 初始化一个空链表
}


// 销毁——>删除所有结点
void SListDestory(SList* plist)
{
	Node*cur=pliist->first;
	Node*next =cur->next;
	while(cur!=NULL)
	{
		
		next=cur->next;
		free(cur);
		
	}
	pliist->first=NULL;
	
}


SListNode* BuySListNode(SLTDataType x);

// 头插
void SListPushFront(SList* plist, SLTDataType x)
{
	Node *node=(Node*)malloc(sizeof(Node));
	node->value=x;
	node->next=plist->first;
	plist->frist=node;
	
}

// 头插
void SListPushFront2(SList* plist, SLTDataType x)
{
	Node* node=(Node*)malloc(sizeof(Node));
	
	node->value=x;
	node->next=pliist->first;
	pliist->first=node;
}

// 尾插
void SListPushBack(SList* plist, SLTDataType x)
{
	Node *node=(Node*)malloc(sizeof(Node));
	node->value=x;
	
	// 1、链表为空
	
	if(plist->first==NULL)
	{
		node->next =NULL;
		plist->first=node;
		return ;
	}
	
	// 2、链表中至少有一个结点
	// 	找最后一个结点
	Node *cur=plist->first;
	if(cur->next!=NULL)
	{
		cur=cur->next;
	}
	cur->next=node;
	
}


// 尾插(需要先申请一个结点用来存放待插入的数据）
void SListPushBack(SList* plist, SLTDataType x)
{
	Node* node =(Node*)malloc(sizeof(Node));
	node->value=x;
	
	// 如果链表为空
	if(plist->first==NULL)
	{
		node->next=NULL;
		plist->first=node;
		
	}
	
	// 至少有一个结点,需要先找到最后一个结点
	Node* cur =pliist->first;
	while(cur->next!=NULL)
	{
		
		cur=cur->next;
	}
	cur->next=node;

	
}


// 头删
void SListPopFront(SList* plist)
{
	assert(plist!=NULL);         // 链表必须存在
	assert(plist->first!=NULL);
	
	Node* next=plist->first->next;
	free(p->first);
	p->first=next;
}


// 尾删
void SListPopBack(SList* plist)
{
	assert(plist!=NULL);         // 链表必须存在
	assert(plist->first!=NULL);   // 不能没有结点
	
	
	// 只有一个结点
	if(plist->first->next==NULL)
	{
		free(plist->first);
		plist->first=NULL;
		return ;
		
	}
	
	// 不止一个结点
	
	Node *cur=p->first;
	while(cur->next->next!=NULL)
	{
		cur=cur->next;
	}
	free(cur->next);
	cur->next=NULL;
	
	
}

// 尾删
void SListPopBack2(SList* plist)
{
	assert(plist!=NULL);
	assert(plist->first!=NULL);
	
	// 只有一个结点
	
	if(plist->first->next==NULL)
	{
		free(plist->first);
		plist->first=NULL;
	}
	
	// 不止一个结点
	
	Node* cur;
	for(cur=plist->first;cur->next->next!=NULL;cur++)
	{
		cur=cur->next;
	}
	free(cur->next);
	cur->next=NULL;
}


SListNode* SListFind(SList* plist, SLTDataType x)
{
	Node* cur=plist->first;
	while(cur!=NULL)
	{
		if(cur->value=x)
		{
			return cur;
		}
		cur =cur->next;
	}
	return NULL;
}

// 在pos的后面进行插入(pos一定是链表中的结点，相当于尾插）
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	Node*cur=(Node*)malloc(sizeof(Node));
	cur->value=x;
	cur->next=pos->next;
	pos->next=cur;
}

// 删除pos的后的结点 （pos是链表的结点且不为最后一个结点）
void SListEraseAfter(SListNode* pos)
{
	Node*cur=pos->next;
	pos->next=pos->next->next;
	free(pos->next);
	free(cur);
	
}

// 删除指定值
void SListRemove(SList* plist, SLTDataType x)
{
	// 链表为空
	if(plist==NULL)
	{
		return NULL;
	}
	// x 为第一个结点
	if(pliist->first->value=x)
	{
		Node*next=plist->first->next;
		free(plist->first);
		plist->first=next;
		return ;
	}
	// x 不为第一个结点
	Node* cur=plist->first;
	while(cur->next!=NULL)
	{
		if(cur->next->value=x)
		{
			Node*next=cur->next->next;
			free(cur->next);
			cur->next=next;
			return ;
				
		}
		cur=cur->next;
	}
}





// 反转链表——创建三个指针，p1=NULL,p2=head,p3=p2->next;

Node *Reverse(Node *head)
{
	Node *p1=NULL;
	Node *p2=head;
	Node *p3=p2->next;
	
	while(p2!=NULL)
	{
		p2->next=p1;
		if(p3==NULL)
		{
			break;
		}
		p1=p2;p2=p3;p3=p3->next;
	
	}
	return p1;
}


// 合并两个有序链表

struct ListNode * MergeTwList(struct ListNode* L1,struct ListNode* L2)
{
	// 两条链表其中一条为空
	if(L1==NULL)
	{
		return L2;
	}
	else
	{
		return L1;
	}
	
	struct ListNode* p1=L1;
	struct ListNode* p2=L2;
	struct ListNode* result =NULL,*tail=NULL;
	while(p1!=NULL&&p2!=NULL)
	{
		
		if(p1->value<= p2->value)
		{
			if(tail==NULL)
			{
				result=tail=p1;
			}
			else
			{
				tail->next=p1;
				tail=p1;
			}
			p1=p1->next;
			
		}
		else
		{
			
		}
	}
	
	// 将剩下的那部分继续取完
	if(c1!=null)
	{
		tail->next=p1;
	}
	else
	{
		tail->next=c2;
	}
	return result;
	
}

// 以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前

 ListNode* partition(ListNode* pHead, int x) {
	 ListNode* p1=NULL;
	 ListNode* p2=NULL;
	 ListNode* p1_last=NULL;
	 ListNode* p2_last=NULL;
	 while(pHead!=NULL)
	 {
		 if(pHead->val<x)
		 {
			 if(p1_last=NULL)
			 {
				 p1=p1_last=pHead;
			 }
			 else
			 {
				 p1_last->next=pHead;
				 p1_last=pHead;
			 }
		 }
		 else
		 {
				 p2=p2_last=pHead;
			 }
			 else
			 {
				 p2_last->next=pHead;
				 p2_last=pHead; 
		 }
	 }
	 
	 if(p1_last!=NULL)
	 {
	 p1_last->next=p2;
	 }
	 
	 if(p2_last!=NULL)
	 {
	 p2_last->next=NULL;
	 }
	 
	 
	 // 拼接
	 if(p1！=NULL)
	 {
		 
	 }
       
    }




// 删除重复结点

ListNode* deleteDuplication(ListNode* pHead)
{
	ListNode* prev=fask;
	ListNode* p1=pHead;
	ListNode* p2=pHead->next;
	
	while(p2!=NULL)
	{
		
	}
	
}

// 回文
// 找到链表的中间结点，逆置后半部分，














































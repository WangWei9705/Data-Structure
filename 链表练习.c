// 头插
void PushFront( Node* head,Node* node){
	
	node->next=head;
	head =node;
	
}

// 尾插
 void PushBack(Node* head,Node* node){
	 
	 // 链表为空
	 if(head ==NULL){
		 
		 head=node;
		 
		 return ;
	 }
	 
	 // 链表中至少有一个结点,找到最后一个结点
	 
	 Node* cur=head;
	 while(cur->next!=NULL){
		 
	 cur=cur->next;
	 
	 }
	 cur->next=node;
 }
 
 // 反转链表
 
 
 // 三指针法：
 void  reverse(Node* head){
	 Node* p1=NULL;       // 结果指针
	 Node* p2=head;		  // 遍历指针
	 Node* p3=head->next;
	 
	 while(p2->next!=NULL){
		 
		 p2->next=p1;
		 
		 if(p3!=NULL){
			 p1=p2;
			 p2=p3;
			 p3=p3->next;
		 }
	 }
	 return p1;
	 
 }
 
 // 遍历+头插法：
 
 
 void reverse (Node* head){
	 Node* resul =NULL;
	 Node* cur =head;
	 
	 while(cur->next!=NULL){
		 
		 cur->next=head;
		 head=cur;
		 
		 cur=cur->next;
	 }
	 
	 return result;
 }
	 
 
// 栈的实现-->顺序表实现：（栈：先进后出）

// 下面是定长的静态栈的结构，实际中一般不实用，所以我们主要实现下面的支持动态增长的栈
typedef int STDataType;
#define N 10
typedef struct Stack
{
 STDataType _a[N];
 int _top; // 栈顶
}Stack;
// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
 STDataType* _a;
 int _top; // 栈顶
 int _capacity; // 容量
}Stack;
void StackInit(Stack* ps){
	ps->size=0;
	
}


void StackDestory(Stack* ps){
	
	ps->size=0;
}

// 插入(压栈）
void StackPush(Stack* ps, STDataType x){
	ps->array[ps->size]=x;
	
	
}
// 删除(弹出）
void StackPop(Stack* ps){
	ps->size--;
}



// 返回栈顶的数据，不需要删除栈顶的数据
STDataType StackTop(Stack* ps){
	return =ps->array[ps->size-1];
}

// 返回栈内是否为空
int StackEmpty(Stack* ps);

// 返回栈内数据个数
int StackSize(Stack* ps);

void TestStack();

 
 // 队列的实现（队列：先进先出）
 typedef int QUDataType;
typedef struct QueueNode
{
 struct QueueNode* _next;
 QUDataType _data;
}QueueNode;
typedef struct Queue
{
 QueueNode* _front; // 队头
 QueueNode* _rear; // 队尾
}Queue;

void QueueInit(Queue* pq){
	
	pq->front=pq->rear=NULL;
	
}

void QueueDestory(Queue* pq);

QueueNode* BuyQueueNode(QUDataType x);

// 入队(尾插）
void QueuePush(Queue* pq, QUDataType x);

// 出队（头删）
void QueuePop(Queue* pq);

QUDataType QueueFront(Queue* pq);

QUDataType QueueBack(Queue* pq);

int QueueEmpty(Queue* pq);

int QueueSize(Queue* pq);

void TestQueue();


// 栈的应用--括号匹配问题





























 

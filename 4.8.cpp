// 根据前序和中序遍历还原二叉树
Node* BulidTree(char pre[],char in[],int size){
	if(size==0){
		return NULL;
	}
	
	char rootvalue=pre[0];
	int r=-1;
	
	for(int i=0;i<szie;i++){
		if(in[i]==rootvalue){
			r=i;
			break;
		}
	}
	assert(r!=-1);
	
	Node* root =(Node*)malloc(sizeof(Node));
	root->value=rootvalue;
	
	root->left=BulidTree(pre+1;in,r);
	root->right=BulidTree(pre+1+r,in+r+1,size-1-r);
	
	
	return root;
}


// 使用队列打印二叉树层序遍历
Node* levelTree(Node* root){
	if(root==NULL){
		printf("\n");
		return ;
	}
	
	using std::queue;
	queue<Node* > q;
	
	q.push(root);
	while(!q.empty()){
		Node* front=q.front();
		q.pop();
		printf("%c",front->value);
		
		if(front->left!=NULL){
			q.push(front->left);
		}
		
		if(front->right!=NULL){
			q.push(front->right);
		}
	}
}


// 给出带空节点的二叉树前序，还原二叉树

typedef struct {
	Node* root;
	int used;
} Result ;

Result CreateTree(char preorder[],int size){
	Result ret;
	
	if(size==0){
		
		ret={NULL,0};
		return ret;
	}
	
	if(preorder[0]=='#'){
		ret={NULL,1};
		return ret;
	}
	
	// 创建根结点
	Node* root=(Node*)malloc(sizeof(Node));
	root->value=preorder[0];
	
	// 创建左子树
	Result left =CreateTree(preorder +1,1);
	Result right=CreateTree(preorder+1+left.used,size-1-left.used);
	
	ret={root,1+left.used,right.used};
	
	return ret;
}

// 根据层序遍历判断一棵树是否为完全二叉树

bool IsComplete(Node* root){
	if(root==NULL){
		return true;
	}
	
	using std::queue;
	queue <Node*> q;
	q.push(root);
	while(true){
		Node* front=q.front;
		q.pop();
		
		if(front==NULL){
			break;
		}
		
		
		q.push(front->left);
		q.push(front->right);
		

	}
	
	while(!q.empty()){
		Node* front =q.front();
		q.pop();
		
		if(q.front != NULL){
			return false;
		}
	}
	return true;
}

// 根据后序和中序遍历创建一颗二叉树

Node* buildTree(char postorder[],char inorder[],int size){
	if(size==0){
		return NULL;
	}
	
	// 后序的最后一个结点为二叉树的根结点
	char rootvalue=postorder[size-1];
	int r=-1;
	
	for(int i=0;i<size;i++){
		if(inorder[i]==rootvalue){
			r=i;
			break;
		}
	}
	
	Node* root=(Node*)malloc(sizeof(Node));
	root->value=rootvalue;
	
	root->left=buildTree(postorder,inorder,r);
	root->right=buildTree(postorder+r,inorder+r+1,size-1-r);
	
	return root;
}
	
	
	
// 使用栈实现二叉树的前中后序遍历

void preorder(Node* root){
	using std::stack;
	stack<Node*> s;
	Node* cur=root;
	
	while(!s.empty() || cur!=NULL){
		while(cur!=NULL){
			printf("%c",cur->value);
			// 开始入栈
			s.push(cur);
			cur=cur->left;
		}
		
		// 定义栈顶
		Node* top =s.top();
		s.pop();
		
		cur=top->right;
	}
	printf("\n");
}

void inorder(Node* root){
	using std::stack;
	stack <Node*> s;
	Node* cur =root;
	while(!s.empty() || cur!=NULL ){
		while(cur!=NULL){
			s.push(cur);
			cur=cur->left;
		}
		
		Node* top=s.top();
		s.pop();
		
		printf("%c",top->value);
		
		cur=top->right;
	}
	printf("\n");
	
}

void postorder(Node* root){
	using std::stack;
	stack <Node*> s;
	Node* cur=root;
	Node* last=NULL; // 上一次遍历完子树的根结点
	while(!s.empty() || cur!=NULL){
		while(cur!=NULL){
			s.push(cur);
			cur=cur->left;
		}
		Node* top=s.top();
		s.pop();
		if(top->right==NULL){
			printf("%c",top->value);
			s.pop();
			last=top;
		}
		
		else if(top->right=last){
			printf("%c",top->value);
			s.pop();
			
			last=top;
		}
		else{
			cur=top->right;
		}
	
	}
	
	printf("\n");
}
	






	
#define Size 1024	
void preorder(Node* root){
	int top=-1;
	Node* stack[Size];
	for(; ; ){
		// 根
		if(root==NULL){
			break;
		}
		
		printf("%c",root->value);
		
		// 左子树
		for(;root;root=root->left){
			add(&top,root);
		}
		
		root=delete(&top);
		
		// 右子树
		
		root=root->right;
	}
}
		

void inorder(Node* root){
	
	int top=-1;  // 定义栈顶
	Node* stack[Size];
	for(; ;){
		for(; root;root=root->left){
			add(&top,root);  // 入栈
		}
		
		root=delete(&top);  // 删除
		
		if(root==NULL){
			break;
		}
		
		printf("%d",root->value);
		root=root->right;
	}
}
			
		
	
void postorder(Node* root){
	int top=-1;
	Node* strack[Size];
	
	for(;;){
		for(;root;root->left){
			add(&top,root);
		}
		root=delete(&top);
		
		root=root->right;
		
		if(root==NULL){
			break;
		}
		
		printf("%c",root->value);
	}
}


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}






















	
	
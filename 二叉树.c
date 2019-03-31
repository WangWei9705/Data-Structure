// 二叉树 

// 二叉树的实现

typedef struct Node {
	int value;
	struct Node *left;		// 左孩子，同时代表着整棵左子树
	struct Node *right;		// 右孩子，同时代表着整棵右子树
};



// 前序遍历   根 左 右

void PreorderTraversal(Node *root){
	
	if(root==NULL){
		return ;
	}
	

	printf("%d",root->value);
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}



// 中序遍历  左 根 右


void void InorderTraversal(Node *root) {
	if(root==NULL){
		return ;
	}
	
	InorderTraversal(root->left);
	printf("%d",root->value);
	InorderTraversal(root->right);
}

// 后序遍历   左 右 根

void PostorderTraversal(Node *root){
	if(root==NULL){
		return ;
	}
	
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	printf("%d",root->value);
}


// 通过遍历的方法求二叉树的结点个数

int size;
void Count(Node *root){
	if(root==NULL){
		return ;
	}
	
	size++;
	Count(root->left);
	Count(rooot->right);
}

// 通过递推方法计算二叉树叶子结点个数

int Size(Node *root){
	
	// 当二叉树不存在时，结点数为0
	if(root==0){
		return 0;
	}
	
	// 只存在根结点，结点数为1
	if(root->left==NULL&&root->right==NULL){
		return 1;
	}
	
	// 已知左子树结点个数
	int left=Size(root->left);
	
	// 已知右子树结点个数
	int right=Size(root->right);
	
	// 总结点数=左+右
	return left+right;
}


// 求二叉树的高度

int Gethigh(Node *root){
	
	// 如果二叉树不存在，高度为0
	if(root==NULL){
		return 0;
	}
	
	// 如果二叉树只有根结点，高度为1
	if(root->left==NULL && root->right==NULL){
		return 1;
	}
	
	
	// 已知左子树高度
	int left=Gethigh(root->left);
	// 已知右子树高度
	int right=Gethigh(root->right);
	
	// 总高度=左/右中较大的+1
	return ((left>right) ? left:right)+1 ;
	
}


// 求二叉树K层结点个数

int GetKlevelSize(Node *root,int K){
	
	// 如果二叉树不存在，结点个数为0
	if(root==NULL){
		return 0;
		
	}
	// 如果K=1,第k层就是跟结点，结点数为1
	
	if(k==1){
		return 1;
	}
	
	// 已知左子树K层节点个数
	int left=GetKlevelSize(root->left,k-1);
	// 已知右子树K层节点个数
	int right=GetKlevelSize(root->right,k-1);
	
	// 第K层结点数=左子树第K层结点数+右子树第K层节点数
	return left+right;
	
}



// 在二叉树中找指定值,找到了返回节点地址，没找到返回NULL

Node *Find(Node *root,int v){
	
	// 如果二叉树不存在，则找不到
	if(root==NULL){
		
	return NULL;
	}
	// 先从根节点开始找
	if(root->val=v){
		return root;
	}
	// 再从左子树开始找，找到了返回地址
	Node *p = Find(root->left,v);
	if(p->val=v){
		return p;
	}
	
	// 没找到去右子树找
	p = Find(root->right,v);
	
	return p;   // 找到了p为指定地址，没找p为空
	
}



























	
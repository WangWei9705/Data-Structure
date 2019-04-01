// 二叉树查找
Node* Find(Node* root,int v){
	if(root==NULL){
		return NULL;
	}
	
	if(root->value=v){
		return root;
	}
	
	Node* ret=Find(root->left,v);
	if(ret!=NULL){
		return ret;
	}
	ret=Find(root->right,v);
	if(ret!=NULL){
		return ret;
	}
	else{
		return NULL;
	}
}
	
	
	
// 求二叉树高度

Node* GetHeight(Node* root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL&&root->right==NULL){
		return 1;
	}
	
	int left=GetHeight(root->left);
	int right=GetHeight(root->right);
	
	return left+right+1;
}

// 根据前序还原二叉树	
	
//	ABE###CD size=8
	
typedef struct {
	Node* root;
	int used;
} Result;
	

Result CreatTree(char preorder[],int size){
	if(size==0){
	Result ret={NULL,0};
		return ret;
		
		
	}
	
	if(preorder[0]=='#'){
		Result ret={NULL,1};
		return ret;
	
	}
	// 创建根
	
	Node* root=(Node*)malloc(sizeof(Node));
	root->value=preorder[0];
	
	// 创建左子树
	
	Result left=CreatTree(preorder+1,size-1);
	
	// 创建右子树
	Result right=CreatTree(preorder+1+left.used,size-1-left.used);
	
	root->left=left.root;
	root->right=right.root;
	
	Result ret ={root,preorder+1+left.used+right.used)};
	
	return ret;
	
}

// 根据前序和中序还原二叉树








	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
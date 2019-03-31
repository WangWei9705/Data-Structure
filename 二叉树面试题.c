
//  二叉树的前序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *p;
int size;
void Preorder(struct TreeNode* root){
    if(root==NULL){
        return ;
    }
    
    p[size++]=root->val;
    Preorder(root->left);
    Preorder(root->right);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    
    p=(int *)malloc(sizeof(int)*100*100);
    size=0;
    
    Preorder(root);
    *returnSize=size;
    
    return p;
    
    
   
}
//  二叉树中序遍历 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *p;
int size;
void Inorder(struct TreeNode* root){
    if(root==NULL){
        return;
    }
    
    // 左子树
    Inorder(root->left);
    // 根
    p[size++]=root->val;
    // 右子树
    Inorder(root->right);
    
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    p=(int *)malloc(sizeof(int)*100*100);
    size=0;
    
    Inorder(root);
    
    *returnSize=size;
    return p;
    
}
// 二叉树的后序遍历 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int size;
int *p;
void postorder(struct TreeNode* root){
    if(root==NULL){
        return ; 
    }
    
    // 左子树
    postorder(root->left);
    // 右子树
    postorder(root->right);
    // 根
    p[size++]=root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    p=(int *)malloc(sizeof(int)*100*100);   // 适当扩大容量，防止溢出
    size = 0;
    
    postorder(root);
    *returnSize = size;
    return p;
}




// 判断两颗二叉树是否相同

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p==NULL&&q==NULL){
        return true;
    }
    if(p==NULL || q==NULL){
        return false;
    }
    
    
    
   return (p->val==q->val)&& isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    
}

// 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

// 思路：一棵树为另一棵树的子树有三种情况
//         1、两棵树相同
// 		   2、为一棵树的左子树
//         3、为一棵树的右子树


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p==NULL&&q==NULL){
        return true;
    }
    if(p==NULL || q==NULL){
        return false;
    }
    
    
    
   return (p->val==q->val)&& isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    
}

	
bool isSubtree(struct TreeNode* s,struct TreeNode* t){
	if(s==NULL&&t==NULL){
		return true;
	}
	
	if(s==NULL||t==NULL){
		return false;
	}
	
	return isSameTree(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
}



// 给定一个二叉树，找出其最大深度。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root==NULL){
        return 0;
    }
    
    // 已知左子树的最大深度
    int left=maxDepth(root->left);
    // 已知右子树的最大深度
    int right=maxDepth(root->right);
    
    // 最大深度=左子树深度/右子树深度+1
    
    return ((left>right)?left:right) +1;
}


// 给定一个二叉树，判断它是否是高度平衡的二叉树。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getHigh(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    
    // 已知左子树高度
    int left=getHigh(root->left);
    // 已知右子树高度
    int right=getHigh(root->right);
    
    // 高度
    return ((left>right)?left:right)+1;
}
bool isBalanced(struct TreeNode* root) {
   // 二叉树为空，则为平衡树
    if(root==NULL){
        return true;
    }
    
    // 左子树和右子树都为平衡树且左右子树高度差<=1则为平衡树
    int ret=abs(getHigh(root->left)-getHigh(root->right));
    return isBalanced(root->left)&&isBalanced(root->right)&&ret<=1;
    
    
}


// 给定一个二叉树，检查它是否是镜像对称的。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode* p,struct TreeNode* q){
    if(p==NULL&&q==NULL){
        return true;
    }
    
    if(p==NULL||q==NULL){
        return false;
    }
    
    return (p->val==q->val)&&isMirror(p->left,q->right)&&isMirror(p->right,q->left);
    
}
bool isSymmetric(struct TreeNode* root) {
    
    if(root==NULL){
        return true;
    }
    
 return isMirror(root->left,root->right);
    
}





















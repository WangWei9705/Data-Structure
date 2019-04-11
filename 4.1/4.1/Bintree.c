#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int value;
	struct Node *left;		// 左孩子，同时代表着整棵左子树
	struct Node *right;		// 右孩子，同时代表着整棵右子树
}Node;

// 二叉树的前中后序遍历
void preorder(Node* root){
	if (root == NULL){
		return;
	}
	printf("%d ", root->value);
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root){
	if (root == NULL){
		return;
	}
	inorder(root->left);
	printf("%d ", root->value);
	inorder(root->right);
}

void postorder(Node* root){
	if (root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->value);
}
// 给出前序和空字符串，还原二叉树
typedef struct{
	Node* root;
	int used;
}Result;

Result CreateTree(char p[],int size){
	if (p == NULL){
		Result r = { NULL, 0 };
		return r;
	}

	if (p[0] == NULL){
		Result r = { NULL, 1 };
		return r;
	}

	// 创建根结点
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = p[0];
	//创建左子树
	Result left = CreateTree(p + 1, size - 1);
	root->left = left.root;
	Result right = CreateTree(p + 1 + left.used, size - 1 - left.used);
	root->right = right.root;

	Result r = { root, 1 + left.used + right.used };
	return r;

}
// 二叉树中查找指定值
Node* Find(Node* root, int v){
	if (root == NULL){
		return NULL;
	}

	if (root->value = v){
		return root;
	}

	struct Node* ret = Find(root->left,v);
	if (ret != NULL){
		return ret;
	}
	ret = Find(root->right,v);
	if (ret != NULL){
		return ret;
	}
	else{
		return NULL;
	}
}



// 求二叉树高度

int GetHeight(struct Node* root){
	if (root == NULL){
		return 0;
	}
	if (root->left == NULL&&root->right == NULL){
		return 1;
	}

	int left = GetHeight(root->left);
	int right = GetHeight(root->right);

	return (left > right ? left : right) + 1;
}


// 创建二叉树
Node* CreateNode(char value){
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = node->right = NULL;
	return node;

}




void test2() {
	char * preorder = "ABE###CD";
	int size = strlen(preorder);

	Result r = CreateTree(preorder, size);

	printf("根的值是: %c\n", r.root->value);
}

//找最近共同祖先
// 判断p、q是否在同一侧
struct Node* find(Node* root, Node* p){
	if (root == NULL){
		return NULL;
	}
	if (root == p){
		return root;
	}

	struct Node* ret = find(root->left, p);
	if (ret != NULL){
		return ret;
	}
	return find(root->right, p);

}




struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q) {
	if (p == NULL || q == NULL){
		return root;
	}

	struct Node* pleft = find(root->left, p);
	struct Node* qleft = find(root->left, q);
	if (pleft != NULL&&qleft != NULL){
		return lowestCommonAncestor(root->left, p, q);
	}

	if (pleft == NULL&&qleft == NULL){
		return lowestCommonAncestor(root->right, p, q);
	}
	return root;
}


void test(){
	Node *a = CreateNode('A');
	Node *b = CreateNode('B');
	Node *c = CreateNode('C');
	Node *d = CreateNode('D');
	Node *e = CreateNode('E');
	Node *f = CreateNode('F');
	Node *g = CreateNode('G');
	Node *h = CreateNode('H');

	a->left = b; a->right = c;
	b->left = d; b->right = e;
	c->left = f; c->right = g;
	d->left = NULL; d->right = NULL;
	e->left = NULL; e->right = h;
	f->left = NULL; f->right = NULL;
	g->left = NULL; g->right = NULL;
	h->left = NULL; h->right = NULL;

	Node *ancestor = lowestCommonAncestor(a, b, c);
	printf("公共祖先: %c\n", ancestor->value);

	/*Node* ret = Find(a, 'C');
	if (ret == NULL){
		printf("没找到C\n");
	}
	else{
		printf("找到了C,地址为：%p\n", ret);
	}

	
	printf("树的高度为：%d\n", GetHeight(a));*/


}

int main()
{	
	test();
	system("pause");
	return 0;
}

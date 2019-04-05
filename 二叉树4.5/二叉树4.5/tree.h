#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <queue>



// 非递归方式实现二叉树的层序遍历
// 使用队列

// 创建二叉树


typedef struct Node {
	struct Node *left;
	struct Node *right;
	char value;
}	Node;


typedef struct {
	Node* root;
	int used;
}Result;

Result CreateTree(char preorder[], int size){
	Result result;
	if (size == 0) {
		result.root = NULL;
		result.used = 0;
		return result;
	}

	if (preorder[0] == '#') {
		result.root = NULL;
		result.used = 1;
		return result;
	}

	// 创建根结点
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = preorder[0];

	// 创建左子树

	Result left = CreateTree(preorder + 1, size-11);   // +1表示跳过根结点
	
	Result right = CreateTree(preorder + 1 + left.used, size - 1 - left.used);

	Result ret = { root, 1 + left.used + right.used };

	return ret;

}

void Levelorder(Node* root){
	if (root == 0){
		printf("\n");
		return;
	}

	using std::queue;
	queue<Node* > q;

	// 开始入队

	q.push(root);

	while (!q.empty()){
		// 取队首元素
		Node* front = q.front();
		q.pop();

		printf("%c", front->value);

		if (root->left != NULL){
			q.push(root->left);
		}
		if (root->right != NULL){
			q.push(root->right);
		}

	}
	printf("\n");
	
}



void Test() {
	char *preorder = "ABD##E#H##CF##G";
	int size = strlen(preorder);
	Result result = CreateTree(preorder, size);

	Levelorder(result.root);
}
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
	struct Node *left;
	struct Node *right;
	char value;
}	Node;


typedef struct {
	Node *node;	// 构建出的二叉树的根结点
	int used;	// 构建过程中使用的序列长度
}	Result;

Result CreateTree(char preorder[], int size) {
	Result result;
	if (size == 0) {
		result.node = NULL;
		result.used = 0;
		return result;
	}

	if (preorder[0] == '#') {
		result.node = NULL;
		result.used = 1;
		return result;
	}

	// 根
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = preorder[0];
	// 左子树
	Result leftR = CreateTree(preorder + 1 , size - 1);
	// 右子树
	Result rightR = CreateTree(preorder + 1 + leftR.used , size - 1 - leftR.used);

	root->left = leftR.node;	// B 为根的一棵树
	root->right = rightR.node;	// C 为根的一棵树

	result.node = root;
	result.used = 1 + leftR.used + rightR.used;
	return result;
}

#include <queue>

void Levelorder(Node *root) {
	if (root == NULL) {
		printf("\n");
		return;
	}

	using std::queue;
	queue<Node *>	q;
	q.push(root);

	while (!q.empty()) {
		// 取队首元素
		Node *front = q.front();
		q.pop();
		// 层序遍历打印
		printf("%c ", front->value);
		// 拉下线
		if (front->left != NULL) {
			q.push(front->left);
		}

		if (front->right != NULL) {
			q.push(front->right);
		}
	}

	printf("\n");
}

// 判断是否是完全二叉树
bool IsComplete(Node *root) {
	if (root == NULL) {
		return true;
	}

	using std::queue;
	queue<Node *>	q;
	q.push(root);

	while (true) {
		Node *front = q.front();
		q.pop();
		if (front == NULL) {
			break;
		}
		q.push(front->left);
		q.push(front->right);
	}

	// 已经遇到一个 NULL 了，判断对了中剩余的数据是否还有非 NULL 的情况
	while (!q.empty()) {
		Node *front = q.front();
		q.pop();

		if (front != NULL) {
			return false;
		}
	}

	return true;
}

void Test() {
	char *preorder = "ABD##E#H##CF##G";
	int size = strlen(preorder);
	Result result = CreateTree(preorder, size);

	Levelorder(result.node);
}

Node * buildTree(char preorder[], char inorder[], int size) {

	if (size == 0) {
		return NULL;
	}

	char rootValue = preorder[0];
	int r = -1;
	for (int i = 0; i < size; i++) {
		if (inorder[i] == rootValue) {
			r = i; break;
		}
	}
	assert(r != -1);	// 中序中一定能找到 rootValue

	// 根
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	// 左子树
	root->left = buildTree(preorder + 1, inorder, r);
	// 右子树
	root->right = buildTree(preorder + 1 + r, inorder + r + 1, size - 1 - r);

	return root;
}

void Test2() {
	char *preorder = "ABDEHCFG";
	char *inorder = "DBEHAFCG";
	int size = strlen(preorder);

	Node *root = buildTree(preorder, inorder, size);

	Levelorder(root);
}

int Find(char array[], int size, char v) {
	for (int i = 0; i < size; i++) {
		if (array[i] == v) {
			return i;
		}
	}

	return -1;
}



Node * buildTree2(char postorder[], char inorder[], int size) {
	if (size == 0) {
		return NULL;
	}
	
	// 找到根的值在中序中出现的下标位置，放到 r 变量中
	int rootValue = postorder[size - 1];
	int r = Find(inorder, size, rootValue);
#if 0
	int r = -1;
	for (int i = 0; i < size; i++) {
		if (inorder[i] == postorder[size - 1]) {
			r = i;
			break;
		}
	}
#endif

	Node *root = (Node *)malloc(sizeof(Node));
	root->value = postorder[size - 1];
	root->left = buildTree2(postorder, inorder, r);
	root->right = buildTree2(postorder + r, inorder + r + 1, size - 1 - r);
	return root;
}

#include <stack>

using std::stack;

void PreorderNoR(Node *root) {
	stack<Node *> s;
	Node *cur = root;

	while (!s.empty() || cur != NULL) {
		while (cur != NULL) {
			printf("%c ", cur->value);
			s.push(cur);
			cur = cur->left;
		}

		Node *top = s.top();
		s.pop();

		cur = top->right;
	}

	printf("\n");
}

void InorderNoR(Node *root) {
	stack<Node *> s;
	Node *cur = root;

	while (!s.empty() || cur != NULL) {
		while (cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}

		Node *top = s.top();
		s.pop();
		printf("%c ", top->value);

		cur = top->right;
	}

	printf("\n");
}

void PostorderNoR(Node *root) {
	stack<Node *> s;
	Node *cur = root;
	Node *last = NULL;	// 上一次被完整遍历完的树的根结点

	while (!s.empty() || cur != NULL) {
		while (cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}

		Node *top = s.top();
		if (top->right == NULL) {
			printf("%c ", top->value);
			s.pop();

			last = top;
		}
		else if (top->right == last) {

			printf("%c ", top->value);
			s.pop();

			last = top;
		}
		else {
			cur = top->right;
		}
	}

	printf("\n");
}

Node *prev = NULL;
// 按中序遍历的方式给到我
void Foreach(Node *node) {
	node->left = prev;
	if (prev != NULL) {
		prev->right = node;
	}

	prev = node;
}

void Inorder(Node *root) {
	if (root != NULL) {
		Inorder(root->left);
		Foreach(root);
		Inorder(root->right);
	}
}

void Test5() {
	char *preorder = "531247689";
	char *inorder = "123456789";
	int size = 9;

	Node *root = buildTree(preorder, inorder, size);
	
	Inorder(root);

}


void Test4() {
	char *preorder = "ABDEHCFG";
	char *inorder = "DBEHAFCG";
	int size = strlen(preorder);

	Node *root = buildTree(preorder, inorder, size);

	Levelorder(root);
	PreorderNoR(root);
	InorderNoR(root);
	PostorderNoR(root);
}
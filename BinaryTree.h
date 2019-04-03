#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
	Node *left;
	Node *right;
	char value;
}	Node;

Node * Find(Node *root, char value) {
	if (root == NULL) {
		return NULL;
	}

	if (root->value == value) {
		return root;
	}

	Node *r = Find(root->left, value);
	if (r != NULL) {
		return r;
	}

	return Find(root->right, value);
}


int GetHeight(Node *root) {
	if (root == NULL) {
		return 0;
	}

	int left = GetHeight(root->left);
	int right = GetHeight(root->right);

	return (left > right ? left : right) + 1;
}

Node * CreateNode(char value) {
	Node * node = (Node *)malloc(sizeof(Node));
	node->value = value;
	node->left = node->right = NULL;
	return node;
}

void Test1() {
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
	d->left = NULL; d->right = h;
	e->left = NULL; e->right = NULL;
	f->left = NULL; f->right = NULL;
	g->left = NULL; g->right = NULL;
	h->left = NULL; h->right = NULL;

	Node *result = Find(a, 'H');
	if (result != NULL) {
		printf("找到了: %c\n", result->value);
	}
	result = Find(a, 'K');
	if (result == NULL) {
		printf("没找到 K\n");
	}

	printf("高度: %d\n", GetHeight(a));
}



typedef struct {
	Node *root;		// 创建出树的根结点
	int used;		// 创建过程中用掉的前序值个数
}	Result;

/*
// preorder = { ###CD }, size = 5
Result CreateTree(char preorder[], int size) {
	// 第一个终止条件
	if (size == 0) {
		// 树是空树 NULL,用了 0 个
		return (Result){ NULL, 0 };
	}

	// 第二个终止条件
	if (preorder[0] == '#') {
		// 树是空树 NULL, 用了 1 个，#
		return (Result){ NULL, 1 };
	}

	// 根
	// malloc 空间，赋值
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = preorder[0];
	// int preorder[]
	// int *preorder
	// preorder{ ABE###CD }	size = 8
	// 左子树 { BE###CD}, size = 7
	Result llll = CreateTree(preorder + 1, size - 1);
	// llll.root	创建好的左子树的根结点
	// llll.used	创建左子树过程中用掉的值的个数
	// 右子树 { CD } size = 2
	Result rrrr = CreateTree(preorder + 1 + llll.used, size - 1 - llll.used);

	root->left = llll.root;
	root->right = rrrr.root;

	return (Result) {
		root, 1 + llll.used + rrrr.used
	}
}

*/



Result CreateTree(char preorder[], int size) {
	if (size == 0) {
		Result r = { NULL, 0 };
		return r;
	}

	char rootValue = preorder[0];
	if (rootValue == '#') {
		Result r = { NULL, 1 };
		return r;
	}

	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	Result leftResult = CreateTree(preorder + 1, size - 1);
	root->left = leftResult.root;

	Result rightResult = CreateTree(
		preorder + 1 + leftResult.used, 
		size - 1 - leftResult.used);
	root->right = rightResult.root;

	Result r = { root, 1 + leftResult.used + rightResult.used };
	return r;
}

void Test2() {
	char * preorder = "ABE###CD";
	int size = strlen(preorder);

	Result r = CreateTree(preorder, size);

	printf("根的值是: %c\n", r.root->value);
}

struct Node * find(struct Node *root, struct Node *p) {
	if (root == NULL) {
		return NULL;
	}

	if (root == p) {
		return root;
	}

	struct Node *result = find(root->left, p);
	if (result != NULL) {
		return result;
	}

	return find(root->right, p);
}

struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q) {
	
	
	
	if (root == p || root == q) {
		return root;
	}

	struct Node * pInLeft = find(root->left, p);
	struct Node * qInLeft = find(root->left, q);

	if (pInLeft != NULL && qInLeft != NULL) {
		return lowestCommonAncestor(root->left, p, q);
	}

	if (pInLeft == NULL && qInLeft == NULL) {
		return lowestCommonAncestor(root->right, p, q);
	}

	return root;
}

void Test3() {
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

	Node *ancestor = lowestCommonAncestor(a, h, d);
	printf("公共祖先: %c\n", ancestor->value);
}

char * array;
int size;

// 
// char str[100];
// sprintf(str, "hello world %s\n", "peixinchen");
// str

void _tree2str(Node *root) {
	if (root == NULL) {
		return;
	}

	array[size++] = '(';
	int n = sprintf(array + size, "%c", root->value);
	size += n;
	if (root->right != NULL && root->left == NULL) {
		array[size++] = '(';
		array[size++] = ')';
	}
	else {
		// 左子树不为空 或者 右子树为空
		_tree2str(root->left);
	}
	_tree2str(root->right);
	array[size++] = ')';
}

char * tree2str(Node *root) {
	array = (char *)malloc(sizeof(char)* 100 * 10000);
	size = 0;

	if (root == NULL) {
		return array;
	}

	int n = sprintf(array + size, "%c", root->value);
	size += n;
	if (root->right != NULL && root->left == NULL) {
		array[size++] = '(';
		array[size++] = ')';
	}
	else {
		_tree2str(root->left);
	}
	_tree2str(root->right);

	array[size] = '\0';
	return array;
}


void Test4() {
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

	char *p = tree2str(a);
	printf("前序: %s\n", p);
}


#include <queue>

void LevelorderTraversal(Node *root) {
	if (root == NULL) {
		printf("\n");
	}

	std::queue<Node *>		q;
	q.push(root);

	while (!q.empty()) {
		Node *front = q.front();
		q.pop();

		printf("%c ", front->value);
		if (front->left != NULL) {
			q.push(front->left);
		}
		if (front->right != NULL) {
			q.push(front->right);
		}
	}
	printf("\n");
}



void Test5() {
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

	LevelorderTraversal(a);
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <queue>



// �ǵݹ鷽ʽʵ�ֶ������Ĳ������
// ʹ�ö���

// ����������


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

	// ���������
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = preorder[0];

	// ����������

	Result left = CreateTree(preorder + 1, size-11);   // +1��ʾ���������
	
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

	// ��ʼ���

	q.push(root);

	while (!q.empty()){
		// ȡ����Ԫ��
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
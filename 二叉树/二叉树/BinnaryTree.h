#pragma once

#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>

typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;



// 1. 创建二叉树 
BTNode* CreateBinTree(BTDataType* array, int size);

// 拷贝二叉树 
BTNode* CopyBinTree(BTNode* pRoot){

}

// 销毁二叉树 
void DestroyBinTree(BTNode** pRoot);
// 二叉树的三种遍历方式 
void PreOrder(BTNode* pRoot){
	if (pRoot == NULL){
		return;
	}

	// 根
	printf("%c", pRoot->_data);
	// 左子树
	PreOrder(pRoot->_pLeft);
	// 右子树
	PreOrder(pRoot->_pRight);
}
using std::stack;
stack <BTNode*> s;
void PreOrderNor(BTNode* pRoot){

	BTNode* cur = pRoot;
	
	while (!s.empty() || cur != NULL){
		while (cur != NULL){
			// 根
			printf("%c", cur->_data);
			// 左子树
			s.push(cur);
			cur = cur->_pLeft;
		}

		// 右子树
		BTNode* top = s.top();
		s.pop();
		cur = top->_pRight;
	}
	printf("\n");


}
void InOrder(BTNode* pRoot){
	if (pRoot == NULL){
		return;
	}

	// 左子树
	InOrder(pRoot->_pLeft);

	// 根
	printf("%c", pRoot->_data);
	// 右子树 
	InOrder(pRoot->_pRight);
}
void InOrderNor(BTNode* pRoot){
	BTNode* cur = pRoot;
	while (!s.empty() || cur != NULL){
		while (cur != NULL){
			// 左子树
			s.push(cur);
			cur = cur->_pLeft;
		}
		BTNode* top = s.top();
		s.pop();
		// 根
		printf("%c", top->_data);
		// 右子树
		cur = top->_pRight;

	}
	printf("\n");
	
}

void PostOrder(BTNode* pRoot){
	if (pRoot == NULL){
		return;
	}

	// 左子树
	PostOrder(pRoot->_pLeft);
	// 右子树
	PostOrder(pRoot->_pRight);
	// 根
	printf("%c", pRoot->_data);
}
void PostOrderNor(BTNode* pRoot){
	BTNode* cur = pRoot;
	BTNode* last = NULL;   // 上一次遍历完时的根结点

	while (!s.empty() || cur != NULL){
		while (cur != NULL){
			// 左子树
			s.push(cur);
			cur = cur->_pLeft;

		}
		BTNode* top = s.top();
		s.pop();
		// 右子树
		if (top->_pRight == NULL){
			printf("%c", top->_data);
		}
		else if (top->_pRight == last){
			printf("%c", top->_data);
		}
		else{
			cur = top->_pRight;
		}
	}
	printf("\n");

}

using std::queue;
queue <BTNode*> q;
void LevelOrder(BTNode* pRoot){
	if (pRoot == NULL){
		printf("\n");
		return;
	}

	// 入队
	q.push(pRoot);
	while (!q.empty()){
		// 取元素
		BTNode* front = q.front();
		q.pop();
		printf("%c", front->_data);

		if (front->_pLeft != NULL){
			q.push(front->_pLeft);
		}

		if (front->_pRight != NULL){
			q.push(front->_pRight);
		}

	}

	printf("\n");
}

// 获取二叉树中节点的个数 
int GetNodeCount(BTNode* pRoot){
	if (pRoot == NULL){
		return 0;
	}
	if (pRoot->_pLeft == NULL&&pRoot->_pRight == NULL){
		return 1;
	}

	int left = GetNodeCount(pRoot->_pLeft);
	int right = GetNodeCount(pRoot->_pRight);

	return left + right + 1;
}

// 求二叉树的高度 
int Height(BTNode* pRoot){
	if (pRoot == NULL){
		return 0;
	}
	if (pRoot->_pLeft == NULL&&pRoot->_pRight == NULL){
		return 1;
	}

	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);

	return (right > left ? right : left) + 1;
}

// 检测二叉树是否平衡O(N^2) 
// 左子树和右子树都为平衡树且左右子树高度差 <= 1则为平衡树
// 按照前序遍历，先求出左右子树的高度差，然后分别判断左右子树是否为平衡二叉树

int IsBalanceTree(BTNode* pRoot){
	if (pRoot == NULL){
		return 1;

	}

	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);
	
	return IsBalanceTree(pRoot->_pLeft) && IsBalanceTree(pRoot->_pRight) && (abs(left - right) >= 1);

}
// 检测二叉树是否平衡O(N) 
// 按照后序遍历，判断左右子树是否为平衡二叉树的同时记录高度
int IsBalanceTree_P(BTNode* pRoot, int* height){

	if (pRoot == NULL){
		*height = 0;
		return 1;
	}

	int left;     // 左子树高度
	int right;    // 右子树高度
	if (IsBalanceTree_P(pRoot->_pLeft, &left) || IsBalanceTree_P(pRoot->_pRight, &right)){
		int ret = left - right;
		if (ret >= 1 || ret <= -1){
			*height = left > right ? left + 1 : right + 1;
			return 1;
		}

	}
	return 0;
	
}

// 获取二叉数中叶子节点的个数 
int GetLeafNodeCount(BTNode* pRoot){
	if (pRoot == NULL){
		return 0;
	}

	if (pRoot->_pLeft == NULL&&pRoot->_pRight == NULL){
		return 1;
	}

	int left = GetLeafNodeCount(pRoot->_pLeft);
	int right = GetLeafNodeCount(pRoot->_pRight);

	return left + right;
}

// 获取二叉树第K层节点的个数 
int GetKLevelNodeCount(BTNode* pRoot, int K){
	if (pRoot == NULL){
		return 0;
	}
	if (K==1){
		return 1;
	}

	int left = GetKLevelNodeCount(pRoot->_pLeft, K - 1);
	int right = GetKLevelNodeCount(pRoot->_pRight, K - 1);

	return left + right;

}

// 获取二叉树中某个节点的双亲节点 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode){
	if (pRoot == NULL||pNode==pRoot||pNode==NULL){
		return NULL;
	}
	
	if (pNode->_pLeft != NULL || pNode->_pRight != NULL){
		return pNode;
	}


	return GetNodeParent(pRoot, pNode);

	
}

// 求二叉树的镜像 (对称）
void Mirror(BTNode* pRoot){
	if (pRoot == NULL || (pRoot->_pLeft == NULL&&pRoot->_pRight == NULL)){
		return;
	}

	BTNode* temp = pRoot->_pLeft;
	pRoot->_pLeft = pRoot->_pRight;
	pRoot->_pRight = temp;

	if (pRoot->_pLeft != NULL){
		Mirror(pRoot->_pLeft);
	}

	if (pRoot->_pRight != NULL){
		Mirror(pRoot->_pRight);
	}

}
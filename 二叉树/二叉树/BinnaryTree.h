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



// 1. ���������� 
BTNode* CreateBinTree(BTDataType* array, int size);

// ���������� 
BTNode* CopyBinTree(BTNode* pRoot){

}

// ���ٶ����� 
void DestroyBinTree(BTNode** pRoot);
// �����������ֱ�����ʽ 
void PreOrder(BTNode* pRoot){
	if (pRoot == NULL){
		return;
	}

	// ��
	printf("%c", pRoot->_data);
	// ������
	PreOrder(pRoot->_pLeft);
	// ������
	PreOrder(pRoot->_pRight);
}
using std::stack;
stack <BTNode*> s;
void PreOrderNor(BTNode* pRoot){

	BTNode* cur = pRoot;
	
	while (!s.empty() || cur != NULL){
		while (cur != NULL){
			// ��
			printf("%c", cur->_data);
			// ������
			s.push(cur);
			cur = cur->_pLeft;
		}

		// ������
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

	// ������
	InOrder(pRoot->_pLeft);

	// ��
	printf("%c", pRoot->_data);
	// ������ 
	InOrder(pRoot->_pRight);
}
void InOrderNor(BTNode* pRoot){
	BTNode* cur = pRoot;
	while (!s.empty() || cur != NULL){
		while (cur != NULL){
			// ������
			s.push(cur);
			cur = cur->_pLeft;
		}
		BTNode* top = s.top();
		s.pop();
		// ��
		printf("%c", top->_data);
		// ������
		cur = top->_pRight;

	}
	printf("\n");
	
}

void PostOrder(BTNode* pRoot){
	if (pRoot == NULL){
		return;
	}

	// ������
	PostOrder(pRoot->_pLeft);
	// ������
	PostOrder(pRoot->_pRight);
	// ��
	printf("%c", pRoot->_data);
}
void PostOrderNor(BTNode* pRoot){
	BTNode* cur = pRoot;
	BTNode* last = NULL;   // ��һ�α�����ʱ�ĸ����

	while (!s.empty() || cur != NULL){
		while (cur != NULL){
			// ������
			s.push(cur);
			cur = cur->_pLeft;

		}
		BTNode* top = s.top();
		s.pop();
		// ������
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

	// ���
	q.push(pRoot);
	while (!q.empty()){
		// ȡԪ��
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

// ��ȡ�������нڵ�ĸ��� 
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

// ��������ĸ߶� 
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

// ���������Ƿ�ƽ��O(N^2) 
// ����������������Ϊƽ���������������߶Ȳ� <= 1��Ϊƽ����
// ����ǰ���������������������ĸ߶ȲȻ��ֱ��ж����������Ƿ�Ϊƽ�������

int IsBalanceTree(BTNode* pRoot){
	if (pRoot == NULL){
		return 1;

	}

	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);
	
	return IsBalanceTree(pRoot->_pLeft) && IsBalanceTree(pRoot->_pRight) && (abs(left - right) >= 1);

}
// ���������Ƿ�ƽ��O(N) 
// ���պ���������ж����������Ƿ�Ϊƽ���������ͬʱ��¼�߶�
int IsBalanceTree_P(BTNode* pRoot, int* height){

	if (pRoot == NULL){
		*height = 0;
		return 1;
	}

	int left;     // �������߶�
	int right;    // �������߶�
	if (IsBalanceTree_P(pRoot->_pLeft, &left) || IsBalanceTree_P(pRoot->_pRight, &right)){
		int ret = left - right;
		if (ret >= 1 || ret <= -1){
			*height = left > right ? left + 1 : right + 1;
			return 1;
		}

	}
	return 0;
	
}

// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
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

// ��ȡ��������K��ڵ�ĸ��� 
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

// ��ȡ��������ĳ���ڵ��˫�׽ڵ� 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode){
	if (pRoot == NULL||pNode==pRoot||pNode==NULL){
		return NULL;
	}
	
	if (pNode->_pLeft != NULL || pNode->_pRight != NULL){
		return pNode;
	}


	return GetNodeParent(pRoot, pNode);

	
}

// ��������ľ��� (�Գƣ�
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
// 通过队列实现层序遍历二叉树

#include <stdio.h>
#include <stdlib.h>

// 二叉树结构
struct BinTree {
	char Data;
	struct BinTree* Left;
	struct BinTree* Right;
};
typedef struct BinTree* TreeNode;

// 队列结构
struct Node {
	TreeNode Data;
	struct Node* Next;
};

struct QNode {
	struct Node* front;
	struct Node* rear;
};

typedef struct QNode* Queue;

Queue CreateQueue() {
	Queue q = (Queue)malloc(sizeof(struct QNode));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

int IsEmpty(Queue q) {
	return q->front == NULL;
}

void Add(Queue q, TreeNode x) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->Next = NULL;
	node->Data = x;
	if (q->rear == NULL) {
		q->front = q->rear = node;
	}
	else {
		q->rear->Next = node;
		q->rear = node;
	}
}

TreeNode Delete(Queue q) {
	if (q->front == NULL) {
		printf("队列空\n");
		return -1;
	}
	struct Node* node = q->front;
	if (q->front == q->rear) {
		q->front = q->rear = NULL;
	}
	else {
		q->front = node->Next;
	}
	TreeNode x = node->Data;
	free(node);
	return x;
}

// 层序遍历二叉树
void LevelOrderTraversal(TreeNode root) {
	if (!root) return;
	Queue q = CreateQueue();
	Add(q, root);
	TreeNode node;
	while (!IsEmpty(q)) {
		node = Delete(q);
		printf("%c ", node->Data);
		if (node->Left) {
			Add(q, node->Left);
		}
		if (node->Right) {
			Add(q, node->Right);
		}
	}
}

// 测试代码
TreeNode CreateTreeNode(char c) {
	TreeNode node = (TreeNode)malloc(sizeof(struct BinTree));
	node->Data = c;
	node->Left = node->Right = NULL;
	return node;
}

int main() {
	TreeNode A = CreateTreeNode('A');
	TreeNode B = CreateTreeNode('B');
	TreeNode C = CreateTreeNode('C');
	TreeNode D = CreateTreeNode('D');
	TreeNode E = CreateTreeNode('E');
	TreeNode F = CreateTreeNode('F');
	TreeNode G = CreateTreeNode('G');
	TreeNode H = CreateTreeNode('H');
	TreeNode I = CreateTreeNode('I');
	A->Left = B;
	A->Right = C;
	B->Left = D;
	B->Right = F;
	F->Left = E;
	C->Left = G;
	C->Right = I;
	G->Right = H;

	printf("层序遍历测试：");
	LevelOrderTraversal(A);
	printf("\n");
}
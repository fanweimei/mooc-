/*
�����壺
��1���������뽻
��2�����˸��ڵ㣬ÿ��������ҽ���һ�������
��3��һ��N����������N-1����
���Ļ������
��1�����Ķȣ�������������
��2�����Ķȣ��������н�������Ķ���
��3��Ҷ���
��4�������
��5���ӽ��
��6���ֵܽ��
��7��·����·������
��8�����Ƚ��
��9��������
��10�����Ĳ��
��11���������
��������һ������Ľ�㼯�ϡ������գ��������ɸ����ͳ�Ϊ�������������������������ཻ�Ķ�������ɡ�
�����������
��1��б������
��2������������������������
��3����ȫ������
��Ҫ���ʣ�
��1��һ����������i����������Ϊ��2{i-1}
��2�����Ϊk�Ķ����������������Ϊ��2{k}-1
��3�����κηǿն�����T����n0��ʾҶ������,n2�Ƕ�Ϊ2�ķ�Ҷ�����������߹�ϵn0=n2+1��n0+n1+n2-1=n0*0+n1+n2*2��
������
��1���������
��2���������
��3���������
��4����α���
*/

// �ݹ��������򡢺������������
#include <stdio.h>
#include <stdlib.h>

struct BinTree {
	char Data;
	struct BinTree* Left;
	struct BinTree* Right;
};
typedef struct BinTree* TreeNode;

// ���µݹ����
// ��������������->����->�Һ���
void PreOrderTraversal(TreeNode node) {
	if (node) {
		printf("%c ", node->Data);
		PreOrderTraversal(node->Left);
		PreOrderTraversal(node->Right);
	}
}
//�����������->��->��
void InOrderTraversal(TreeNode node) {
	if (node) {
		InOrderTraversal(node->Left);
		printf("%c ", node->Data);
		InOrderTraversal(node->Right);
	}
}
// �����������->��->��
void PostOrderTraversal(TreeNode node) {
	if (node) {
		PostOrderTraversal(node->Left);
		PostOrderTraversal(node->Right);
		printf("%c ", node->Data);
	}
}

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

	printf("����������ԣ�");
	PreOrderTraversal(A);
	printf("\n");

	printf("����������ԣ�");
	InOrderTraversal(A);
	printf("\n");

	printf("����������ԣ�");
	PostOrderTraversal(A);
	printf("\n");
}
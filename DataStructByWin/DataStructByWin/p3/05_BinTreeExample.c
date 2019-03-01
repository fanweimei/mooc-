// ����������Ӧ��

#include <stdio.h>
#include <stdlib.h>

// �������ṹ
struct BinTree {
	char Data;
	struct BinTree* Left;
	struct BinTree* Right;
};
typedef struct BinTree* TreeNode;

// һ�������������Ҷ�ӽ��
void PrintLeafNode(TreeNode root) {
	if (root) {
		if (!root->Left && !root->Right) {
			printf("%c ", root->Data);
			return;
		}
		PrintLeafNode(root->Left);
		PrintLeafNode(root->Right);
	}
}
// ������������ĸ߶�
int GetBintreeHeight(TreeNode root) {
	if (root) {
		int lefth = GetBintreeHeight(root->Left);
		int righth = GetBintreeHeight(root->Right);
		return lefth > righth ? lefth + 1 : righth + 1;
	}
	return 0;
}

// ��������Ҫ���������ȷ��һ�ö�����

//���Դ���
TreeNode CreateTreeNode(char c) {
	TreeNode node = (TreeNode)malloc(sizeof(struct BinTree));
	node->Data = c;
	node->Left = node->Right = NULL;
	return node;
}

TreeNode GetTree() {
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
	return A;
}

int main() {
	TreeNode root = GetTree();

	printf("��������Ҷ�ӽ�㣺");
	PrintLeafNode(root);
	printf("\n");

	int height = GetBintreeHeight(root);
	printf("�������ĸ߶ȣ�%d\n", height);
}
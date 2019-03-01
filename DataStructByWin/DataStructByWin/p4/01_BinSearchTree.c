/*
������������
��1���ǿ������������м�ֵС��������ļ�ֵ
��2���ǿ������������м�ֵ����������ļ�ֵ
��3�������������Ƕ���������
*/

#include <stdio.h>
#include <stdlib.h>


// �������ṹ
struct BinTree {
	int Data;
	struct BinTree* Left;
	struct BinTree* Right;
};
typedef struct BinTree* TreeNode;

// �ݹ����
TreeNode Find(TreeNode tree, int x) {
	if (!tree) return NULL;
	if (tree->Data == x) return tree;
	else if (x < tree->Data) return Find(tree->Left, x);
	else return Find(tree->Right, x);
}
// �ǵݹ����
TreeNode IterFind(TreeNode tree, int x) {
	TreeNode node = tree;
	while (node) {
		if (node->Data == x) return node;
		else if (x < node->Data) node = node->Left;
		else node = node->Right;
	}
	return NULL;
}

TreeNode FindMin(TreeNode tree) {
	TreeNode node = tree;
	if (!node) return NULL;
	while (node->Left) {
		node = node->Left;
	}
	return node;
}
TreeNode FindMax(TreeNode tree) {
	TreeNode node = tree;
	if (!node) return NULL;
	while (node->Right) {
		node = node->Right;
	}
	return node;
}

TreeNode Insert(TreeNode tree, int x) {
	if (!tree) {
		tree = (TreeNode)malloc(sizeof(struct BinTree));
		tree->Data = x;
		tree->Left = tree->Right = NULL;
		return tree;
	}
	if (x < tree->Data) {
		tree->Left = Insert(tree, x);
	}
	else {
		tree->Right = Insert(tree, x);
	}
	return tree;
}

TreeNode Delete(TreeNode tree, int x) {
	if (!tree) {
		printf("Ҫɾ����Ԫ��δ�ҵ�");
		return NULL;
	}
	if (x > tree->Data) {
		tree->Right = Delete(tree, x);
	}
	else if (x < tree->Data) {
		tree->Left = Delete(tree, x);
	}
	else {
		if (tree->Left&&tree->Right) {
			TreeNode min = FindMin(tree->Right);
			tree->Data = min->Data;
			tree->Right = Delete(tree->Right, min->Data);
		}
		else {
			TreeNode tmp = tree;
			if (!tree->Left) { // ���Ϊ�գ���treeΪ��������ΪNULL
				tree = tree->Right;
			}
			if (!tree->Right) {
				tree = tree->Left;
			}
			free(tmp);
		}
	}
	return tree;
}
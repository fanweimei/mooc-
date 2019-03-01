/*
二叉搜索树：
（1）非空左子树的所有键值小于其根结点的键值
（2）非空右子树的所有键值大于其根结点的键值
（3）左右子树都是二叉搜索树
*/

#include <stdio.h>
#include <stdlib.h>


// 二叉树结构
struct BinTree {
	int Data;
	struct BinTree* Left;
	struct BinTree* Right;
};
typedef struct BinTree* TreeNode;

// 递归查找
TreeNode Find(TreeNode tree, int x) {
	if (!tree) return NULL;
	if (tree->Data == x) return tree;
	else if (x < tree->Data) return Find(tree->Left, x);
	else return Find(tree->Right, x);
}
// 非递归查找
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
		printf("要删除的元素未找到");
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
			if (!tree->Left) { // 左边为空，则tree为右子树或为NULL
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
// 二叉树遍历应用

#include <stdio.h>
#include <stdlib.h>

// 二叉树结构
struct BinTree {
	char Data;
	struct BinTree* Left;
	struct BinTree* Right;
};
typedef struct BinTree* TreeNode;

// 一：输出二叉树的叶子结点
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
// 二：求二叉树的高度
int GetBintreeHeight(TreeNode root) {
	if (root) {
		int lefth = GetBintreeHeight(root->Left);
		int righth = GetBintreeHeight(root->Right);
		return lefth > righth ? lefth + 1 : righth + 1;
	}
	return 0;
}

// 三：必须要有中序才能确定一棵二叉树

//测试代码
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

	printf("二叉树的叶子结点：");
	PrintLeafNode(root);
	printf("\n");

	int height = GetBintreeHeight(root);
	printf("二叉树的高度：%d\n", height);
}
/*
树定义：
（1）子树不想交
（2）除了根节点，每个结点有且仅有一个父结点
（3）一棵N个结点的树有N-1条边
树的基本术语：
（1）结点的度：结点的子树个数
（2）树的度：树的所有结点中最大的度数
（3）叶结点
（4）父结点
（5）子结点
（6）兄弟结点
（7）路径和路径长度
（8）祖先结点
（9）子孙结点
（10）结点的层次
（11）树的深度
二叉树：一个有穷的结点集合。若不空，则它是由根结点和称为其左子树和右子树的两个不相交的二叉树组成。
特殊二叉树：
（1）斜二叉树
（2）完美二叉树（满二叉树）
（3）完全二叉树
重要性质：
（1）一个二叉树第i层的最大结点数为：2{i-1}
（2）深度为k的二叉树有最大结点总数为：2{k}-1
（3）对任何非空二叉树T，若n0表示叶结点个数,n2是度为2的非叶结点个数，两者关系n0=n2+1（n0+n1+n2-1=n0*0+n1+n2*2）
遍历：
（1）先序遍历
（2）中序遍历
（3）后序遍历
（4）层次遍历
*/

// 递归先序、中序、后序遍历二叉树
#include <stdio.h>
#include <stdlib.h>

struct BinTree {
	char Data;
	struct BinTree* Left;
	struct BinTree* Right;
};
typedef struct BinTree* TreeNode;

// 以下递归遍历
// 先序遍历：根结点->左孩子->右孩子
void PreOrderTraversal(TreeNode node) {
	if (node) {
		printf("%c ", node->Data);
		PreOrderTraversal(node->Left);
		PreOrderTraversal(node->Right);
	}
}
//中序遍历：左->根->右
void InOrderTraversal(TreeNode node) {
	if (node) {
		InOrderTraversal(node->Left);
		printf("%c ", node->Data);
		InOrderTraversal(node->Right);
	}
}
// 后序遍历：左->右->根
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

	printf("先序遍历测试：");
	PreOrderTraversal(A);
	printf("\n");

	printf("中序遍历测试：");
	InOrderTraversal(A);
	printf("\n");

	printf("后序遍历测试：");
	PostOrderTraversal(A);
	printf("\n");
}
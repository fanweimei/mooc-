/*
平衡二叉树
（1）平衡因子：左右子树高度差
（2）空树或者任一结点左右子树高度差绝对值小于1
（3）平衡二叉树的调整
	- RR旋转
	- LL旋转
	- LR旋转
	- RL旋转
*/
typedef struct AVLNode* AVLTree;
struct AVLNode {
	char Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int GetHeight(AVLTree tree) {
	if (!tree) return 0;
	return tree->Height;
}
int Max(int a, int b) {
	return a > b ? a : b;
}
AVLTree LLRotation(AVLTree A) {
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;
	return B;
}

AVLTree LRRotation(AVLTree A) {
	AVLTree B = A->Left;
	AVLTree C = B->Right;
}
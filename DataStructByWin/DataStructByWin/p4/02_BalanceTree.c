/*
ƽ�������
��1��ƽ�����ӣ����������߶Ȳ�
��2������������һ������������߶Ȳ����ֵС��1
��3��ƽ��������ĵ���
	- RR��ת
	- LL��ת
	- LR��ת
	- RL��ת
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
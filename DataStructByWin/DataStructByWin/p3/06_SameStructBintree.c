/*
给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。
现在给定两棵树，请判断他们是否是同构的。
输入格式：输入给出2棵二叉树的信息：
（1）先在一行中给出该树的结点数，随后N行
（2）第i行对应编号第i个结点，给出该结点中存储的字母、其左孩子结点的编号、右孩子结点的编号。
（3）如果孩子结点为空，则在相应位置上给出"-"
输入样例：
8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - - 
A 5 1
H - -
C 0 -
D - -
E 2 -
*/

/*求解思路
（1）二叉树表示
（2）建二叉树
（3）同构判别
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

struct TreeNode {
	char Data;
	int Left;
	int Right;
};

// 构建二叉树
int BuildTree(struct TreeNode T[]) {
	int N;
	scanf_s("%d\n", &N);
	if (N <= 0) return -1;
	char L, R;
	int *check = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		check[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		if (i == N - 1) { // 最后一行不能加\n，不然需要多输入一个字符
			scanf_s("%c %c %c", &T[i].Data, 1, &L, 1, &R, 1);
		}
		else {
			scanf_s("%c %c %c\n", &T[i].Data, 1, &L, 1, &R, 1);
		}
		if (L != '-') {
			T[i].Left = L - '0';
			check[T[i].Left] = 1;
		}
		else {
			T[i].Left = -1;
		}
		if (R != '-') {
			T[i].Right = R - '0';
			check[T[i].Right] = 1;
		}
		else {
			T[i].Right = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) return i;
	}
	return -1;
}

// 判断是否是同构
int IsomeOrphic(struct TreeNode T1[], int root1, struct TreeNode T2[], int root2) {
	if (root1 == -1 && root2 == -1) return 1;
	if ((root1 == -1 && root2 != -1) || (root1 != -1 && root2 == -1)) return 0;
	if (T1[root1].Data != T2[root2].Data) return 0;
	if (T1[root1].Left == -1 && T2[root2].Left == -1) {
		return IsomeOrphic(T1, T1[root1].Right, T2, T2[root2].Right);
	}
	if ((T1[root1].Left != -1 && T2[root2].Left != -1) && (T1[T1[root1].Left].Data == T2[T2[root2].Left].Data)) {
		return IsomeOrphic(T1, T1[root1].Left, T2, T2[root2].Left) && IsomeOrphic(T1, T1[root1].Right, T2, T2[root2].Right);
	}
	else {
		return IsomeOrphic(T1, T1[root1].Left, T2, T2[root2].Right) && IsomeOrphic(T1, T1[root1].Right, T2, T2[root2].Left);
	}
}

void PrintTree(struct TreeNode T[], int root) {
	if (root != -1) {
		printf("%c ", T[root].Data);
		PrintTree(T, T[root].Left);
		PrintTree(T, T[root].Right);
	}
}

int main() {
	struct TreeNode T1[MaxSize];
	struct TreeNode T2[MaxSize];
	printf("请输入参数：\n");
	int root1 = BuildTree(T1);
	printf("打印T1：");
	PrintTree(T1, root1);
	printf("\n");

	printf("请输入T2的参数：\n");
	int root2 = BuildTree(T2);
	printf("打印T2：");
	PrintTree(T2, root2);
	printf("\n");

	int same = IsomeOrphic(T1, root1, T2, root2);
	printf("是否是同构：%d\n", same);
}
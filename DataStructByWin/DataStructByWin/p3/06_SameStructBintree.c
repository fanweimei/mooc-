/*
����������T1��T2�����T1����ͨ�����ɴ����Һ��ӻ����ͱ��T2�������ǳ��������ǡ�ͬ�����ġ�
���ڸ��������������ж������Ƿ���ͬ���ġ�
�����ʽ���������2�ö���������Ϣ��
��1������һ���и��������Ľ���������N��
��2����i�ж�Ӧ��ŵ�i����㣬�����ý���д洢����ĸ�������ӽ��ı�š��Һ��ӽ��ı�š�
��3��������ӽ��Ϊ�գ�������Ӧλ���ϸ���"-"
����������
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

/*���˼·
��1����������ʾ
��2����������
��3��ͬ���б�
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

struct TreeNode {
	char Data;
	int Left;
	int Right;
};

// ����������
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
		if (i == N - 1) { // ���һ�в��ܼ�\n����Ȼ��Ҫ������һ���ַ�
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

// �ж��Ƿ���ͬ��
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
	printf("�����������\n");
	int root1 = BuildTree(T1);
	printf("��ӡT1��");
	PrintTree(T1, root1);
	printf("\n");

	printf("������T2�Ĳ�����\n");
	int root2 = BuildTree(T2);
	printf("��ӡT2��");
	PrintTree(T2, root2);
	printf("\n");

	int same = IsomeOrphic(T1, root1, T2, root2);
	printf("�Ƿ���ͬ����%d\n", same);
}
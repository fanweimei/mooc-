// �ǵݹ�������������������

#include <stdio.h>
#include <stdlib.h>

// �������ṹ
struct BinTree {
	char Data;
	struct BinTree* Left;
	struct BinTree* Right;
};
typedef struct BinTree* TreeNode;

struct Stack {
	TreeNode Data;
	struct Stack* Next;
};

//ջ�ṹ
struct Stack* CreateStack() {
	struct Stack* Ptrs = (struct Stack*)malloc(sizeof(struct Stack));
	Ptrs->Next = NULL;
	return Ptrs;
}

int IsEmpty(struct Stack* Ptrs) {
	return Ptrs->Next == NULL;
}

void Push(struct Stack* Ptrs, TreeNode x) {
	struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
	s->Data = x;
	s->Next = Ptrs->Next;
	Ptrs->Next = s;
}

TreeNode Pop(struct Stack* Ptrs) {
	if (IsEmpty(Ptrs)) {
		printf("ջ��");
		return NULL;
	}
	struct Stack* node = Ptrs->Next;
	TreeNode data = node->Data;
	Ptrs->Next = node->Next;
	free(node);
	return data;
}

// �ǵݹ����

// ��������ǵݹ�
void PreOrderTraversal(TreeNode Node) {
	struct Stack* Stack = CreateStack();
	TreeNode T = Node;
	while (T || !IsEmpty(Stack)) {
		while (T) {
			printf("%c ", T->Data);
			Push(Stack, T);
			T = T->Left;
		}
		if (!IsEmpty(Stack)) {
			T = Pop(Stack);
			T = T->Right;
		}
	}
}
// ��������ǵݹ�
void InOrderTraversal(TreeNode Node) {
	struct Stack* Stack = CreateStack();
	TreeNode T = Node;
	while (T || !IsEmpty(Stack)) {
		while (T) {
			Push(Stack, T);
			T = T->Left;
		}
		if (!IsEmpty(Stack)) {
			T = Pop(Stack);
			printf("%c ", T->Data);
			T = T->Right;
		}
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
}
//����������ʽ��ӡ����

#include <stdio.h>
#include <stdlib.h>

// ��ʽ����
struct Node {
	int coef;
	int exp;
	struct Node* Next;
};
struct QNode {
	struct Node* front;
	struct Node* rear;
};

typedef struct QNode* Queue;
//��������
Queue CreateQueue() {
	Queue q = (Queue)malloc(sizeof(struct QNode));
	q->front = NULL;
	q->rear = NULL;
	return q;
}
//�����½��
struct Node* CreateNode(int coef, int exp) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->Next = NULL;
	node->coef = coef;
	node->exp = exp;
	return node;
}
//ֱ���ڶ�β����
void Add(Queue q, int coef, int exp) {
	struct Node* node = CreateNode(coef, exp);
	if (q->rear == NULL) {
		q->front = q->rear = node;
	}
	else {
		q->rear->Next = node;
		q->rear = node;
	}
}


int Delete(Queue q) {
	if (q->front == NULL) {
		printf("���п�\n");
		return 0;
	}
	struct Node* node = q->front;
	if (q->front == q->rear) {
		q->front = q->rear = NULL;
	}
	else {
		q->front = node->Next;
	}
	free(node);
	return 1;

}

//��������ʽ
Queue CreatePolynomial() {
	Queue q = CreateQueue();
	int n, c, e;
	scanf_s("%d", &n); // �ȶ�������
	while (n--) {
		scanf_s("%d %d", &c, &e); //����ÿһ���ϵ����ָ��
		Add(q, c, e);
	}
	return q;
}

// ����ʽ���
Queue PolyAdd(Queue p1, Queue p2) {
	Queue q = CreateQueue();
	struct Node* f1 = p1->front;
	struct Node* f2 = p2->front;
	while (f1!=NULL && f2!=NULL) {
		if (f1->exp > f2->exp) {
			Add(q, f1->coef, f1->exp);
			f1 = f1->Next;
		}
		else if (f1->exp < f2->exp) {
			Add(q, f2->coef, f2->exp);
			f2 = f2->Next;
		}
		else {
			int coef = f1->coef + f2->coef;
			if (coef != 0) {
				Add(q, coef, f1->exp);
			}
			f1 = f1->Next;
			f2 = f2->Next;
		}
	}

	while (f1 != NULL) {
		Add(q, f1->coef, f1->exp);
		f1 = f1->Next;
	}
	while (f2 != NULL) {
		Add(q, f2->coef, f2->exp);
		f2 = f2->Next;
	}
	return q;
}
//�ҵ�ĳ��λ�ò���
void AddByMul(Queue q, int coef, int exp) {
	struct Node* cur = q->front;
	struct Node* prev = cur;
	struct Node* node;
	while (cur && cur->exp > exp) {
		prev = cur;
		cur = cur->Next;
	}
	if (!cur) { // �ҵ����һ��
		node = CreateNode(coef, exp);
		q->rear = node;
		if (prev) { //�Ŷ�q�ǲ��ǿն���
			prev->Next = node;
		}
		else {
			q->front = node;
		}
		return;
	}
	if (cur->exp == exp) { //�������ָ�����
		int c = cur->coef + coef; //��ϵ��������
		if (c) { //ϵ����Ϊ0
			cur->coef = c;
			return;
		}
		 //ϵ��Ϊ0����cur���ɾ��
		if (prev) { //�Ƿ�ɾ���ĵ�һ�����
			prev->Next = cur->Next;
		}
		else {
			q->front = cur->Next;
		}
		// �Ƿ�ɾ�����һ�����
		if (cur == q->rear) {
			q->rear = prev;
		}
		free(cur);
		return;
	}
	//���ϵ������cur��С��prev
	node = CreateNode(coef, exp);
	node->Next = cur;
	if (prev) { // cur�Ƿ��ǵ�һ�����
		prev->Next = node;
	}
	else {
		q->front = node;
	}
}

// ����ʽ���
Queue PolyMul(Queue p1, Queue p2) {
	Queue q = CreateQueue();
	struct Node* f1 = p1->front;
	struct Node* f2 = p2->front;
	int coef, exp;
	while (f1) {
		while (f2) {
			coef = f1->coef*f2->coef;
			exp = f1->exp + f2->exp;
			AddByMul(q, coef, exp);
			f2 = f2->Next;
		}
		f1 = f1->Next;
		f2 = p2->front;
	}
	return q;
}

void Print(Queue q) {
	struct Node* node = q->front;
	while (node!=NULL) {
		printf("%dx{%d}+", node->coef, node->exp);
		node = node->Next;
	}
	printf("\n");
}

int main() {
	printf("���������ʽһ��ϵ����ָ����\n");
	Queue p1 = CreatePolynomial();
	/*int coef[5] = { 3, 4, -1, 2, -1 };
	int exp[5] = { 5, 4, 3, 1, 0 };*/
	
	/*int coef2[6] = { 2, 1, -7, 1 };
	int exp2[4] = { 4,3,2,1 };*/
	printf("���������ʽ����ϵ����ָ����\n");
	Queue p2 = CreatePolynomial();
	printf("��������ʽ�ֱ�Ϊ��\n");
	Print(p1);
	Print(p2);

	Queue addQ = PolyAdd(p1, p2);
	printf("����ʽ��ӣ�\n");
	Print(addQ);

	Queue mulQ = PolyMul(p1, p2);
	printf("����ʽ��ˣ�\n");
	Print(mulQ);
}
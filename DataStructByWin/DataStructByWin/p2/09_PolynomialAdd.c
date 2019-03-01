//求两个多项式相加、相乘

#include <stdio.h>
#include <stdlib.h>

// 链式队列
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
//创建队列
Queue CreateQueue() {
	Queue q = (Queue)malloc(sizeof(struct QNode));
	q->front = NULL;
	q->rear = NULL;
	return q;
}
//创建新结点
struct Node* CreateNode(int coef, int exp) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->Next = NULL;
	node->coef = coef;
	node->exp = exp;
	return node;
}
//直接在队尾插入
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
		printf("队列空\n");
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

//创建多项式
Queue CreatePolynomial() {
	Queue q = CreateQueue();
	int n, c, e;
	scanf_s("%d", &n); // 先读入项数
	while (n--) {
		scanf_s("%d %d", &c, &e); //读入每一项的系数、指数
		Add(q, c, e);
	}
	return q;
}

// 多项式相加
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
//找到某个位置插入
void AddByMul(Queue q, int coef, int exp) {
	struct Node* cur = q->front;
	struct Node* prev = cur;
	struct Node* node;
	while (cur && cur->exp > exp) {
		prev = cur;
		cur = cur->Next;
	}
	if (!cur) { // 找到最后一项
		node = CreateNode(coef, exp);
		q->rear = node;
		if (prev) { //排队q是不是空队列
			prev->Next = node;
		}
		else {
			q->front = node;
		}
		return;
	}
	if (cur->exp == exp) { //如果两个指数相等
		int c = cur->coef + coef; //将系数加起来
		if (c) { //系数不为0
			cur->coef = c;
			return;
		}
		 //系数为0，把cur结点删除
		if (prev) { //是否删除的第一个结点
			prev->Next = cur->Next;
		}
		else {
			q->front = cur->Next;
		}
		// 是否删除最后一个结点
		if (cur == q->rear) {
			q->rear = prev;
		}
		free(cur);
		return;
	}
	//如果系数大于cur，小于prev
	node = CreateNode(coef, exp);
	node->Next = cur;
	if (prev) { // cur是否是第一个结点
		prev->Next = node;
	}
	else {
		q->front = node;
	}
}

// 多项式相乘
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
	printf("请输入多项式一的系数和指数：\n");
	Queue p1 = CreatePolynomial();
	/*int coef[5] = { 3, 4, -1, 2, -1 };
	int exp[5] = { 5, 4, 3, 1, 0 };*/
	
	/*int coef2[6] = { 2, 1, -7, 1 };
	int exp2[4] = { 4,3,2,1 };*/
	printf("请输入多项式二的系数和指数：\n");
	Queue p2 = CreatePolynomial();
	printf("两个多项式分别为：\n");
	Print(p1);
	Print(p2);

	Queue addQ = PolyAdd(p1, p2);
	printf("多项式相加：\n");
	Print(addQ);

	Queue mulQ = PolyMul(p1, p2);
	printf("多项式相乘：\n");
	Print(mulQ);
}
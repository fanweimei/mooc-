// 队列的链式存储结构实现

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int Data;
	struct Node* Next;
};

struct QNode {
	struct Node* front;
	struct Node* rear;
};

typedef struct QNode* Queue;

Queue CreateQueue() {
	Queue q = (Queue)malloc(sizeof(struct QNode));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

void Add(Queue q, int x) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->Next = NULL;
	node->Data = x;
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
		return -1;
	}
	struct Node* node = q->front;
	if (q->front == q->rear) {
		q->front = q->rear = NULL;
	}
	else {
		q->front = node->Next;
	}
	int x = node->Data;
	free(node);
	return x;
}

int main() {
	Queue q = CreateQueue();
	Delete(q);
	Add(q, 10);
	int x = Delete(q);
	printf("%d\n", x);
	Delete(q);
	Add(q, 20);
	Add(q, 30);
	Add(q, 40);
	x = Delete(q);
	printf("%d\n", x);
}
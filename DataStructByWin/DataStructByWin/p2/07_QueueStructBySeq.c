// ���е�˳��洢ʵ��

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

struct QNode {
	int Data[MAXSIZE];
	int rear;
	int front;
};
typedef struct QNode * Queue;

Queue CreateQueue() {
	Queue queue = (Queue)malloc(sizeof(struct QNode));
	queue->rear = 0;
	queue->front = 0;
}

/*
��1�������MAXSIZE-1��Ԫ�أ�����rear==front��ʱ���޷��ж��ǿջ�����
	- ��Ϊrear��front�Ĳ�ֵ��n�����������װ�ص�ֵ��n+1����������Բ�����
��2��������QNode�ṹ��������һ��size��¼��ǰ�����е�Ԫ�ظ���
*/
int IsFull(Queue q) {
	return (q->rear + 1) % MAXSIZE == q->front; 
}
int IsEmpty(Queue q) {
	return q->front == q->rear;
}
void Add(Queue q, int x) {
	if (IsFull(q)) {
		printf("������\n");
		return;
	}
	q->rear = (q->rear + 1) % MAXSIZE;
	q->Data[q->rear] = x;
}

int Delete(Queue q) {
	if (IsEmpty(q)) {
		printf("���п�");
		return -1;
	}
	q->front = (q->front + 1) % MAXSIZE;
	return q->Data[q->front];
}

int main() {
	Queue q = CreateQueue();
	Add(q, 1);
	Add(q, 2);
	Add(q, 3);
	Add(q, 4);
	Add(q, 5);
	Add(q, 6);
	Add(q, 7);
	Add(q, 8);
	Add(q, 9);
	Add(q, 10);
	Add(q, 11);

	int n;
	while ((n = Delete(q)) != -1) {
		printf("%d ", n);
	}
	printf("\n");
}
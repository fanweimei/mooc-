// 队列的顺序存储实现

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
（1）最多存放MAXSIZE-1个元素，否则当rear==front的时候无法判断是空还是满
	- 因为rear和front的差值有n种情况，但是装载的值有n+1中情况，所以不可以
（2）或者在QNode结构中再增加一个size记录当前队列中的元素个数
*/
int IsFull(Queue q) {
	return (q->rear + 1) % MAXSIZE == q->front; 
}
int IsEmpty(Queue q) {
	return q->front == q->rear;
}
void Add(Queue q, int x) {
	if (IsFull(q)) {
		printf("队列满\n");
		return;
	}
	q->rear = (q->rear + 1) % MAXSIZE;
	q->Data[q->rear] = x;
}

int Delete(Queue q) {
	if (IsEmpty(q)) {
		printf("队列空");
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
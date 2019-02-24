//
//  StackSeqExample1.c
//  DataStructure
//  栈的顺序存储案例
// 题目：请用一个数组实现两个堆栈，要求最大地利用数组空间，使数组只要有空间入栈操作就可以成功
//  Created by 范伟梅 on 2019/2/24.
//  Copyright © 2019 范伟梅. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

struct Stack {
    int Data[MAXSIZE];
    int Top1;
    int Top2;
};

struct Stack* CtreateStack() {
    struct Stack* Ptrs = (struct Stack*)malloc(sizeof(struct Stack));
    Ptrs->Top1 = -1;
    Ptrs->Top2 = MAXSIZE;
    return Ptrs;
}

int IsFull(struct Stack* Ptrs) {
    return Ptrs->Top2 - Ptrs->Top1 == 1 ? 1 : 0;
}

int IsEmpty(struct Stack* Ptrs, int tag) {
    if((tag == 1 && Ptrs->Top1==-1) || (tag == 2 && Ptrs->Top2 == MAXSIZE)) return 1;
    return 0;
}

void Push(struct Stack* Ptrs, int x, int tag) {
    if(IsFull(Ptrs)) {
        printf("已满");
        return;
    }
    if(tag == 1) {
        Ptrs->Data[++Ptrs->Top1] = x;
    } else {
        Ptrs->Data[--Ptrs->Top2] = x;
    }
}

int Pop(struct Stack* Ptrs, int tag) {
    if(IsEmpty(Ptrs, tag)) {
        printf("栈空");
        return -1;
    }
    if(tag==1) {
        return Ptrs->Data[Ptrs->Top1--];
    } else {
        return Ptrs->Data[Ptrs->Top2++];
    }
}

int main() {
    struct Stack* stack = CtreateStack();
    Push(stack, 10, 1);
    Push(stack, 20, 2);
    Push(stack, 30, 1);
    Push(stack, 50, 1);
    Push(stack, 100, 2);
    printf("%d ", Pop(stack, 1));
    printf("%d ", Pop(stack, 1));
    printf("%d ", Pop(stack, 1));
    printf("%d ", Pop(stack, 2));
};

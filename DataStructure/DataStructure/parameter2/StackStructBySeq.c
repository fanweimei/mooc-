//
//  StackStructBySeq.c
//  DataStructure
//  栈的顺序存储结构
//  Created by 范伟梅 on 2019/2/24.
//  Copyright © 2019 范伟梅. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

struct Stack {
    int Data[MAXSIZE];
    int Top;
};

struct Stack* CtreateStack() {
    struct Stack* Ptrs = (struct Stack*)malloc(sizeof(struct Stack));
    Ptrs->Top = -1;
    return Ptrs;
}

int IsFull(struct Stack* Ptrs) {
    return Ptrs->Top >= MAXSIZE-1 ? 1 : 0;
}

int IsEmpty(struct Stack* Ptrs) {
    return Ptrs->Top < 0 ? 1 : 0;
}

void Push(struct Stack* Ptrs, int x) {
    if(IsFull(Ptrs)) {
        printf("已满");
        return;
    }
    Ptrs->Top++;
    Ptrs->Data[Ptrs->Top] = x;
}

int Pop(struct Stack* Ptrs) {
    if(IsEmpty(Ptrs)) {
        printf("栈空");
        return -1;
    }
    int x = Ptrs->Data[Ptrs->Top];
    Ptrs->Top--;
    return x;
}

int main() {
    struct Stack* stack = CtreateStack();
    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);
    printf("%d ", Pop(stack));
    printf("%d ", Pop(stack));
    printf("%d ", Pop(stack));
    printf("%d ", Pop(stack));
};

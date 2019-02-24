//
//  StackStructByLink.c
//  DataStructure
//  栈的链式存储结构：只在栈顶push、pop数据
//  Created by 范伟梅 on 2019/2/24.
//  Copyright © 2019 范伟梅. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void CountCexpression(char str[]);

struct Stack {
    int Data;
    struct Stack* Next;
};

struct Stack* CreateStack() {
    struct Stack* Ptrs = (struct Stack*)malloc(sizeof(struct Stack));
    Ptrs->Next = NULL;
    return Ptrs;
}

int IsEmpty(struct Stack* Ptrs) {
    return Ptrs->Next == NULL;
}

void Push(struct Stack* Ptrs, int x) {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->Data = x;
    s->Next = Ptrs->Next;
    Ptrs->Next = s;
}

int Pop(struct Stack* Ptrs) {
    if(IsEmpty(Ptrs)) {
        printf("栈空");
        return -1;
    }
    struct Stack* node = Ptrs->Next;
    int data = node->Data;
    Ptrs->Next = node->Next;
    free(node);
    return data;
}

int main() {
//    struct Stack* stack = CreateStack();
//    Push(stack, 10);
//    Push(stack, 20);
//    Push(stack, 30);
//    printf("%d ", Pop(stack));
//    printf("%d ", Pop(stack));
//    printf("%d ", Pop(stack));
//    printf("%d ", Pop(stack));
    CountCexpression("2+9/3-5");
}

//中缀表达式求值
void CountCexpression(char str[]) {
    long len = strlen(str);
    char ss[len];
    for(int i=0; i<len; i++) {
        char c = str[i];
        ss[i] = c;
    }
    printf(ss);
}

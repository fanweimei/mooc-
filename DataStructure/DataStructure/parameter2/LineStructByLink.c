//
//  LineStructByLink.c
//  DataStructure
// 线性表的链式存储结构
//  Created by 范伟梅 on 2019/2/24.
//  Copyright © 2019 范伟梅. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct LNode {
    int Data;
    struct LNode* Next;
};

// 求链表长度
int Length(struct LNode* Ptrl) {
    int j = 0;
    struct LNode* p = Ptrl;
    while(p != NULL) {
        j++;
        p = p->Next;
    }
    return j;
}

//根据索引号查找结点
struct LNode* FindByIndex(int i, struct LNode* Ptrl) {
    int j=1;
    struct LNode* p = Ptrl;
    while(p !=NULL && j<i) {
        j++;
        p = p->Next;
    }
    if(j!=i) return NULL;
    return p;
}

//根据值查找结点
struct LNode* FindByValue(int x, struct LNode* Ptrl) {
    struct LNode* p = Ptrl;
    while(p!=NULL && p->Data != x) {
        p = p->Next;
    }
    return p;
}

//在i位置插入值为x的结点
struct LNode* Insert(int x, int i, struct LNode* Ptrl) {
    struct LNode* node = (struct LNode*)malloc(sizeof(struct LNode));
    node->Data = x;
    if(i==1) {
        node->Next = Ptrl;
        return node;
    }
    struct LNode* p = FindByIndex(i-1, Ptrl);
    if(p == NULL) {
        printf("参数错误:%d", i);
        return NULL;
    }
    node->Next = p->Next;
    p->Next = node;
    return Ptrl;
}

//删除i位置的结点
struct LNode* Delete(int i, struct LNode* Ptrl) {
    struct LNode* p;
    struct LNode* s;
    if(i==1) {
        if(Ptrl == NULL) return NULL;
        s = Ptrl;
        Ptrl = Ptrl->Next;
        free(s);
        return Ptrl;
    }
    p = FindByIndex(i-1, Ptrl);
    if(p == NULL||p->Next==NULL) {
        printf("第%d个结点不存在", i);
        return NULL;
    }
    s = p->Next;
    p->Next = s->Next;
    free(s);
    return Ptrl;
}

void Print(struct LNode* Ptrl) {
    struct LNode* p = Ptrl;
    while(p!=NULL) {
        printf("%d ", p->Data);
        p= p->Next;
    }
    printf("\n");
}

int main() {
    struct LNode* Ptrl = NULL;
    Ptrl = Insert(10, 1, Ptrl);
    Ptrl = Insert(5, 1, Ptrl);
    Ptrl = Insert(60, 3, Ptrl);
    Ptrl = Insert(50, 3, Ptrl);
    struct LNode* p = FindByValue(10, Ptrl);
    printf("%d\n", p->Data);
    Print(Ptrl);
    Ptrl = Delete(2, Ptrl);
    Print(Ptrl);
}

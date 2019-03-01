//
//  LineStuctBySeq.c
//  DataStructure
// 线性表的顺序存储结构
//  Created by 范伟梅 on 2019/2/23.
//  Copyright © 2019 范伟梅. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

struct LNode {
    int Data[MAXSIZE];
    int Last;
};

// 创建空表
struct LNode * MakeEmpty() {
    struct LNode * Ptrl = (struct LNode *)malloc(sizeof(struct LNode));
    Ptrl->Last = -1;
    return Ptrl;
}

// 查找元素为x的位置
int Find(int x, struct LNode* Ptrl) {
    int i = 0;
    while(i<=Ptrl->Last && Ptrl->Data[i]!=x) {
        i++;
    }
    if(i>Ptrl->Last) return -1;
    return i;
}

//在第i个位置插入元素x
void Insert(int x, int i, struct LNode* Ptrl) {
    if(Ptrl->Last > MAXSIZE) {
        printf("已满");
        return;
    }
    if(i<1 || i>Ptrl->Last+2) {
        printf("插入位置不合适");
        return;
    }

    for(int j=Ptrl->Last; j>=i-1; j--) {
        Ptrl->Data[j+1] = Ptrl->Data[j];
    }
    Ptrl->Data[i-1] = x;
    Ptrl->Last++;
}

// 删除第i个位置的元素
void Delete(int i, struct LNode* Ptrl) {
    if(i<1 || i > Ptrl->Last+1) {
        printf("不存在第%d个味素", i);
        return;
    }
    for(int j=i-1; j<Ptrl->Last; j++) {
        Ptrl->Data[j] = Ptrl->Data[j+1];
    }
    Ptrl->Last--;
}

//打印
void Print(struct LNode* Ptrl) {
    for(int i=0; i<=Ptrl->Last; i++) {
        printf("%d ", Ptrl->Data[i]);
    }
    printf("\n");
}

int main() {
    struct LNode * List = MakeEmpty();
    Insert(10, 1, List);
    Insert(6, 1, List);
    Insert(18, 3, List);
    Insert(20, 3, List);
    Insert(50, 5, List);
    
    int x = Find(18, List);
    printf("%d\n", x);
    Print(List);
    Delete(1, List);
    Print(List);
}

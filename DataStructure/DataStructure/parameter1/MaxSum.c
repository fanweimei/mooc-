//
//  MaxSum.c
//  DataStructure
// 求一个数组最大的子数组之和，提供了三种方法
//  Created by 范伟梅 on 2019/2/23.
//  Copyright © 2019 范伟梅. All rights reserved.
//

#include <stdio.h>

int MaxSubseqSum1(int A[], int N) {
    int temp, max = 0;
    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            temp = 0;
            for(int k=i; k<=j; k++) {
                temp += A[k];
                if(temp > max) {
                    max = temp;
                }
            }
        }
    }
    return max;
}

int MaxSubseqSum2(int A[], int N) {
    int temp, max = 0;
    for(int i=0; i<N; i++) {
        temp = 0;
        for(int j=i; j<N; j++) {
            temp += A[j];
            if(temp > max) {
                max = temp;
            }
        }
    }
    return max;
}

int MaxSubseqSum3(int A[], int N) {
    int temp = 0, max = 0;
    for(int i=0; i<N; i++) {
        temp += A[i];
        if(temp > max) {
            max = temp;
        } else if(temp < 0) {
            temp = 0;
        }
    }
    return max;
}

int main() {
    int A[10] = {10, 20, -1,-10, 30, -40, 50, -2,20, -1};
    int max = MaxSubseqSum3(A, 10);
    printf("%d\n", max);
    return 0;
}

/*
二分查找算法
前提：集合是有序的
*/

#include <stdio.h>
#include <stdlib.h>

int Search(int array[], int n, int x) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (array[mid] < x) {
			left = mid + 1;
		}
		else if (array[mid] > x) {
			right = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int main() {
	int array[10] = { 1, 4, 6, 10, 88, 99, 100, 101, 120, 999 };
	int index = Search(array, 10, 6);
	printf("%d\n", index);
}
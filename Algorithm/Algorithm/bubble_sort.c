//
//  bubble_sort.c
//  冒泡排序
//
//  Created by ronglei on 14-6-20.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "algorithm.h"

// 冒泡排序
// 每次遍历数组找到最大或最小的放到特定位置,然后一次类推知道最后一个数
void swap(int *x, int *y);
void print(int array[], int length);

int bubble_sort_pointer(int array[], int length)
{
    if (NULL == array || 0 == length) {
        printf("params error!\n");
        return -1;
    }
    printf("bfore:\n");
    print(array, length);
    
    int *p = array;
    for (int i = 0; i < length - 1; i ++, p ++) {
        int *q = p + 1;
        for (int j = i + 1; j < length; j ++, q ++) {
            if (*p < *q) {
                swap(p, q);
            }
        }
    }
    
    printf("after:\n");
    print(array, length);
    return 0;
}

int bubble_sort(int array[], int length)
{
    if (NULL == array || 0 == length) {
        printf("params error!\n");
        return -1;
    }
    printf("bfore:\n");
    print(array, length);
    
    int i = 0;
    int j = 0;
    int mid_data = 0;
    
    for (i = 0; i < length - 1; i ++) {
        for (j = i + 1; j < length; j ++) {
            if (array[i] < array[j]) {
                mid_data = array[i];
                array[i] = array[j];
                array[j] = mid_data;
            }
        }
    }
    
    printf("after:\n");
    print(array, length);
    return 0;
}

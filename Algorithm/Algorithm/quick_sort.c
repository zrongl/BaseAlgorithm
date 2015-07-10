//
//  quick_sort.c
//  快速排序
//
//  Created by ronglei on 14-6-23.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "algorithm.h"

static int gQuickSort[] = {};

int get_middle(int array[], int start, int end);

// 快速排序
int quick_sort(int array[], int start, int end)
{
    int middle;
    if (array == NULL || start >= end) {
        printf("params error\n");
        return -1;
    }
    
    middle = get_middle(array, start, end);
    quick_sort(array, start, middle-1);
    quick_sort(array, middle+1, end);
    
    return 0;
}

int get_middle(int array[], int start, int end)
{
    int value = array[start];
    int *loop = array + 1;
    int length = end - start + 1;
    int front = 0;
    int tail = end - start;
    
    while (front < length/2) {
        if (*loop < value) {
            gQuickSort[front] = *loop;
            front ++;
        }else if(*loop > value){
            gQuickSort[tail] = *loop;
            tail --;
        }
        loop ++;
    }
    
    gQuickSort[front] = value;
    memcpy(&array[start], gQuickSort, sizeof(int)*length);
    
    return (start + front);
}

//
//  sorting.c
//  Algorithm
//
//  Created by ronglei on 15/9/11.
//  Copyright (c) 2015年 ronglei. All rights reserved.
//

#include "sorting.h"
#include "helper.h"

/*
 * 冒泡排序
 **/

// 冒泡排序
// 每次遍历数组找到最大或最小的放到特定位置,然后一次类推知道最后一个数
/**
 *  冒泡排序
 *
 *
 *  @param array  待排序数组
 *  @param length 数组长度
 *
 *  @return 排序是否成功
 */
int bubble_sort_pointer(int array[], int length)
{
    if (NULL == array || 0 == length) {
        printf("params error!\n");
        return -1;
    }
    printf("bfore:\n");
    print_array(array);
    
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
    print_array(array);
    
    return 0;
}

int bubble_sort(int array[], int length)
{
    if (NULL == array || 0 == length) {
        printf("params error!\n");
        return -1;
    }
    printf("bfore:\n");
    print_array(array);
    
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
    print_array(array);
    return 0;
}

/**************************************/

//插入排序
int insert_sort(int array[], int length)
{
    if (NULL == array && 0 == length) {
        printf("params error!\n");
        return -1;
    }
    
    printf("bfore:\n");
    print_array(array);
    
    int i = 0;
    int j = 0;
    int mid_data = 0;
    
    for (i = 0; i < length - 1; i ++) {
        for (j = i + 1; j > 0; j --) {
            if (array[j] > array[j-1]) {
                mid_data = array[j];
                array[j] = array[j-1];
                array[j-1] = mid_data;
            }else break;
        }
    }
    
    printf("after:\n");
    print_array(array);
    
    return 0;
}

/**************************************/

//归并排序
int merger_sort(int array[], int start, int end)
{
    if ((start + 1) < end) {
        int mid = (start+end)/2;
        merger(array, start, mid);
        merger(array, mid, end);
        merger_sort(array, start, end);
    }
    
    return 0;
}

int merger(int array[], int start, int end)
{
    int length = end-start+1;
    int mid = end - start + 1;
    int *temp = malloc(sizeof(int)*length);
    
    int idx_a = start;
    int idx_b = mid;
    int loop = 0;
    
    
    while (idx_a < mid && idx_b < end) {
        if (array[idx_a] < array[idx_a]) {
            temp[loop] = array[idx_a];
            idx_a ++;
        }else{
            temp[loop] = array[idx_b];
            idx_b ++;
        }
        loop ++;
    }
    
    while (idx_a < mid) {
        temp[loop] = array[idx_a];
        idx_a ++;
        loop ++;
    }
    
    while (idx_b < end) {
        temp[loop] = array[idx_b];
        idx_b ++;
        loop ++;
    }
    
    int index = 0;
    while (index < length) {
        array[start+index] = temp[index];
        index ++;
    }
    
    free(temp);
    
    return 0;
}

/**************************************/

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

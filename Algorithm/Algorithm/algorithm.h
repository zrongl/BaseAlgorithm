//
//  algorithm.h
//  Algorithm
//
//  Created by ronglei on 14-6-18.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#ifndef Algorithm_algorithm_h
#define Algorithm_algorithm_h

#include <stdio.h>
#include <stdlib.h>

//常用的方法
void swap(int *x, int *y);
void print(int *array, int length);

/**
 * 排序算法分为：
 * 递归排序：快速排序、归并排序、堆排序
 * 非递归排序：冒泡排序、插入排序、希尔排序
 */

//查找
//对于无序排列的数据需要遍历整个数据进行查找
int findIndex(int array[], int length, int value);
//对于有序的数据，可以使用二分法查找
int binary_search(int array[], int length, int value);

//循环计算n的阶乘
int iterate(int value);
//递归计算n的阶乘
int _iterate(int value);
void inverse (char *p);
void _inverse (char *p);

//冒泡排序
int bubble_sort(int array[], int length);
int bubble_sort_pointer(int array[], int length);

//直接插入排序
int insert_sort(int array[], int length);

//快速排序
int quick_sort(int array[], int start, int end);

//归并排序
int merger_sort(int array[], int start, int end);
int merger(int array[], int start, int end);

//洗牌算法
int shuffle(int array[], int length);
#endif

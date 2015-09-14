//
//  sorting.h
//  Algorithm
//
//  Created by ronglei on 15/9/11.
//  Copyright (c) 2015年 ronglei. All rights reserved.
//

#ifndef __Algorithm__sorting__
#define __Algorithm__sorting__

/**
 * 排序算法分为：
 * 递归排序：快速排序、归并排序、堆排序
 * 非递归排序：冒泡排序、插入排序、希尔排序
 */

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

#endif

//
//  common.c
//  Algorithm
//
//  Created by ronglei on 14-6-20.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "algorithm.h"

void print(int *array, int length)
{
    if (NULL == array || 0 == length) {
        printf("params error!\n");
        exit(-1);
    }
    
    int *p = array;
    for (int i = 0; i < length; i ++) {
        printf("%d\n", *p ++);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
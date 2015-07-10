//
//  insert_sort.c
//  插入排序
//
//  Created by ronglei on 14-6-20.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "algorithm.h"

//插入排序
int insert_sort(int array[], int length)
{
    if (NULL == array && 0 == length) {
        printf("params error!\n");
        return -1;
    }
    
    printf("bfore:\n");
    print(array, length);
    
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
    print(array, length);
    
    return 0;
}


//
//  merger_sort.c
//  归并排序
//
//  Created by ronglei on 14-6-23.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "algorithm.h"

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
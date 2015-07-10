//
//  shuffle.c
//  洗牌算法
//
//  Created by ronglei on 14-7-2.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "time.h"
#include "algorithm.h"

// 洗牌算法
int shuffle(int array[], int length)
{
    if (array == NULL || length == 0) {
        return -1;
    }
    
    printf("bfore:\n");
    print(array, length);
    
    int middata = 0;
    srand((int)time(0));
    for (int i = length-1; i >= 0; i --) {
        int index = rand()%(i+1);
        
        middata = array[i];
        array[i] = array[index];
        array[index] = middata;
    }
    
    printf("after:\n");
    print(array, length);
    return 0;
}
//
//  algorithm.c
//  Algorithm
//
//  Created by ronglei on 15/9/11.
//  Copyright (c) 2015年 ronglei. All rights reserved.
//

#include "algorithm.h"
#include "helper.h"
#include "time.h"

//循环计算n的阶乘
int iterate(int value)
{
    if ( 0 > value ){
        return -1;
    }
    
    int sum = 0;
    
    for(int i = 0; i <= value; i++){
        sum += i;
    }
    printf("%d的阶乘为%d\n", value, sum);
    return sum;
}

//递归计算n的阶乘
int _iterate(int value)
{
    if( 0 > value ){
        return -1;
    }
    
    if ( 0 == value ){
        return 0;
    }else{
        return value + _iterate(value - 1);
    }
}

void inverse (char *p)
{
    while (*p != '\n') {
        printf ("%c\n", *p);
        p++;
    }
}

void _inverse(char *p)
{
    if( *p == '\n' )
        return;
    printf( "%c\n", *p );
    inverse( p+1 );
}

/**************************************/

// 洗牌算法
int shuffle(int array[], int length)
{
    if (array == NULL || length == 0) {
        return -1;
    }
    
    printf("bfore:\n");
    print_array(array);
    
    int middata = 0;
    srand((int)time(0));
    for (int i = length-1; i >= 0; i --) {
        int index = rand()%(i+1);
        
        middata = array[i];
        array[i] = array[index];
        array[index] = middata;
    }
    
    printf("after:\n");
    print_array(array);
    
    return 0;
}

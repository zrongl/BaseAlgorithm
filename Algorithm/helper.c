//
//  helper.c
//  Algorithm
//
//  Created by ronglei on 15/9/11.
//  Copyright (c) 2015年 ronglei. All rights reserved.
//

#include "helper.h"

char *change(long val, int base, char *retbuf )
{
    static char *str = "0123456789ABCDEF";
    char *p;
    char buf[64];
    
    p = buf+63;
    *p = 0;
    
    do { *--p = str[val % base]; } while( val /= base );
    strcpy(retbuf,p);
    
    return retbuf;
}

// 将float类型参数以二进制形式输出
void print_binary_f(float val2)
{
    unsigned char *p = (unsigned char*)&val2 + 3; //从低位到高位,低端字节计算机
    for(int k = 0; k <= 3; k++)
    {
        int val2 = *(p-k);
        for (int i = 7; i >= 0; i--)
        {
            if(val2 & (1 << i))
                printf("1");
            else
                printf("0");
        }
        printf(" ");
    }
    printf("\n");
}

// 控制台输出数组元素
void print_array(int *array)
{
    if (NULL == array) {
        printf("params error!\n");
        return;
    }
    
    int *p = array;
    while (*p) {
        printf("%i", *p);
    }
}

// 交换x与y所指向内存的内容
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
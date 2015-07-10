//
//  iterate.c
//  循环和递归
//
//  Created by ronglei on 14-6-23.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "algorithm.h"

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
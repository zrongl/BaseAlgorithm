//
//  search.c
//  查找算法
//
//  Created by ronglei on 14-6-23.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "search.h"
#include "helper.h"

//对于无序排列的数据需要遍历整个数据进行查找
int findIndex(int array[], int length, int value)
{
	//内容检测
	if ( NULL == array || 0 == length ){
		printf("param error\n");
		return -1;
	}
	
	int *start = array;
	int *end = array + length;

	for (int index = 0; start < end; index ++, start++){
		if( value == *start ){
			return index;
		}
	}
	
	return -1;
}

//对于有序的数据，可以使用二分法查找
int binary_search(int array[], int length, int value)
{
	//容错处理
	if ( NULL == array || 0 == length ){
		printf("param error\n");
		return -1;
	}
	
    print_array(array);
    
	int *start = array;
	int *end = array + (length - 1);
	//对于整数的乘除法应该尽量使用移位运算，这样可以显著提高运行效率
	int *middle = array + (length >> 1);
	
    while (start < end) {
        if (value < *middle) {
            end = middle - 1;
        }else if (value > *middle){
            start = middle + 1;
        }else{
            printf("%d index is :%d\n", value, (int)(middle - array));
            return (int)(middle - array);
            break;
        }
        middle = start + ((end - start) >> 1);
    }
	
    if (*start == value) {
        printf("%d index is :%d\n", value, (int)(start - array));
        return (int)(start - array);
    }else{
        printf("cannot find the value\n");
        return -1;
    }
}
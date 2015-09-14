//
//  search.h
//  Algorithm
//
//  Created by ronglei on 15/9/11.
//  Copyright (c) 2015年 ronglei. All rights reserved.
//

#ifndef Algorithm_search_h
#define Algorithm_search_h

//查找
//对于无序排列的数据需要遍历整个数据进行查找
int findIndex(int array[], int length, int value);
//对于有序的数据，可以使用二分法查找
int binary_search(int array[], int length, int value);

#endif

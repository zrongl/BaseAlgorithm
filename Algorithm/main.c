//
//  main.c
//  Algorithm
//
//  Created by ronglei on 14-6-18.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "algorithm.h"
#include "advance.h"
#include "log.h"

int main(int argc, char *argv[])
{
    int array[10];
    for (int i=0; i < 10; i ++) {
        array[i] = i;
    }
    
    int a = 123;
    int *p = &a;
    
    printf("%p\n%p\n", &array, array);
    printf("%p\n%p\n", &p, p);

    shuffle(array, 10);
    
    float f = 5.0;
    print_2(f);
    
    return 0;
}


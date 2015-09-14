//
//  main.c
//  Algorithm
//
//  Created by ronglei on 14-6-18.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "advance.h"

//static unsigned log2u (unsigned x) { return (x < 2) ? 0 : log2u (x >> 1) + 1; };
////#define GOOD_CAPACITY(c) (c <= 1 ? 1 : 1 << (log2u (c-1)+1))
//
//static unsigned exp2m1 (unsigned x) { return (1 << x) - 1; };
//#define GOOD_CAPACITY(c) (exp2m1 (log2u (c)+1))
//
//static uint32_t _objc_strhash(const char *s)
//{
//    uint32_t hash = 0;
//    for (;;) {
//        int a = *s++;
//        if (0 == a) break;
//        hash += (hash << 8) + a;
//    }
//    return hash;
//}
//
//uintptr_t _ptrhash (const void *info, const void *data)
//{
//    uintptr_t d = (uintptr_t)data;
//    printf("hash iput:%lu\n", d);
//    return ((d >> 16) ^ d);
//};

int main(int argc, char *argv[])
{
    thread_specific();
    
    return 1;
}


//
//  helper.h
//  Algorithm
//
//  Created by ronglei on 15/7/7.
//  Copyright (c) 2015年 ronglei. All rights reserved.
//

#ifndef Algorithm_helper_h
#define Algorithm_helper_h

#include <stdio.h>
#include <string.h>

char *change(long val, int base, char *buf );
void print_binary_f(float val2);

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

#endif

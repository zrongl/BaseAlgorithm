//
//  overflow.c
//  数据溢出
//  Algorithm
//
//  Created by ronglei on 14-7-11.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "advance.h"
#include <stdint.h>

/*
 bool   1byte
 char   1byte   2^8
 short  2byte   2^16
 int    4byte   2^32
 long   4byte
 float  4byte
 */

void overflow()
{
    long i = -1;
    /*
     具体参见C99/C11标准之常用算术转换一章：
     若无符号整型的位数不低于另一操作数，则有符号数转为无符号数的类型
     判断时 long型的i 与 size_t型的sizeof(i)比较
     由于size_t类型的位数不低于16位,所以i被强制转换为size_t型
     值size_t的最大值,如size_t位数为16则i的值为2^16-1
     而sizeof(i)的结果为 4
     所以打印 error
     */
    if (i < sizeof(i)) {
        printf("ok\n");
    }else {
        printf("error\n");
    }
    
    /*
     由于long类型数据局在32位和64位系统中所占位数不同所以存在问题
     所以除long long外,long类型在涉及兼容性的产品代码中应被禁用
     以x86_64架构为例,long 在Linux环境中是64比特,但在64位Windows系统中是32比特
     */
    if (-1U > 0L) {
        
    }
    
    /*
     无论C语言实现中，是否把未修饰的char看做有符号的类型，整型提升都连同符号一起把值保留下来
     有符号或无符号字符(8位)转换为短整型(16位)
     1.若字符最高位为0,则整型高8位全补0
     2.若字符最高位为1,则整型高8位全补1
     以下情况就属于字符最高位为1的情况
     声明 char c = 128;
     printf打印的时候会被强制转换为有符整形
     即: 1000 0000(char型 128) -> 1111 1111 1000 0000(有符整形 -128)
     相加等于 0
     */
    char c = 128;
    char d = 129;
    signed char uc = c;
    signed char ud = d;
    int ic = c;
    int id = d;
    printf("%d, %d\n",c,d);
    printf("%d, %d\n", uc, ud);
    printf("%d, %d\n", ic, id);
}

/*
 C标准中“整型提升规则”中写道：
 若int的表达范围足以覆盖所有的基础类型,此值将被转换为int;否则将转为unsigned int.
 这就叫做整型提升.整型提升过程中.所有其他的类型保持不变.
 */

//下述代码在32位平台中将返回65536，在16位平台上返回0:
uint32_t sum()
{
    uint16_t a = 65535;
    uint16_t b = 1;
    return a+b;
}
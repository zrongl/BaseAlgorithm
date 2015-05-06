//
//  memory.c
//  Algorithm
//
//  Created by ronglei on 14-7-15.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include <stdio.h>

#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

#define VECTOR_OK            0
#define VECTOR_NULL_ERROR    1
#define VECTOR_SIZE_ERROR    2
#define VECTOR_ALLOC_ERROR   3

struct vector {
    int *data;
    size_t size;
};

/*
 内存的申请:
 malloc:
 extern void *malloc(unsigned int num_bytes);
 使用malloc分配指定字节大小的、未初始化的内存对象。
 若入参值为0，其行为取决于操作系统实现，或者说，这是C和POSIX标准均未定义的行为。
 若请求的空间大小为0，则结果视具体实现而定：返回值可以是空指针或特殊指针。
 malloc(0) 通常返回有效的特殊指针。
 或者返回的值可成为 free 函数的参数，且函数不会错误退出。
 例如 free 函数对NULL指针不做任何操作。
 
 calloc:
 void *calloc(size_t n, size_t size);
 在内存的动态存储区中分配n个长度为size的连续空间，函数返回一个指向分配起始地址的指针；如果分配不成功，返回NULL
 calloc在动态分配完内存后，自动初始化该内存空间为零，而malloc不初始化，里边数据是随机的垃圾数据。
 
 realloc:
 extern void *realloc(void *mem_address, unsigned int newsize);
 先判断当前的指针是否有足够的连续空间，
 如果空间足够，扩大mem_address指向的地址，并且将mem_address返回，
 如果空间不够，先按照newsize指定的大小分配空间，将原有数据从头到尾拷贝到新分配的内存区域，
 而后释放原来mem_address所指内存区域（注意：原来指针是自动释放，不需要使用free），
 同时返回新分配的内存区域的首地址。即重新分配存储器块的地址。
 */
int create_vector(struct vector *vc, size_t num) {
    
    if (vc == NULL) {
        return VECTOR_NULL_ERROR;
    }
    
    vc->data = 0;
    vc->size = 0;
    
    /* check for integer and SIZE_MAX overflow */
    if (num == 0 || SIZE_MAX / num < sizeof(int)) {
        errno = ENOMEM;
        return VECTOR_SIZE_ERROR;
    }
    
    vc->data = calloc(num, sizeof(int));
    
    /* calloc faild */
    if (vc->data == NULL) {
        return VECTOR_ALLOC_ERROR;
    }
    
    vc->size = num * sizeof(int);
    return VECTOR_OK;
}

int grow_vector(struct vector *vc) {
    
    void *newptr = 0;
    size_t newsize;
    
    if (vc == NULL) {
        return VECTOR_NULL_ERROR;
    }
    
    /* check for integer and SIZE_MAX overflow */
    if (vc->size == 0 || SIZE_MAX / 2 < vc->size) {
        errno = ENOMEM;
        return VECTOR_SIZE_ERROR;
    }
    
    newsize = vc->size * 2;
    
    newptr = realloc(vc->data, newsize);
    
    /* realloc faild; vector stays intact size was not changed */
    if (newptr == NULL) {
        return VECTOR_ALLOC_ERROR;
    }
    
    /* upon success; update new address and size */
    vc->data = newptr;
    vc->size = newsize;
    return VECTOR_OK;
}

/*
 内存释放注意以下几点:
 1.指针初始化为NULL，以防不能立即传给它有效值的情况(多用calloc申请内存)
 2.GCC和Clang都有-Wuninitialized参数来警告未初始化的变量
 3.静态和动态分配的内存不要用同一个变量
 4.调用 free 后要把指针设回为NULL，这样一来即便无意中重复释放也不会导致错误
 5.测试或调试时使用assert之类的断言（如C11中静态断言，译者注）
 */

#include <assert.h>
char *ptr = NULL;

void nullfree(void **pptr)
{
    void *ptr = *pptr;
    assert(ptr != NULL);
    free(ptr);
    *pptr = NULL;
}

/*
 数组越界访问,注意以下函数区别:
 strcpy
 strncpy
 memcpy
 strlcpy
 */

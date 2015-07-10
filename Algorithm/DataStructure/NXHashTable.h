//
//  NXHashTable.h
//  Algorithm
//
//  Created by ronglei on 15/7/2.
//  Copyright (c) 2015年 ronglei. All rights reserved.
//

#ifndef __Algorithm__NXHashTable__
#define __Algorithm__NXHashTable__

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    uintptr_t	(*hash)(const void *info, const void *data);
    int         (*isEqual)(const void *info, const void *data1, const void *data2);
    void        (*free)(const void *info, void *data);
    int         style; /* reserved for future expansion; currently 0 */
} NXHashTablePrototype;

/**
 * hash表的元素需要满足两种约束：
 * 1.相同的data值应该具有相同的hash值,即data1 = data2 -> hash(data1) = hash(data2)
 * 2.isEqual函数可以确定两个data是否相同,即isEqual(data1, data2) == 1 -> data1 = data2
 */

/**
 * 下面是hash结构体
 * prototype  :hash函数表
 * count      :hash结构已经有的key个数
 * nbBuckets  :hash表的容量大小,随count增多而改变
 * 当count > nbBuckets时会通过_NXHashRehash函数进行扩扩容
 * buckets    :hash表的数组基址
 */
typedef struct {
    const NXHashTablePrototype	*prototype;
    unsigned                    count;
    unsigned                    nbBuckets;
    void                        *buckets;
    const void                  *info;
} NXHashTable;

NXHashTable *NXCreateHashTableFromZone(NXHashTablePrototype prototype, unsigned capacity, const void *info, void *z);
NXHashTable *NXCreateHashTable(NXHashTablePrototype prototype, unsigned capacity, const void *info);

void NXFreeHashTable(NXHashTable *table);
void NXEmptyHashTable(NXHashTable *table);
void NXResetHashTable(NXHashTable *table);
bool NXCompareHashTables(NXHashTable *table1, NXHashTable *table2);
NXHashTable *NXCopyHashTable(NXHashTable *table);
unsigned NXCountHashTable(NXHashTable *table);
int NXHashMember(NXHashTable *table, const void *data);
void *NXHashGet(NXHashTable *table, const void *data);
void *NXHashInsert(NXHashTable *table, const void *data);
void *NXHashInsertIfAbsent(NXHashTable *table, const void *data);
void *NXHashRemove(NXHashTable *table, const void *data);

typedef struct {
    int i;
    int j;
} NXHashState;

NXHashState NXInitHashState(NXHashTable *table);
int NXNextHashState(NXHashTable *table, NXHashState *state, void **data);
uintptr_t NXPtrHash(const void *info, const void *data);
uintptr_t NXStrHash(const void *info, const void *data);
int NXPtrIsEqual(const void *info, const void *data1, const void *data2);
int NXStrIsEqual(const void *info, const void *data1, const void *data2);
void NXNoEffectFree(const void *info, void *data);
void NXReallyFree(const void *info, void *data);

const NXHashTablePrototype NXPtrPrototype;
const NXHashTablePrototype NXStrPrototype;

const NXHashTablePrototype NXPtrStructKeyPrototype;
const NXHashTablePrototype NXStrStructKeyPrototype;

#if !__OBJC2__ && !TARGET_OS_WIN32

typedef const char *NXAtom;
NXAtom NXUniqueString(const char *buffer);
NXAtom NXUniqueStringWithLength(const char *buffer, int length);
NXAtom NXUniqueStringNoCopy(const char *string);
char *NXCopyStringBuffer(const char *buffer);
char *NXCopyStringBufferFromZone(const char *buffer, void *z);

#endif

#endif

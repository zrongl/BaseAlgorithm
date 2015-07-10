//
//  data_structure.h
//  Algorithm
//
//  Created by ronglei on 14-6-30.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#ifndef Algorithm_data_structure_h
#define Algorithm_data_structure_h

#include <stdio.h>
#include "stdlib.h"
#include "string.h"

typedef int CType;

/*********************
 * 单链表 list
 *********************/
#pragma mark - list

typedef struct _List_Node{
    CType data;
    struct _List_Node *next;
}List_Node, *List_Node_Ptr;

List_Node_Ptr init_list(void);
int list_length(List_Node_Ptr head);

int list_insert(List_Node_Ptr head, List_Node_Ptr node, int index);
int list_delete(List_Node_Ptr head, int index);

//链表逆序
List_Node_Ptr reverse(List_Node_Ptr head);
//链表逆序输出
void reverse_print(List_Node_Ptr head);


/*********************
 * 栈 stack
 *********************/
#pragma mark - stack

#define MAX_SIZE    100
typedef struct _Stack_Node{
    CType data[MAX_SIZE];
    int top;
}Stack_Node, *Stack_Node_Ptr;

Stack_Node_Ptr init_stack(void);
int is_empty_stack(Stack_Node_Ptr stack);
int is_full_stack(Stack_Node_Ptr stack);
int push(Stack_Node_Ptr stack, CType elem);
int pop(Stack_Node_Ptr stack, CType *elem);

/*********************
 * 队列 queue
 *********************/
#pragma mark - queue

typedef struct _Queue_Node{
    CType data[MAX_SIZE];
    int front;
    int tail;
}Queue_Node, *Queue_Node_Ptr;

Queue_Node_Ptr init_queue(void);
int is_empty_queue(Queue_Node_Ptr queue);
int is_full_queue(Queue_Node_Ptr queue);
int queue_in(Queue_Node_Ptr queue, CType elem);
int queue_out(Queue_Node_Ptr queue, CType *elem);

/*********************
 * 二叉树 tree
 *********************/
#pragma mark - tree

typedef struct _Binary_Tree{
    char data;
    struct _Binary_Tree *lchild, *rchild;
}Binary_Tree_Node, *Binary_Tree_Node_Ptr;

void binary_tree_init(Binary_Tree_Node_Ptr *tree);
//前序遍历
void pre_order_traverse(Binary_Tree_Node_Ptr tree);
//中序遍历
void mid_order_traverse(Binary_Tree_Node_Ptr tree);
//后续遍历
void last_order_traverse(Binary_Tree_Node_Ptr tree);

/*********************
 * 哈希表 hash
 *********************/
#pragma mark - hash

//数据类型重定义
#define uint8_t unsigned char
#define uint16_t unsigned short
#define uint32_t unsigned long

// 哈希表长度
#define HASH_TABLE_LEN	100

//节点
typedef struct _Link_Node
{
    uint16_t id;
    uint16_t data;
    struct _Link_Node *next;
}Link_Node,*Link_Node_Ptr;

//哈希表头
typedef struct _Hash_Header
{
    struct _Link_Node *next;
}Hash_Header,*Hash_Header_Ptr;

// 全局变量 哈希表
Hash_Header_Ptr Hash_Table[HASH_TABLE_LEN];

void hash_operation();
#endif
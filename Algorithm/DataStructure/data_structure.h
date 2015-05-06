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

//单链表
typedef struct List{
    CType data;
    struct List *next;
}LiNode, *List;

int list_init(List *list);
int list_length(LiNode *head);

int list_insert(LiNode *head, LiNode *node, int index);
int list_delete(LiNode *head, int index);

//链表逆序
LiNode *reverse(LiNode *head);
//链表逆序输出
void reverse_print(LiNode *head);

//栈
#define MAX_SIZE    100
typedef struct Stack{
    CType data[MAX_SIZE];
    int top;
}StNode, *Stack;

int stack_init(Stack *stack);
int is_empty_stack(StNode *stack);
int is_full_stack(StNode *stack);
int push(StNode *stack, CType elem);
int pop(StNode *stack, CType *elem);

//队列
typedef struct Queue{
    CType data[MAX_SIZE];
    int front;
    int tail;
}QuNode, *Queue;

int queue_init(Queue *queue);
int is_empty_queue(QuNode *queue);
int is_full_queue(QuNode *queue);
int queue_in(QuNode *queue, CType elem);
int queue_out(QuNode *queue, CType *elem);

//二叉树
typedef struct BiTree{
    char data;
    struct BiTree *lchild, *rchild;
}BiTNode, *BiTree;

void bitree_init(BiTree *tree);
//前序遍历
void pre_order_traverse(BiTree tree);
//中序遍历
void mid_order_traverse(BiTree tree);
//后续遍历
void last_order_traverse(BiTree tree);
#endif
//
//  list.c
//  Algorithm
//
//  Created by ronglei on 14-6-23.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "data_structure.h"

//创建一个只有头结点的链表
int list_init(List *list)
{
    *list = (List)malloc(sizeof(LiNode));
    if (*list == NULL) {
        return -1;
    }
    
    (*list)->data = 0;
    (*list)->next = NULL;
    
    return 0;
}

int list_length(LiNode *head)
{
    if (head == NULL) {
        return -1;
    }
    
    LiNode *start = head;
    
    int length = 0;
    while (start->next != NULL) {
        length ++;
        start = start->next;
    }
    
    return length;
}

//在索引为index的节点前插入新节点
int list_insert(LiNode *head, LiNode *node, int index)
{
    if (head == NULL || node == NULL || index < 0) {
        return -1;
    }
    
    LiNode *current = head;
    LiNode *before = NULL;
    int i = 0;
    
    while (current->next != NULL && i < index) {
        before = current;
        current = current->next;
        i ++;
    }
    
    if (i == index) {
        before->next = node;
        node->next = current;
        return 0;
    }
    
    return -1;
}

LiNode *reverse(LiNode *head)
{
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    LiNode *s = head;
    LiNode *h = NULL;
    LiNode *n = NULL;
    
    while (s != NULL) {
        n = s->next;
        s->next = h;
        
        h = s;
        s = n;
    }
    
    head = h;
    return head;
}

void reverse_print(LiNode *head)
{
    if (head->next == NULL) {
        return;
    }
    
    reverse_print(head->next);
    printf("%d", head->data);
}

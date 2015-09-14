//
//  list.c
//  Algorithm
//
//  Created by ronglei on 14-6-23.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "structure.h"

//创建一个只有头结点的链表
List_Node_Ptr init_list(void)
{
    List_Node_Ptr list;
    
    list = (List_Node_Ptr)malloc(sizeof(List_Node));
    if (list == NULL) {
        return NULL;
    }
    
    list->data = 0;
    list->next = NULL;
    
    return list;
}

int list_length(List_Node_Ptr head)
{
    if (head == NULL) {
        return -1;
    }
    
    List_Node_Ptr start = head;
    
    int length = 0;
    while (start->next != NULL) {
        length ++;
        start = start->next;
    }
    
    return length;
}

//在索引为index的节点前插入新节点
int list_insert(List_Node_Ptr head, List_Node_Ptr node, int index)
{
    if (head == NULL || node == NULL || index < 0) {
        return -1;
    }
    
    List_Node_Ptr current = head;
    List_Node_Ptr before = NULL;
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

List_Node_Ptr reverse(List_Node_Ptr head)
{
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    List_Node_Ptr s = head;
    List_Node_Ptr h = NULL;
    List_Node_Ptr n = NULL;
    
    while (s != NULL) {
        n = s->next;
        s->next = h;
        
        h = s;
        s = n;
    }
    
    head = h;
    return head;
}

void reverse_print(List_Node_Ptr head)
{
    if (head->next == NULL) {
        return;
    }
    
    reverse_print(head->next);
    printf("%d", head->data);
}

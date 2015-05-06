//
//  stack.c
//  Algorithm
//
//  Created by ronglei on 14-6-30.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "data_structure.h"

int stack_init(Stack *stack)
{
    *stack = (Stack)malloc(sizeof(StNode));
    if (*stack == NULL) {
        return -1;
    }
    
    (*stack)->top = -1;
    
    return 0;
}

int is_empty_stack(StNode *stack)
{
    return 1;
}

int is_full_stack(StNode *stack)
{
    return 1;
}

int push(StNode *stack, CType elem)
{
    if (stack->top == (MAX_SIZE - 1)) {
        return -1;
    }
    
    stack->data[stack->top] = elem;
    stack->top ++;
    
    return 0;
}

int pop(StNode *stack, CType *elem)
{
    if (stack->top ==  -1) {
        return -1;
    }
    
    *elem =  stack->data[stack->top];
    stack->data[stack->top] = 0;
    stack->top --;
    
    return 0;
}
//
//  stack.c
//  Algorithm
//
//  Created by ronglei on 14-6-30.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "structure.h"

Stack_Node_Ptr init_stack(void)
{
    Stack_Node_Ptr stack;
    
    stack = (Stack_Node_Ptr)malloc(sizeof(Stack_Node));
    if (stack == NULL) {
        return NULL;
    }
    
    stack->top = -1;
    
    return 0;
}

int is_empty_stack(Stack_Node_Ptr stack)
{
    return 1;
}

int is_full_stack(Stack_Node_Ptr stack)
{
    return 1;
}

int push(Stack_Node_Ptr stack, CType elem)
{
    if (stack->top == (MAX_SIZE - 1)) {
        return -1;
    }
    
    stack->data[stack->top] = elem;
    stack->top ++;
    
    return 0;
}

int pop(Stack_Node_Ptr stack, CType *elem)
{
    if (stack->top ==  -1) {
        return -1;
    }
    
    *elem =  stack->data[stack->top];
    stack->data[stack->top] = 0;
    stack->top --;
    
    return 0;
}
//
//  queue.c
//  Algorithm
//
//  Created by ronglei on 14-7-1.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "structure.h"

Queue_Node_Ptr init_queue(void)
{
    Queue_Node_Ptr queue;
    
    queue = (Queue_Node_Ptr)malloc(sizeof(Queue_Node));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->front = 0;
    queue->tail = 0;
    
    return queue;
}

int is_empty_queue(Queue_Node_Ptr queue)
{
    return (queue->front == queue->tail) ? 1 : 0;
}

int is_full_queue(Queue_Node_Ptr queue)
{
    return ((queue->tail - queue->front) == (MAX_SIZE - 1)) ? 1 : 0;
}

int queue_in(Queue_Node_Ptr queue, CType elem)
{
    if (queue == NULL || is_full_queue(queue)) {
        return -1;
    }
    
    queue->data[queue->tail] = elem;
    queue->tail ++;
    
    return 0;
}

int queue_out(Queue_Node_Ptr queue, CType *elem)
{
    if (queue == NULL || is_empty_queue(queue)) {
        return -1;
    }
    
    *elem = queue->data[queue->front];
    
    int front = queue->front;
    while (front < queue->tail) {
        queue->data[front] = queue->data[front + 1];
        front ++;
    }
    
    queue->tail --;
    
    return 0;
}

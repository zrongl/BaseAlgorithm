//
//  queue.c
//  Algorithm
//
//  Created by ronglei on 14-7-1.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "data_structure.h"

int queue_init(Queue *queue)
{
    *queue = (Queue)malloc(sizeof(QuNode));
    if (*queue == NULL) {
        return -1;
    }
    
    (*queue)->front = 0;
    (*queue)->tail = 0;
    
    return 0;
}

int is_empty_queue(QuNode *queue)
{
    return (queue->front == queue->tail) ? 1 : 0;
}

int is_full_queue(QuNode *queue)
{
    return ((queue->tail - queue->front) == (MAX_SIZE - 1)) ? 1 : 0;
}

int queue_in(QuNode *queue, CType elem)
{
    if (queue == NULL || is_full_queue(queue)) {
        return -1;
    }
    
    queue->data[queue->tail] = elem;
    queue->tail ++;
    
    return 0;
}

int queue_out(QuNode *queue, CType *elem)
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

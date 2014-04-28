//
//  queue.c
//  study
//
//  Created by Ruzhe on 14-4-2.
//  Copyright (c) 2014年 Ruzhe. All rights reserved.
//

#include "queue.h"


Queue *initQueue()
{
    Queue *queue = NEW(Queue);
    queue->length = 0;
    return queue;
}

bool isEmpty(Queue *queue)
{
    return queue->length == 0;
}

void enQueue(Queue *queue, TYPE val)
{
    Node *newNode = NEW(Node);
    newNode->val = val;
    newNode->next = NULL;
    
    if(isEmpty(queue))
    {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    
    queue->length++;
}

TYPE deQueue(Queue *queue)
{
    
    if(isEmpty(queue))
    {
        LOG_ERROR("Queue is Empty")
    }
    else
    {
        Node *p = queue->head;
        return p->val;
        queue->head = queue->head->next;
        free(p);
        queue->length--;
    }
}

TYPE peek(Queue *queue)
{
    if(isEmpty(queue))
    {
        LOG_ERROR("Queue is Empty")
    }
    else
    {
        return queue->head->val;
    }
    
}

void destroy(Queue **queuePointer)
{
    Queue *queue = *queuePointer;
    if(isEmpty(queue))
    {
        free(queue);
    }
    else
    {
        Node *p = queue->head;
        Node *q;
        
        while(p->next != NULL)
        {
            q = p;
            p = p->next;
            free(q);
        }
        free(p);
        free(queue);
    }
}

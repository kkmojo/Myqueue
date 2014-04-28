//
//  queue.h
//  study
//
//  Created by Ruzhe on 14-4-1.
//  Copyright (c) 2014年 Ruzhe. All rights reserved.
//

#ifndef study_queue_h
#define study_queue_h

#include "list.h"

typedef List Queue;

Queue *initQueue();
bool isEmpty(Queue *queue);
void enQueue(Queue *queue, TYPE val);
TYPE deQueue(Queue *queue);
TYPE peek(Queue *queue);
void destroy(Queue **queuePointer);

#endif

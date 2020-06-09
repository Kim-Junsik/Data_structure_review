//
//  ex_10.c
//  DS_study
//
//  Created by KimJunsik on 2020/06/09.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct
{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return (q->front == ((q->rear + 1)%MAX_QUEUE_SIZE));
}


void enqueue(QueueType *q, element item)
{
    if(is_full(q))
        error("Queue is full");
    q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}


element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("Queue is empty");
    q->front = (q->front+1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q)
{
    if(is_empty(q))
        error("Queue is empty");
    return q->data[(q->front+1)%MAX_QUEUE_SIZE];
}

int main()
{
    QueueType q;
    init_queue(&q);
    
    enqueue(&q, 0);
    enqueue(&q, 1);
    
    for(int i = 0; i < 10; i++)
    {
        element cur = dequeue(&q);
        cur += peek(&q);
        printf("%d, ", cur);
        enqueue(&q, cur);
    }
    
    return 0;
}

//
//  Linked_Queue.c
//  DS_study
//
//  Created by KimJunsik on 2020/08/17.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct QueueNode
{
    element data;
    struct QueueNode *link;
}QueueNode;

typedef struct
{
    QueueNode *front, *rear;
}LinkedQueueType;

void init(LinkedQueueType *q)
{
    q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType *q)
{
    return (q->front == NULL);
}

int is_full(LinkedQueueType *q)
{
    return 0;
}

void enqueue(LinkedQueueType *q, element data)
{
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->link = NULL;
    if(is_empty(q))
    {
        q->front = temp;
        q->rear = temp;
    }
    else
    {
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(LinkedQueueType *q)
{
    QueueNode *temp = q->front;
    element data;
    if(is_empty(q))
    {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    else
    {
        data = temp->data;
        q->front = temp->link;
        if(q->front == NULL)
            q->rear = NULL;
        free(temp);
        return data;
    }
}

void print_queue(LinkedQueueType *q)
{
    for(QueueNode *p = q->front; p != NULL; p = p->link)
    {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

int main()
{
    LinkedQueueType q;
    init(&q);
    
    enqueue(&q, 1); print_queue(&q);
    enqueue(&q, 2); print_queue(&q);
    enqueue(&q, 3); print_queue(&q);
    dequeue(&q); print_queue(&q);
    dequeue(&q); print_queue(&q);
    dequeue(&q); print_queue(&q);
    return 0;
}

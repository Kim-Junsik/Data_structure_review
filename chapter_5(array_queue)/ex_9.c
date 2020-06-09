//
//  ex_9.c
//  DS_study
//
//  Created by KimJunsik on 2020/06/09.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef int element;
typedef struct
{
    element stack[MAX_STACK_SIZE];
    element top;
}StackType;

int stack_is_empty(StackType *s)
{
    return (s->top == -1);
}

int stack_is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE-1));
}

void stack_push(StackType *s, element item)
{
    if(stack_is_full(s))
    {
        fprintf(stderr,"stack is full\n");
        exit(1);
    }
    else s->stack[++(s->top)] = item;
}

element stack_pop(StackType *s)
{
    if(stack_is_empty(s))
    {
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    
    else return s->stack[(s->top)--];
}

typedef struct Queue{
    StackType s1;
    StackType s2;
}QueueType;

void queue_init(QueueType *q)
{
    q->s1.top = -1;
    q->s2.top = -1;
}

void queue_push(QueueType *q, element item)
{
    if(stack_is_full(&(q->s1)))
    {
        printf("s1 is full\n");
        exit(1);
    }
    
    stack_push(&(q->s1), item);
}

element queue_pop(QueueType *q)
{
    if(stack_is_empty(&(q->s2)))
    {
        while(!stack_is_empty(&(q->s1)))
        {
            stack_push(&(q->s2), stack_pop(&(q->s1)));
        }
    }
    
    return stack_pop(&(q->s2));
}

int main()
{
    QueueType q;
    queue_init(&q);
    queue_push(&q, 5);
    queue_push(&q, 4);
    queue_push(&q, 3);
    printf("%d\n", queue_pop(&q));
    printf("%d\n", queue_pop(&q));
    printf("%d\n", queue_pop(&q));
    return 0;
}

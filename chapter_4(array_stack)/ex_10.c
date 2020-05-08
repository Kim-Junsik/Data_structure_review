//
//  ex_10.c
//  DS_study
//
//  Created by KimJunsik on 2020/05/08.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 6

typedef int element;
typedef struct
{
    element stack[MAX_STACK_SIZE];
    element top;
}StackType;

void init_stack(StackType *s)
{
    s->top = -1;
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, element item)
{
    if(is_full(s))
    {
        fprintf(stderr,"stack is full\n");
        exit(1);
    }
    else s->stack[++(s->top)] = item;
}

element pop(StackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    
    else return s->stack[(s->top)--];
}

int main()
{
    StackType s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    push(&s, 6);
    
    for (int i = 0; i < MAX_STACK_SIZE; i++)
    {
        printf("%d, ", pop(&s));
    }
    
    return 0;
}

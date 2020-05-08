//
//  ex_12.c
//  DS_study
//
//  Created by KimJunsik on 2020/05/08.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct
{
    element stack[MAX_STACK_SIZE];
    int top;
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

element peek(StackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    
    else return s->stack[s->top];
}

int main()
{
    char input[MAX_STACK_SIZE] = {};
    int count = 0;
    scanf("%s", input, sizeof(input));
    
    StackType s;
    init_stack(&s);
        
    for(int i = 0; i < MAX_STACK_SIZE; i++)
    {
        char pivot = input[i];
        if( pivot>='A' && pivot<='Z')
            pivot += 32;
        if(input[i] == '\0')
        {
            printf("%d%c", count, peek(&s));
            break;
        }
        else
        {
            if(is_empty(&s) || peek(&s) == pivot)
            {
                push(&s, pivot);
                count++;
            }
            else
            {
                printf("%d%c", count, peek(&s));
                s.top = -1;
                push(&s, pivot);
                count=1;
            }
        }
    }
    printf("\n");
    return 0;
}

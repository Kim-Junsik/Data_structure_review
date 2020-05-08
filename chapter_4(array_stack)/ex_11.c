//
//  ex_11.c
//  DS_study
//
//  Created by KimJunsik on 2020/05/08.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 20
#define MAX_STRING_SIZE 20
typedef int element;

typedef struct
{
    element datas[MAX_STACK_SIZE];
    int top;
    
    int left;
    int right;
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

void push(StackType *s, element data)
{
    if(is_full(s))
    {
        fprintf(stderr,"stack is full\n");
        exit(1);
    }
    s->datas[++(s->top)] = data;
}

int pop(StackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "stack is empty\n");
        exit(2);
    }
    return (s->datas[(s->top)--]);
}

int main()
{
    char inputs[MAX_STRING_SIZE] = {};
    StackType s;
    init_stack(&s);
    printf("수식 : ");
    scanf("%s", inputs, sizeof(inputs));
    printf("괄호 수 : ");
    int count = 0;
    
    for (int i = 0; i < MAX_STRING_SIZE; i++)
    {
        if(inputs[i] == 0)
        {
            printf("\n program is down");
            return 0;
        }
        else
        {
            if(inputs[i] == '(')
            {
                push(&s, ++count);
                printf("%d ", count);
            }
            else
            {
                printf("%d ", pop(&s));
            }
        }
    }
    printf("\n");
    return 0;
}

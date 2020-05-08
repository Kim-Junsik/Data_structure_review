//
//  ex_16.c
//  DS_study
//
//  Created by KimJunsik on 2020/05/08.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;
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
    char inputs[MAX_STACK_SIZE] = {};
    scanf("%s", inputs, sizeof(inputs));
    StackType s;
    init_stack(&s);
    int check = 1;
    
    int size = (int)strlen(inputs)/2;
    for (int i = 0; i < MAX_STACK_SIZE; i++)
    {
        if((inputs[i]>=65 && inputs[i]<=90) || (inputs[i] >= 97 && inputs[i] <= 122))
        {
            push(&s, inputs[i]);
        }
    }
    
    for (int j = 0; j<size;j++)
    {
        if((inputs[j]>=65 && inputs[j]<=90) || (inputs[j] >= 97 && inputs[j] <= 122))
        {
            if(inputs[j] != pop(&s))
            {
                check = 0;
                break;
            }
        }
    }
    
    if(check == 1)
        printf("회문입니다\n");
    else
        printf("회문이 아닙니다\n");
    return 0;
}

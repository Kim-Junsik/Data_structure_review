//
//  program_4_7.c
//  DS_study
//
//  Created by KimJunsik on 2020/05/06.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 후위식을 계산하는 프로그램
#include <stdio.h>
#include <stdlib.h>
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

int eval(char exp[])
{
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;
    
    init_stack(&s);
    for (i = 0; i < len ; i++)
    {
        ch = exp[i];
        if(ch!='+' && ch!='-' && ch!='*' && ch!='/')
        {
            value = ch-'0';
            push(&s, value);
        }
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch)
            {
                case '+':
                    push(&s, op1+op2);
                    break;
                case '-':
                    push(&s, op1-op2);
                    break;
                case '*':
                    push(&s, op1*op2);
                    break;
                case '/':
                    push(&s, op1/op2);
                    break;
            }
        }
    }
    return pop(&s);
}

int main()
{
    int result;
    printf("input string is : 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("%d\n", result);
    return 0;
}

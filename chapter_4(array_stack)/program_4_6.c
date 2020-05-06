//
//  program_4_6.c
//  DS_study
//
//  Created by KimJunsik on 2020/05/06.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 문자열에서 괄호를 검사하는 프로그램
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

int check_matching(const char *in)
{
    StackType s;
    char ch, open_ch;
    int i, n = (int)strlen(in);
    init_stack(&s);
    
    for (i = 0; i < n ; i++)
    {
        ch = in[i];
        switch(ch)
        {
            case '(':
            case '{':
            case '[':
                push(&s, ch);
                break;
            case ')':
            case '}':
            case ']':
                open_ch = pop(&s);
                if((open_ch == '(' && ch != ')') ||
                   (open_ch == '{' && ch != '}') ||
                   (open_ch == '[' && ch != ']'))
                {
                    return 0;
                }
                break;
        }
    }
    if (!is_empty(&s)) return 0;
    return 1;
}

int main()
{
    char* arr[3];
    arr[0] = "{A[(i+!)]=0;}";
    arr[1] = "{(a+b)*k[2+3*n]}";
    arr[2] = "{[(2+10)*u]/3]";
    
    for (int i = 0; i < sizeof(arr)/sizeof(char*); i++)
    {
        if(check_matching(arr[i]) == 1)
            printf("%s matching success\n", arr[i]);
        else
            printf("%s matching failed\n", arr[i]);
    }
    
    return 0;
}

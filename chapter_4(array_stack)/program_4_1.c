//
//  program_4_1.c
//  DS_study
//
//  Created by KimJunsik on 2020/05/06.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 전역 변수를 활용하여 스텍을 만들면 간단하게 사용할 수 있지만
// 이는 여러 스텍을 사용할 경우 사용하기 어려워진다.

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

/*
#define MAX_STRING 100

typedef struct
{
    int sudent_no;
    char name[MAX_STRING];
    char address[MAX_STRING];
}element;
*/

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty()
{
    return (top == -1);
}

int is_full()
{
    return (top == (MAX_STACK_SIZE-1));
}

void push(element item)
{
    if(is_full())
    {
        fprintf(stderr,"stack is full\n");
        exit(1);
    }
    else stack[++top] = item;
}

element pop()
{
    if(is_empty())
    {
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    else return stack[top--];
}

element peek()
{
    if(is_empty())
    {
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    else return stack[top];
}

int main()
{
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}

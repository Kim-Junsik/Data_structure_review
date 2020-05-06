//
//  program_4_2.c
//  DS_study
//
//  Created by KimJunsik on 2020/05/06.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 스텍과 top을 가지고 있는 구조체를 선언하고 이의 포인터를 넘겨주는 형식이면
// 전역변수에서의 단점을 해결할 수 있다.
// c언어는 기본적으로 call by value방식이다
// 이는 구조체를 함수에 넘겨준다면 함수에서는 원본이 아니라 복사본을 가지고 연산을 하게 된다
// 포인터를 넘겨준다면 이는 외부에서 받은 매개변수를 변경할 수 있다.

#include <stdio.h>
#include <stdlib.h>

// 이후 공부에서 스택이 필요하면 여기부터 복사하면 된다
// ======== 스텍 코드의 시작 ========

#define MAX_STACK_SIZE 100

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

element peek(StackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    
    else return s->stack[s->top];
}

// ======== 스택 끝 ========


// 책에서의 도전문제
// 2개의 스택을 만든후 첫번째 스텍에 1,2,3 추가 후 삭제
// 삭제한 숫자를 그대로 두번째 스텍에 저장하고 삭제하면서 출력한다면??
// --> 처음 저장한 순서 1,2,3 순서로 출력된다.

int main()
{
    StackType s1;
    StackType s2;
    init_stack(&s1);
    init_stack(&s2);
    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    
    push(&s2, pop(&s1));
    push(&s2, pop(&s1));
    push(&s2, pop(&s1));
    
    printf("%d\n", pop(&s2));
    printf("%d\n", pop(&s2));
    printf("%d\n", pop(&s2));
    return 0;
}



//
//  program_4_5.c
//  DS_study
//
//  Created by KimJunsik on 2020/05/06.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct
{
    element *data;
    int capacity;
    int top;
}StackType;

void init_stack(StackType *s)
{
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(s->capacity*sizeof(element));
    if(s->data == NULL)
    {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE-1));
}

// realloc() 함수는 이전에 예약된 기억장치 블록의 크기를 변경한다.
// ptr이 NULL이면, realloc()는 size 바이트의 기억장치 블록을 예약한다. 각 요소의 모든 비트를 0의 초기값으로 지정되는 것은 아니다.
// size가 0이고 ptr이 NULL이 아닌 경우, realloc()은 ptr에 할당된 기억장치를 해제하고 NULL을 리턴한다.
// realloc() 함수는 재할당된 기억장치 블록에 대한 포인터를 리턴한다. (ptr 인수는 realloc() 함수가 리턴값과 반드시 동일할 필요는 없다.)
// 블록을 지정된 크기로 확장하기 위한 충분한 기억장치가 없는 경우, 원래 블록이 변경되지 않으며 realloc() 함수는 NULL을 리턴한다.
void push(StackType *s, element item)
{
    if(is_full(s))
    {
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, s->capacity*sizeof(element));
        
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr,"stack is empty\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

int main()
{
    StackType s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    free(s.data);
    return 0;
}

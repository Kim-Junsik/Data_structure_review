//
//  program_6_1.c
//  DS_study
//
//  Created by KimJunsik on 2020/06/12.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 배열을 이용한 리스트의 구현

#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct
{
    element array[MAX_LIST_SIZE];
    int size;
}ArrayListType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(ArrayListType *L)
{
    L->size = 0;
}

int is_empty(ArrayListType *L)
{
    return L->size == 0;
}

int is_full(ArrayListType *L)
{
    return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType *L, int pos)
{
    if(pos < 0 || pos >= L->size)
        error("index out of range");
    return L->array[pos];
}

void print_list(ArrayListType *L)
{
    int i;
    for (i=0; i<L->size; i++)
    {
        printf("%d -> ", L->array[i]);
    }
    printf("\n");
}

void insert_last(ArrayListType *L, element item)
{
    if(L->size >= MAX_LIST_SIZE)
    {
        error("List overflow");
    }
    L->array[L->size++] = item;
}

void insert(ArrayListType *L, int pos, element item)
{
    if(!is_full(L) && (pos >= 0) && (pos <= L->size))
    {
        for(int i = (L->size-1); i >= pos; i--)
        {
            L->array[i+1] = L->array[i];
        }
        L->array[pos] = item;
        L->size++;
    }
}

element delete(ArrayListType *L, int pos)
{
    element item;
    
    if(pos < 0 || pos >= MAX_LIST_SIZE)
        error("pos is out of range");
    item = L->array[pos];
    for(int i = pos+1; i < L->size; i++)
    {
        L->array[i-1] = L->array[i];
    }
    L->size--;
    return item;
}

// 책 문제 추가 구현 insert_first, clear, replace, get_length
void insert_first(ArrayListType *L, element item)
{
    if(is_full(L))
        error("list is full");
    for (int i = 0; i < L->size; i++)
    {
        L->array[i+1] = L->array[i];
    }
    L->array[0] = item;
    L->size++;
}

void clear_list(ArrayListType *L)
{
    L->size = 0;
}

void replace(ArrayListType *L, int pos, element item)
{
    if(pos < 0 || pos >= MAX_LIST_SIZE)
        error("index is out of range");
    L->array[pos] = item;
}

int get_length(ArrayListType *L)
{
    return L->size;
}

int main()
{
    ArrayListType list;
    
    init(&list);
    insert(&list, 0, 10); print_list(&list);
    insert(&list, 0, 20); print_list(&list);
    insert(&list, 0, 30); print_list(&list);
    insert_last(&list, 40); print_list(&list);
    delete(&list, 0); print_list(&list);
    insert_first(&list, 100); print_list(&list);
    replace(&list, 3, 70); print_list(&list);
    printf("list length  : %d\n", get_length(&list));
    clear_list(&list);
    printf("list length : %d\n", get_length(&list));
    return 0;
}

//
//  ex_14.c
//  DS_study
//
//  Created by KimJunsik on 2020/07/13.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 이름(string), 나이(int), 키(float)를 저정하는 연결 리스트 만들기
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[10];
    int age;
    float heigh;
} element;

typedef struct ListNode
{
    element data;
    struct ListNode *link;
}ListNode;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* init_list(ListNode *head)
{
    ListNode *dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->data.age = 0;
    dummy->data.heigh = 0.0;
    dummy->link = NULL;
    head = dummy;
    return head;
}

void insert_last(ListNode *head, element *value)
{
    ListNode *cur = head;
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = (*value);
    p->link = NULL;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = p;
    return;
}

ListNode* delete_first(ListNode *head)
{
    ListNode *removed;
    if(head == NULL)
        return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode *head)
{
    for (ListNode *p = head->link; p != NULL; p = p->link)
    {
        printf("(%s, %d, %f)-> ", p->data.name, p->data.age, p->data.heigh);
    }
    printf("NULL\n");
}

int main()
{
    char *name = (char*)malloc(sizeof(char)*10);
    int age, n;
    float heigh;
    scanf("%d", &n);
    ListNode* head = NULL;
    head = init_list(head);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %d %f", name, &age, &heigh);
        element value;
        strcpy(value.name, name);
        value.age = age;
        value.heigh = heigh;
        insert_last(head, &value);
    }
    print_list(head);
    for(int i = 0; i<n; i++)
    {
        head = delete_first(head);
    }
    return 0;
}

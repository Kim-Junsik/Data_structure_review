//
//  ex_13.c
//  DS_study
//
//  Created by KimJunsik on 2020/07/13.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 특정 데이터 값을 가지는 노드를 삭제하는 함수 구현
#include <stdio.h>
#include <stdlib.h>

typedef int element;
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
    dummy->data = 0;
    dummy->link = NULL;
    head = dummy;
    return head;
}
ListNode* insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void insert_last(ListNode *head, element value)
{
    ListNode *cur = head;
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = NULL;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = p;
    return;
}

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
    ListNode* p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
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

void remove_element_node(ListNode** head, element item)
{
    ListNode* p = NULL, *removed = (*head)->link;
    while (removed->data != item)
    {
        p = removed;
        removed = removed->link;
    }
    p->link = removed->link;

    free(removed);
    return;
}

void print_list(ListNode *head)
{
    for (ListNode *p = head->link; p != NULL; p = p->link)
    {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

element get_entry(ListNode *head, int index)
{
    ListNode *cur = head;
    for (int i = 0; i < index; i++)
        cur = cur->link;
    return cur->data;
}

int list_count(ListNode *head)
{
    int count = 0;
    ListNode *cur = head;
    while(cur->link != NULL)
    {
        cur = cur->link;
        count++;
    }
    return count;
}

int list_sum(ListNode *head)
{
    int sum = 0;
    ListNode *cur = head;
    while(cur->link != NULL)
    {
        cur = cur->link;
        sum += cur->data;
    }
    return sum;
}

int find_element(ListNode *head, element value)
{
    int count = 0;
    ListNode *cur = head;
    while(cur->link != NULL)
    {
        cur = cur->link;
        if(cur->data == value)
            count++;
    }
    return count;
}

int main()
{
    int n, value, remove_val;
    scanf("%d", &n);
    ListNode *head = NULL;
    head = init_list(head);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert_last(head, value);
    }
    scanf("%d", &remove_val);
    remove_element_node(&head, remove_val);
    
    print_list(head);
    for(int i = 0; i < n; i++)
    {
        head = delete_first(head);
    }
    return 0;
}

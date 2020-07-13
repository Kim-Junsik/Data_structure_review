//
//  ex_16.c
//  DS_study
//
//  Created by KimJunsik on 2020/07/13.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

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

ListNode* delete_odd_node(ListNode* head) {
    ListNode* cur = head;
    ListNode* p = NULL, *removed = NULL;
    while (cur->link != NULL) {
        p = cur;
        cur = cur->link;
        p->link = cur->link;
        removed = cur;
        if (cur->link != NULL)
        {
            cur = cur->link;
            free(removed);
        }
        else
        {
            break;
        }
    }
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

void print_list(ListNode *head)
{
    for (ListNode *p = head->link; p != NULL; p = p->link)
    {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

int main()
{
    int n, value;
    scanf("%d", &n);
    ListNode* head = NULL;
    head = init_list(head);
    
    for(int i=0; i < n ; i++)
    {
        scanf("%d", &value);
        insert_last(head, value);
    }
    
    head = delete_odd_node(head);
    print_list(head);
    int c = list_count(head);
    for(int i = 0; i < c; i++)
    {
        head = delete_first(head);
    }
    return 0;
}

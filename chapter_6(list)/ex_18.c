//
//  ex_18.c
//  DS_study
//
//  Created by KimJunsik on 2020/07/13.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 오름차순 정렬된 2개의 연결리스트가 있을때, 정렬을 만족하면서 새로운 리스트로 기존 값을 옮겨 새로운 리스트를 만드는 함수 작성
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

ListNode* alternate(ListNode* p1, ListNode* p2)
{
    ListNode *head = NULL;
    head = init_list(head);
    ListNode* cur1 = p1->link, *cur2 = p2->link;
    while((cur1 != NULL) && (cur2 != NULL))
    {
        if(cur1->data < cur2->data)
        {
            insert_last(head, cur1->data);
            cur1 = cur1->link;
        }
        else
        {
            insert_last(head, cur2->data);
            cur2 = cur2->link;
        }
    }
    if(cur1 == NULL)
    {
        while(cur2 != NULL)
        {
            insert_last(head, cur2->data);
            cur2 = cur2->link;
        }
    }
    else
    {
        while(cur1 != NULL)
        {
            insert_last(head, cur1->data);
            cur1 = cur1->link;
        }
    }
    return head;
}

int main()
{
    ListNode* head1=NULL;
    ListNode* head2=NULL;
    head1 = init_list(head1);
    head2 = init_list(head2);
    int n1, n2, value;
    printf("list 1 input\n");
    scanf("%d", &n1);
    for(int i=0; i < n1; i++)
    {
        scanf("%d", &value);
        insert_last(head1, value);
    }
    printf("---------------------------\n");
    printf("list 2 input\n");
    scanf("%d", &n2);
    for(int i=0; i < n2; i++)
    {
        scanf("%d", &value);
        insert_last(head2, value);
    }
    
    ListNode* head = alternate(head1, head2);
    print_list(head);
    
    for(int i = 0; i < (n1+n2); i++)
    {
        head = delete_first(head);
    }
    return 0;
}

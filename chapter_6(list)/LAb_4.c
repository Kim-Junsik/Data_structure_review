//
//  LAb_4.c
//  DS_study
//
//  Created by KimJunsik on 2020/06/17.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 연결 리스트 역순 연산 작성하기
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
}ListNode;

ListNode* insert_first(ListNode* head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode *head)
{
    ListNode *cur = head;
    while(cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->link;
    }
    printf("NULL\n");
}

ListNode* reverse(ListNode* head)
{
    ListNode *p, *q, *r;
    p = head;
    q = NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}

int main()
{
    ListNode *head_1 = NULL;
    ListNode *head_2 = NULL;
    
    head_1 = insert_first(head_1, 10);
    head_1 = insert_first(head_1, 20);
    head_1 = insert_first(head_1, 30);
    print_list(head_1);
    
    head_2 = reverse(head_1);
    print_list(head_2);
    return 0;
}

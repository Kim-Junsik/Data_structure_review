//
//  LAb_3.c
//  DS_study
//
//  Created by KimJunsik on 2020/06/17.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 두 개의 연결 리스트를 하나로 합치는 함수 작성하기
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode
{
    element data;
    struct ListNode *link;
}ListNode;

ListNode* init_list(ListNode *head)
{
    head = (ListNode *)malloc(sizeof(ListNode));
    head->link = NULL;
    return head;
}

ListNode* insert_last(ListNode *head, element value)
{
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->data = value;
    new_node->link = NULL;
    
    ListNode *cur = head;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = new_node;
    return head;
}

void print_list(ListNode *head)
{
    ListNode* cur = head->link;
    while(cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->link;
    }
    printf("NULL\n");
}

ListNode* merge_list(ListNode *head_1, ListNode *head_2)
{
    if(head_1 == NULL)
        return head_2;
    else if(head_2 == NULL)
        return head_1;
    else
    {
        ListNode *merge_list = head_2->link;
        ListNode *cur = head_1->link;
        while(cur->link != NULL)
            cur = cur->link;
        cur->link = merge_list;
        free(head_2);
        return head_1;
    }
}

ListNode* del_list(ListNode *head)
{
    ListNode* del_node = NULL;
    while(head != NULL)
    {
        del_node = head;
        head = head->link;
        free(del_node);
    }
    return head;
}

int main()
{
    ListNode *head_1 = NULL;
    head_1 = init_list(head_1);
    ListNode *head_2 = NULL;
    head_2 = init_list(head_2);
    
    head_1 = insert_last(head_1, 10);
    head_1 = insert_last(head_1, 20);
    head_1 = insert_last(head_1, 30);
    print_list(head_1);
    
    head_2 = insert_last(head_2, 40);
    head_2 = insert_last(head_2, 50);
    head_2 = insert_last(head_2, 60);
    print_list(head_2);
    
    ListNode *total = merge_list(head_1, head_2);
    print_list(total);
    total = del_list(total);
    return 0;
}

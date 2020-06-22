//
//  program_6_7.c
//  DS_study
//
//  Created by KimJunsik on 2020/06/12.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 단순 연결 리스트 구현
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

ListNode* insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
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

ListNode* delete(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode *head)
{
    for (ListNode *p = head; p != NULL; p = p->link)
    {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

// 책 문제 추가 구현 --> '인덱스'를 받아 '인덱스'번째의 값을 반환하는 get_entry함수 구현
element get_entry(ListNode *head, int index)
{
    ListNode *cur = head;
    for (int i = 0; i < index; i++)
        cur = cur->link;
    return cur->data;
}

int main()
{
    ListNode *head = NULL;
    
    for (int i = 0; i < 5; i++)
    {
        head = insert_first(head, i);
        print_list(head);
    }
    
    printf("3rd value : %d\n", get_entry(head, 2));
    
    for (int i = 0; i < 5; i++)
    {
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}

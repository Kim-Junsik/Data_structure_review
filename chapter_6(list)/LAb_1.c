//
//  LAb_1.c
//  DS_study
//
//  Created by KimJunsik on 2020/06/17.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 단어를 저장하는 연결리스트 구현
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
}element;

typedef struct Node
{
    element data;
    struct Node *link;
}ListNode;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* init_list(ListNode *head)
{
    head = (ListNode*)malloc(sizeof(ListNode));
    head->link = NULL;
    return head;
}

ListNode* insert_last(ListNode *head, element value)
{
    ListNode *cur = head;
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->data = value;
    new_node->link = NULL;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = new_node;
    return head;
}

void print_list(ListNode* head)
{
    ListNode *cur = head->link;
    while(cur != NULL)
    {
        printf("%s -> ", cur->data.name);
        cur = cur->link;
    }
    printf("NULL\n");
}

void del_list(ListNode *head)
{
    ListNode* del_node = NULL;
    while(head != NULL)
    {
        del_node = head;
        head = head->link;
        free(del_node);
    }
}

int main()
{
    ListNode *head = NULL;
    head = init_list(head);
    element data;
    
    strcpy(data.name, "APPLE");
    head = insert_last(head, data);
    print_list(head);
    
    strcpy(data.name, "KIWI");
    head = insert_last(head, data);
    print_list(head);
    
    strcpy(data.name, "BANANA");
    head = insert_last(head, data);
    print_list(head);
    
    del_list(head);
    return 0;
}

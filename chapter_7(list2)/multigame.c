//
//  multigame.c
//  DS_study
//
//  Created by KimJunsik on 2020/08/16.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode
{
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    strcpy(node->data, data);
    if(head == NULL)
    {
        head = node;
        head->link = node;
    }
    else
    {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

int main()
{
    ListNode *head = NULL;
    head = insert_first(head, "KIM");
    head = insert_first(head, "PARK");
    head = insert_first(head, "CHOI");
    ListNode *p = head;
    for(int i=0; i < 10; i++)
    {
         printf("current player : %s\n", p->data);
        p=p->link;
    }
    return 0;
}

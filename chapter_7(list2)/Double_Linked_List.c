//
//  Double_Linked_List.c
//  DS_study
//
//  Created by KimJunsik on 2020/08/16.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode
{
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
}DListNode;

void init(DListNode* phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode* phead)
{
    DListNode* p;
    for(p = phead->rlink; p != phead; p = p->rlink)
    {
        printf("<- |%d| -> ", p->data);
    }
    printf("\n");
}

void dinsert(DListNode* before, element data)
{
    DListNode *newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->data = data;
    newNode->llink = before;
    newNode->rlink = before->rlink;
    before->rlink->llink = newNode;
    before->rlink = newNode;
}

void ddelete(DListNode* head, DListNode* removed)
{
    if(removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main()
{
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    printf("Add data\n");
    for(int i = 0; i < 5; i++)
    {
        dinsert(head, i);
        print_dlist(head);
    }
    printf("Delete data\n");
    for(int i = 0; i < 5; i++)
    {
        print_dlist(head);
        ddelete(head, head->rlink);
    }
    free(head);
    return 0;
}

//
//  LAb_2.c
//  DS_study
//
//  Created by KimJunsik on 2020/06/17.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

// 특정 값을 탐색하는 함수 작성
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode* link;
}ListNode;

// 리스트 초기화 함수 (더미 노드 생성)
ListNode* init_list(ListNode *head)
{
    head = (ListNode *)malloc(sizeof(ListNode));
    head->link = NULL;
    return head;
}

// 리스트 꼬리 추가 함수
ListNode* insert_last(ListNode *head, element value)
{
    // 추가할 노드 생성
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->data = value;
    new_node->link = NULL;
    
    // 꼬리를 가리키기 위한 변수
    ListNode *cur = head;
    // 꼬리 찾기
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    // 꼬리에 연결
    cur->link = new_node;
    // 연결 후 리스트 반환
    return head;
}

// 중간 리스트 삭제
ListNode* delete(ListNode *head, int idx)
{
    // 삭제할 노드 저장
    ListNode* del_node = head->link;
    // 삭제할 노드 이전의 노드 저장
    ListNode* pre = head;
    for(int i = 0; i < idx; i++)
    {
        del_node = del_node->link;
        pre = pre->link;
    }
    // 노드가 없다면 삭제하지 않고 함수 나감
    if(del_node == NULL || pre == NULL)
        return head;
    // 삭제할 노드 제외하고 노드 연결
    pre->link = del_node->link;
    // 노드 삭제
    free(del_node);
    // 삭제 연산 후 리스트 반환
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

ListNode* search_list(ListNode *head, element x)
{
    ListNode *cur = head->link;
    while(cur != NULL)
    {
        if(cur->data == x)
            return cur;
        else
            cur = cur->link;
    }
    return NULL;
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
    
    head = insert_last(head, 10);
    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_last(head, 50);
    printf("리스트 출력\n");
    print_list(head);
    
    head = delete(head, 4);
    printf("삭제 후 리스트 츨력\n");
    print_list(head);
    
    ListNode *cur = search_list(head, 30);
    if(cur != NULL)
        printf("find element %d\n", cur->data);
    else
        printf("not found element\n");
    
    del_list(head);
    return 0;
}

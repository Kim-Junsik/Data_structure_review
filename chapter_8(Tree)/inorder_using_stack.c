//
//  inorder_using_stack.c
//  DS_study
//
//  Created by KimJunsik on 2020/08/20.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p)
{
    if(top < SIZE-1)
        stack[++top] = p;
}

TreeNode* pop()
{
    TreeNode *p = NULL;
    if(top >= 0)
        p = stack[top--];
    return p;
}

void in_order_iter(TreeNode *root)
{
    while(1)
    {
        for(;root;root=root->left)
        {
            push(root);
        }
        root = pop();
        if(!root)
        {
            break;
        }
        printf("[%d] ", root->data);
        root = root->right;
    }
}

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main()
{
    printf("in_order = ");
    in_order_iter(root);
    printf("\n");
    return 0;
}

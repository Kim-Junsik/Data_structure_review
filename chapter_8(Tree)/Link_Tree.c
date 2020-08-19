//
//  Link_Tree.c
//  DS_study
//
//  Created by KimJunsik on 2020/08/19.
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

TreeNode n1 = {1,NULL,NULL};
TreeNode n2 = {4,&n1,NULL};
TreeNode n3 = {16,NULL,NULL};
TreeNode n4 = {25,NULL,NULL};
TreeNode n5 = {20,&n3,&n4};
TreeNode n6 = {15,&n2,&n5};
TreeNode *root = &n6;

void in_order(TreeNode *root)
{
    if(root != NULL)
    {
        in_order(root->left);
        printf("[%d] ", root->data);
        in_order(root->right);
    }
}

void pre_order(TreeNode *root)
{
    if(root != NULL)
    {
        printf("[%d] ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order(TreeNode *root)
{
    if(root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("[%d] ", root->data);
    }
}

int main()
{
    printf("in_order=");
    in_order(root);
    printf("\n");
    
    printf("pre_order=");
    pre_order(root);
    printf("\n");
    
    printf("post_order=");
    post_order(root);
    printf("\n");
    
    return 0;
}

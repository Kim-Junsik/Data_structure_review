//
//  program_6_3.c
//  DS_study
//
//  Created by KimJunsik on 2020/06/15.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   int insertchecking;
   struct node* next;
}node;

struct node* root = NULL;
int count = 0;

void insert(int data)
{
   node* newNode = (node*)malloc(sizeof(node));
   node* preNode = root;
   newNode->data = data;
   newNode->next = NULL;
   if (count == 0)
   {
      root = newNode;
   }
   else
   {
      for (int i = 1; i < count; i++)
      {
         preNode = preNode->next;
      }
      preNode->next = newNode;
   }
   count++;
}

void midinsert(int data, int index)
{
   if (index > count)
   {
      printf("error midinsert\n");
      return;
   }
   node* newNode = (node*)malloc(sizeof(node));
   node* preNode = root;
   newNode->data = data;
   newNode->insertchecking = 1;
   for (int i = 1; i < index - 1; i++)
   {
      if (i > count) break;
      preNode = preNode->next;
   }
   newNode->next = preNode->next;
   preNode->next = newNode;

   count++;
}

void print()
{
   node* curNode = root;
   int i;
   if (count == 0)
   {
      printf("none\n");
   }
   if ((curNode->data) != NULL)
   {
      for (i = 1, curNode; i <= count; i++, curNode = curNode->next)
      {
         if ((curNode->insertchecking) == 1)
         {
            printf("index : %d curNode->data : %d (insert)\n", i, curNode->data);
         }
         else
         {
            printf("index : %d curNode->data : %d\n", i, curNode->data);
         }
      }
   }
}

void deleteNode(int index)
{
   if (index > count)
   {
      printf("error deleteNode\n");
      return;
   }
   node* predelNode = root;
   node* delNode;
   int i;
   for (i = 1; i < index - 1; i++)
   {
      predelNode = predelNode->next;
   }
   delNode = predelNode->next;
   predelNode->next = delNode->next;
   free(delNode);
   count--;
}

void returnNode()
{
   node* curNode = root;
   node* delNode = root;
   while (delNode->next != NULL)
   {
      curNode = curNode->next;
      free(delNode);
      delNode = curNode;
   }
   count = 0;
}

int main()
{
   for (int i = 1; i < 10; i++)
   {
      insert(i);
   }
   printf("origin\n");
   print();
   midinsert(555, 5);
   printf("\n");
   printf("delete before\n");
   print();
   printf("\n");
   printf("delete after\n");
   deleteNode(7);
   print();
   returnNode();
   printf("\n");
   printf("return Node\n");
   print();
}

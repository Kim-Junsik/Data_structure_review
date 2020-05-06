//
//  program_3_8.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/29.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    int *p;
    p = (int *) malloc(sizeof(int));
    if(p==NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    
    for (int i = 0; i < SIZE ; i++)
    {
        p[i] = i;
    }
    
    for (int i = 0; i < SIZE ; i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
    free(p);
    return 0;
}

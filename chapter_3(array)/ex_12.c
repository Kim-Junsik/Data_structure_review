//
//  ex_12.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/29.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct _check
{
    int number;
    char st[20];
}check;

int main()
{
    check *c;
    c = (check*)malloc(sizeof(check));
    
    c->number = 100;
    strcpy(c->st, "just testing");
    printf("number : %d, string : %s\n", c->number, c->st);
    free(c);
    return 0;
}

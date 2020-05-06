//
//  program_3_9.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/29.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag
{
    char name[10];
    int age;
    double gpa;
}student;

int main()
{
    student *s;
    s = (student*)malloc(sizeof(student));
    if(s==NULL)
    {
        fprintf(stderr, "mallco failed");
        exit(1);
    }
    
    strcpy(s->name, "Park");
    s->age = 20;
    free(s);
    return 0;
}

//
//  ex_5.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/29.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

typedef struct _Person
{
    char name[10];
    int age;
    float salary;
}Person;

int main()
{
    Person p = {"aaa",30,250.4};
    printf("%s\n", p.name);
    printf("%d\n", p.age);
    printf("%f\n", p.salary);
    return 0;
}

//
//  ex_7.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/22.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int sum(int n)
{
    printf("%d\n", n);
    if(n<1) return 1;
    else return (n+sum(n-1));
}

int main()
{
    int re = sum(5);
    printf("sum : %d\n", re);
    return 0;
}

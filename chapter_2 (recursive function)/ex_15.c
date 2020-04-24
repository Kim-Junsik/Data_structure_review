//
//  ex_15.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/23.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int fib(int n)
{
    printf("fib(%d) is call\n",n);
    if(n==0) return 0;
    if(n==1) return 1;
    return (fib(n-1) + fib(n-2));
}

int main()
{
    int re = fib(6);
    printf("%d\n", re);
    return 0;
}

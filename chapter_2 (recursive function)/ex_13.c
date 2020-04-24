//
//  ex_13.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/23.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int loop(int n)
{
    if(n == 1) return n;
    else return n+loop(n-1);
}

int main()
{
    int n =0;
    scanf("%d", &n);
    int re = loop(n);
    printf("%d\n", re);
    return 0;
}

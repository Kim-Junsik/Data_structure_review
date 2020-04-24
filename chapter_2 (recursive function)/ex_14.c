//
//  ex_14.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/23.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

double loop(float n)
{
    if(n==1) return 1;
    else return ((1.0 / n) + loop(n-1));
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    double re = loop(n);
    printf("%f\n", re);
    return 0;
}

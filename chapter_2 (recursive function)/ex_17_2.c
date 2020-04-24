//
//  ex_17_2.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/23.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#define MAX 100

int bino(int n, int k)
{
    static int list[MAX][MAX];
    if(list[n][k] != 0) return list[n][k];
    else if(k == 0 || k == n) return list[n][k] = 1;
    else if(0<k && k<n) return list[n][k] = (bino(n-1, k-1) + bino(n-1, k));
    else return 0;
}

int main()
{
    int n = 5;
    int k = 2;
    int re = bino(n,k);
    printf("%d\n", re);
    return 0;
}

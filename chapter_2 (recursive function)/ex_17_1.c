//
//  ex_17(과제).c
//  DS_study
//
//  Created by KimJunsik on 2020/04/23.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int bino(int n, int k)
{
    if(k == 0 || k == n) return 1;
    else if(0<k && k<n) return (bino(n-1, k-1) + bino(n-1, k));
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

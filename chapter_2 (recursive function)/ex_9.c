//
//  ex_9.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/22.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int recursive(int n)
{
    printf("%d\n", n);
    if(n<1) return -1;
    else return (recursive(n-3)+1);
}

int main()
{
    int re = 0;
    re = recursive(10);
    printf("%d\n", re);
    return 0;
}

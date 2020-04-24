//
//  ex_8.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/22.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int recursive(int n)
{
    printf("%d\n", n);
    if(n<1) return 2;
    else return (2*recursive(n-1)+1);
}

int main()
{
    int re = recursive(5);
    printf("recursive : %d\n", re);
    return 0;
}

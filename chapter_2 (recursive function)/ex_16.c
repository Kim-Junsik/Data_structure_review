//
//  ex_16.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/23.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n = 0;
    int sum = 0;
    scanf("%d", &n);
    for(n; n>0; n--)
    {
        sum+=n;
    }
    printf("%d\n", sum);
    return 0;
}

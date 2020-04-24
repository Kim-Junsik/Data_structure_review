//
//  quiz_1.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/22.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int sub(int n)
{
    if(n<0) return 0;
    return n + sub(n-3);
}

int main()
{
    int re = sub(10);
    printf("quiz_1\n");
    printf("%d\n", re);
    return 0;
}

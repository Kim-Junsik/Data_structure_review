//
//  ex_10.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/22.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

void recursive(int n)
{
    if(n!=1) recursive(n-1);
    printf("%d\n", n);
}

int main()
{
    recursive(5);
    return 0;
}

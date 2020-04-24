//
//  ex_12.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/23.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

void unknown()
{
    int ch = 0;
    if((ch = getchar()) != '\n')
    {
        unknown();
    }
    putchar(ch);
}

int main()
{
    unknown();
    return 0;
}

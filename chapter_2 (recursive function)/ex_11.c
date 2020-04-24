//
//  ex_11.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/22.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

void asterisk(int i)
{
    if(i>1)
    {
        asterisk(i/2);
        asterisk(i/2);
    }
    printf("*");
}

int main()
{
    asterisk(5);
    return 0;
}

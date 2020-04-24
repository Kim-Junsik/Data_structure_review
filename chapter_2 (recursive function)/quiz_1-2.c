//
//  quiz_2.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/22.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int main()
{
    int re = 0;
    for(int i = 10; i>0 ;i-=3)
    {
        re+=i;
    }
    printf("quiz_2\n");
    printf("%d\n", re);
    return 0;
}

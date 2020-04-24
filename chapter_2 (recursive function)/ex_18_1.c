//
//  ex_18.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/23.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int Ackermann(int m, int n)
{
    if(m == 0) return n+1;
    else if(n == 0) return Ackermann(m-1, 1);
    else if(m >=1&& n >= 1) return Ackermann(m-1, Ackermann(m,n-1));
    else return 0;
}

int main()
{
    int re_1 = Ackermann(3,2);
    int re_2 = Ackermann(2,3);
    printf("%d, %d\n", re_1, re_2);
    return 0;
}

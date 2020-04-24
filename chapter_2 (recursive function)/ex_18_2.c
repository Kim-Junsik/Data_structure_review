//
//  ex_18_2.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/23.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int Ackermann(int _m, int _n)
{
    int list[1000];
    int idx = 0;
    list[idx++] = _m;
    list[idx] = _n;
    
    while(1)
    {
         if(idx == 0)
         {
            return list[idx];
         }
         else if(list[idx - 1] == 0)
         {
            list[idx - 1] = list[idx] + 1;
            idx = idx - 1;
         }
         else if(list[idx] == 0)
         {
            list[idx - 1] = list[idx - 1] - 1;
            list[idx] = 1;
         }
         else
         {
            list[idx + 1] = list[idx] - 1;
            list[idx] = list[idx - 1];
            list[idx - 1] = list[idx - 1] - 1;
            idx = idx + 1;
         }
     }
}

int main()
{
    int re_1 = Ackermann(3, 2);
    int re_2 = Ackermann(2, 3);
    printf("%d, %d\n", re_1, re_2);
    return 0;
}

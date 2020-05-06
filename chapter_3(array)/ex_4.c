//
//  ex_4.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/29.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

int main()
{
    int arr[10];
    arr[0] = 1;
    for (int i = 1; i < 10; i++)
    {
        arr[i] = arr[i-1]*2;
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

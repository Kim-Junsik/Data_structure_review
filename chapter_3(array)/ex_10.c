//
//  ex_10.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/29.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#define SIZE 10

int delete(int array[], int loc)
{
    int local = loc-1;
    
    if(array[local] == 0)
    {
        return 0;
    }
    else
    {
        int del_value = array[local];
        for (int i = local; i < SIZE-1; i++)
        {
            array[i] = array[i+1];
        }
        return del_value;
    }
}

int main()
{
    int array[SIZE] = {0,};
    int items = 0;
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = i+1;
        items++;
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    delete(array, 3);
    array[items-1] = 0;
    items--;
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

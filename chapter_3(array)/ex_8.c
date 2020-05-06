//
//  ex_8.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/29.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

#define SIZE 100

void insert(int array[], int loc, int value)
{
    if (array[loc-1] == 0)
    {
        array[loc-1] = value;
        return;
    }
    else
    {
        for(int i = SIZE-1; i > loc-1 ; i--)
        {
            array[i] = array[i-1];
        }
        
        array[loc-1] = value;
    }
}

int main()
{
    int array[SIZE] = {0,};
    
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = i+1;
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    insert(array, 11, 7777);
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

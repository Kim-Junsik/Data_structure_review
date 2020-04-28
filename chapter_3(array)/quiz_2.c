//
//  quiz_2.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/28.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void matrix_print(int **A)
{
    printf("=========================\n");
    for (int r = 0; r<ROWS; r++)
    {
        for (int c = 0; c<COLS; c++)
        {
            printf("%d ", A[r][c]);
        }
        printf("\n");
    }
}

int** add_matrix(int a[ROWS][COLS], int b[ROWS][COLS])
{
    int **c = (int**)malloc (sizeof(int*) * ROWS);
    
    for (int k = 0; k < COLS; k++)
    {
        c[k] = (int*)malloc (sizeof(int) * COLS);
    }
    
    for (int i = 0; i<ROWS ; i++)
    {
        for (int j = 0; j<COLS ; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

int main()
{
    int array1[ROWS][COLS] = {{2,3,0},
                            {8,9,1},
                            {7,0,5}};
    int array2[ROWS][COLS] = {{4,0,2},
                            {3,0,3},
                            {2,3,1}};
    
    int **array3 = add_matrix(array1, array2);
    
    matrix_print(array3);
    
    for (int i = 0; i < COLS; i++)
    {
        free(array3[i]);
    }
    free(array3);
    
    return 0;
}

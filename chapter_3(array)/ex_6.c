//
//  ex_6.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/29.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

typedef struct _complex
{
    float real;
    float imaginary;
}Complex;

int main()
{
    Complex c1 = {3.4, 2.6};
    Complex c2 = {2.2, 1.6};
    
    printf("real : %f, imaginary : %f\n", c1.real, c1.imaginary);
    printf("real : %f, imaginary : %f\n", c2.real, c2.imaginary);
    return 0;
}

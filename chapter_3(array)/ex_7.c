//
//  ex_7.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/29.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _complex
{
    float real;
    float imaginary;
}Complex;

Complex* complex_add(Complex *c1, Complex *c2)
{
    Complex *c3;
    c3 = (Complex*)malloc(sizeof(Complex));
    
    c3->real = c1->real + c2->real;
    c3->imaginary = c1->imaginary + c2->imaginary;
    
    return c3;
}

int main()
{
    Complex c1 = {3.4, 2.6};
    Complex c2 = {2.2, 1.6};
    
    Complex *c3 = complex_add(&c1, &c2);
    printf("real : %f, imaginary : %f\n", c3->real, c3->imaginary);
    free(c3);
    return 0;
}

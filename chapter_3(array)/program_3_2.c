//
//  program_3_2.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/27.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct
{
    int degree;
    float coef[MAX_DEGREE];
}polynominal;

polynominal poly_add1(polynominal A, polynominal B)
{
    polynominal C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree);
    while(Apos <= A.degree && Bpos <= B.degree)
    {
        if(degree_a > degree_b)
        {
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if(degree_a == degree_b)
        {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_b--; degree_a--;
        }
        else
        {
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    
    return C;
}

// 계수가 0이면 출력하지 않기 위해 추가한 함수
void print_poly_1(polynominal p)
{
    for(int i = p.degree; i>0;i--)
    {
        if(p.coef[p.degree - i] !=0)
            printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }
    printf("%3.1f \n", p.coef[p.degree]);
}
// 계수가 0이어도 출력시키는 함수 (위 함수와 비교하기위해)
void print_poly_2(polynominal p)
{
    for(int i = p.degree; i>0;i--)
    {
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }
    printf("%3.1f \n", p.coef[p.degree]);
}

// 배열에 계수가 0이어도 메모리르 잡고있어 공간의 낭비가 심하다는 단점이있다.
// 공간상의 단점은 있지만 전체적은 알고리즘은 쉬워진다.
int main()
{
    polynominal a = {3,{1,0,2,3}};
    polynominal b = {3,{-1,0,4,-1}};
    polynominal c;
    print_poly_1(a);
    print_poly_2(a);
    print_poly_1(b);
    print_poly_2(b);
    c = poly_add1(a, b);
    printf("-----------------------------------------------------\n");
    print_poly_1(c);
    print_poly_2(c);
    return 0;
}

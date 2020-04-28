//
//  program_3_3.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/27.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct
{
    float coef;
    int expon;
}polynominal;

polynominal terms[MAX_TERMS] = {{8,3},{7,1},{1,0},{10,3},{3,2},{1,0}};
int avail = 6;

char compare(int a, int b)
{
    if(a>b) return '>';
    else if(a==b) return '=';
    else return '<';
}

void attach(float coef, int expon)
{
    if(avail > MAX_TERMS)
    {
        fprintf(stderr, "항의 개수가 너무 많습니다\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail++;
}

void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
    float tempcoef;
    *Cs = avail;
    while (As <= Ae && Bs <= Be)
        switch (compare(terms[As].expon, terms[Bs].expon))
        {
            case '>':
                attach(terms[As].coef, terms[As].expon);
                As++;
                break;
            case '=':
                tempcoef = terms[As].coef + terms[Bs].coef;
                if(tempcoef)
                    attach(tempcoef, terms[As].expon);
                As++; Bs++;; break;
            case '<':
                attach(terms[Bs].coef, terms[Bs].expon);
                Bs++; break;
        }
    
    for (;As<=Ae;As++)
        attach(terms[As].coef, terms[As].expon);
    for (;Bs<=Be;Bs++)
        attach(terms[Bs].coef, terms[Bs].expon);
    
    *Ce = avail - 1;
}

void print_poly(int s, int e)
{
    for (int i = s; i<e; i++)
    {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

// 배열을 2개 선언해서 각각 계수와 차수를 저장하면 공간을 절약할 수 있다.
// 하지만 이는 2개의 배열이 필요하며 상황에 따라 공간복잡도가 더 늘어날 수 있다.
// 또한 이는 배열의 인덱스 변수를 직접 관리해줘야 하며, 알고리즘의 구현 방법이 더욱 어려워 질 수 있다.
int main()
{
    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
    poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
    print_poly(As, Ae);
    print_poly(Bs, Be);
    printf("-------------------------------------------------\n");
    print_poly(Cs, Ce);
    return 0;
}

//
//  quiz_1.c
//  DS_study
//
//  Created by KimJunsik on 2020/04/26.
//  Copyright © 2020 KimJunsik. All rights reserved.
//

#include <stdio.h>

typedef struct _Point
{
    int x;
    int y;
}Point;

double get_distance(Point p1, Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

int main()
{
    Point p1 = {1,2};
    Point p2 = {9,8};
    float distance = get_distance(p1, p2);
    printf("%f\n", distance);
}

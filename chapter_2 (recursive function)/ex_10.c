#include <stdio.h>

void recursive(int n)
{
    if(n!=1) recursive(n-1);
    printf("%d\n", n);
}

int main()
{
    recursive(5);
    return 0;
}

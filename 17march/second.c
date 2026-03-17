#include <stdio.h>

void switchNumbers(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 5, y = 10;
    printf("Before switching: x = %d, y = %d\n", x, y);
    switchNumbers(&x, &y);
    printf("After switching: x = %d, y = %d\n", x, y);
    return 0;
}
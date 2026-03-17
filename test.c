#include <stdio.h>

void increment();

int main()
{
    int numbers[] = {1,6,3,4};
    int *p = numbers;
    (*p)++;

    printf("%d", *p);


    return 0;
}
#include <stdio.h>

bool isEven(int num)
{
    return num % 2 == 0;
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if(isEven(number))
    {
        printf("The number is even.\n");
    }
    else
    {
        printf("The number is odd.\n");
    }
    return 0;
}
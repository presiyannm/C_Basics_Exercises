#include <stdio.h>

void numberInBaseTwo(int num)
{
    int binary[32];
    int i = 0;
    while(num > 0)
    {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("The number in base 2 is: ");
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
}


int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    numberInBaseTwo(number);
    return 0;
}
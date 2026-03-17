#include <stdio.h>

bool checkIfNumberIsSimple(int num)
{
    if(num <= 1)
    {
        return false;
    }
    for(int i = 2; i <= num/2; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int getDigitsSum(int num)
{
    int sum = 0;
    while(num > 0)
    {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

int getDigitsNumber(int num)
{
    int count = 0;
    while(num > 0)
    {
        count++;
        num = num / 10;
    }
    return count;
}

int reverseNumber(int num)
{
    int reversed = 0;
    while(num > 0)
    {
        reversed = reversed * 10 + num % 10;
        num = num / 10;
    }
    return reversed;
}

int main()
{
    int number;
    printf("Enter a number: ");

    if(scanf("%d", &number) < 0)
    {
        printf("Number must be an integer\n");
        return 1;
    }

    if(checkIfNumberIsSimple(number))
    {
        printf("The number is simple.\n");
    }
    else
    {
        printf("The number is not simple.\n");
    }

    printf("The sum of the digits is: %d\n", getDigitsSum(number));
    printf("The number of digits is: %d\n", getDigitsNumber(number));
    printf("The reversed number is: %d\n", reverseNumber(number));

    return 0;
}
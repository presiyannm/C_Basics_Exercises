#include <stdio.h>
#include <math.h>

int sum(int a, int b)
{
    return a + b;
}

int difference(int a, int b)
{
    return a - b;
}

int product(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    if(b == 0)
    {
        printf("Cannot divide by zero\n");
        return 0;
    }
    return a / b;
}

double customPow(int a, int b) {
    if (b < 0) {
        // Handling negative exponents: a^-b = 1 / a^b
        return 1.0 / customPow(a, -b); 
    }

    double result = 1.0; // Use double here to avoid overflow
    for(int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

double getRemainder(int a, int b) {
    if(b == 0) {
        printf("Error: Division by zero\n");
        return 0.0;
    }
    return (double)(a % b);
}

int main()
{
    int numberOfChoice;
    int a;
    int b;
    printf("Enter number a: ");
    scanf("%d", &a);
    printf("Enter number b: ");
    scanf("%d", &b);
    printf("Choose from 1 - Sum, 2 - Difference, 3 - Product, 4 - Divison, 5 - Pow, 6 - Biggest Remainder: ");
    scanf("%d", &numberOfChoice);

    switch(numberOfChoice)
    {
        case 1:
            printf("The sum is: %d\n", sum(a, b));
            break;
        case 2:
            printf("The difference is: %d\n", difference(a, b));
            break;
        case 3:
            printf("The product is: %d\n", product(a, b));
            break;
        case 4:
            printf("The division is: %d\n", division(a, b));
            break;
        case 5:
            printf("The pow is: %.2f\n", customPow(a, b));
            break;
        case 6:
            printf("The biggest remainder is: %.2f\n", getRemainder(a, b));
            break;
        default:
            printf("Invalid choice\n");
    }
}
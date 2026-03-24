#include <stdio.h>

int main(void)
{
    double a, b;
    double *pa = &a;
    double *pb = &b;

    printf("Enter two numbers: ");
    if (scanf("%lf %lf", pa, pb) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Sum: %.2f\n", *pa + *pb);
    printf("Difference: %.2f\n", *pa - *pb);
    printf("Multiplication: %.2f\n", *pa * *pb);

    if (*pb == 0)
    {
        printf("Division: impossible (division by zero).\n");
    }
    else
    {
        printf("Division: %.2f\n", *pa / *pb);
    }

    return 0;
}

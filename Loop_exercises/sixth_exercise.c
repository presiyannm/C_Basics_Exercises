#include <stdio.h>

int main() {
    double start, end, x, f_x;

    printf("Enter the start of the interval: ");
    scanf("%lf", &start);
    
    printf("Enter the end of the interval: ");
    scanf("%lf", &end);

    if (start > end)
    {
        double temp = start;
        start = end;
        end = temp;
    }

    printf("\nValues of the function f(x) = x*x - 4:\n");

    for (x = start; x <= end + 0.0001; x+= 0.001)
    {    
        f_x = (x * x) - 4;
        printf("f(%.2lf) = %.4lf\n", x, f_x);
    }

    return 0;
}
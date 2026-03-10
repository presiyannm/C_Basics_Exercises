#include <stdio.h>
int main() {
    int numbers[50];
    int count = 0;
    int number;
    int sum = 0;
    
    printf("Enter numbers (0 to stop): ");
    while (scanf("%d", &number) == 1 && number != 0 && count < 50)
     {
        numbers[count++] = number;
    }
    for (int i = 0; i <= count; i++)
    {
        sum += numbers[i];
    }
    printf("Sum of numbers: %d\n", sum);

    return 0;
}
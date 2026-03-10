#include <stdio.h>
int main() {
    int firstNumber, secondNumber;
    int sum = 0;
    printf("Enter two numbers: ");
    scanf("%d %d", &firstNumber, &secondNumber);
    
    for (int i = firstNumber+1; i < secondNumber; i++)
    {
        sum += i;
    }
    
    printf("Sum: %d\n", sum);
    return 0;
}
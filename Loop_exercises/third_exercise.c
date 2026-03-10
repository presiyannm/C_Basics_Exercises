#include <stdio.h>
int main() {
    int firstNumber, secondNumber;
    int sumOfEvens = 0;
    int multiplicationOfOdds = 1;
    printf("Enter two numbers: ");
    scanf("%d %d", &firstNumber, &secondNumber);
    
    for (int i = firstNumber+1; i < secondNumber; i++)
    {
        if (i % 2 == 0) 
        {
            sumOfEvens += i;
        } 
        else 
        {
            multiplicationOfOdds *= i;
        }
    }
    
    printf("Sum of evens: %d\n", sumOfEvens);
    printf("Multiplication of odds: %d\n", multiplicationOfOdds);
    return 0;
}
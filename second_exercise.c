#include <stdio.h>
int main() {
    int number;
    int remainder;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    remainder = number % 8;

    if (remainder > 4)
    {
        printf("The remainder is greater than 4.\n");
    }
    return 0;
}
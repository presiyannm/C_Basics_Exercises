#include <stdio.h>
int main() {
    int n,k;
    int numbers[50];
    int numbers_greater_than_k = 0;
    printf("Enter the numbers N and K: ");
    scanf("%d %d", &n, &k);

    numbers[0] = k;
    numbers[1] = k;

    for  (int i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > k && numbers[i] % 3 == 0)
        {
            numbers_greater_than_k++;
        }
    }
    
    printf("Count of numbers greater than K and divisible by 3: %d\n", numbers_greater_than_k);
    return 0;
}
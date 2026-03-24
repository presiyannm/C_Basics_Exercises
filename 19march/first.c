#include <stdio.h>
#include <stdlib.h>

void checkBiggerAndSmallestNumber(int* numbers, int size)
{
    int biggest = numbers[0];
    int smallest = numbers[0];
    for(int i = 1; i < size; i++)
    {
        if(numbers[i] > biggest)
        {
            biggest = numbers[i];
        }
        if(numbers[i] < smallest)
        {
            smallest = numbers[i];
        }
    }
    printf("The biggest number is: %d\n", biggest);
    printf("The smallest number is: %d\n", smallest);
}

int main()
{
    int count = 0;
    int *numbers = (int*)malloc(10 * sizeof(int));
    for(int i = 0; i < 10; i++)
    {
        
        printf("Enter a number: ");
        if(scanf("%d", &numbers[i]) != 1) 
        {
           break;
        }

        if(numbers[i] == 0)
        {
            break;
        }
        count++;
    }

    checkBiggerAndSmallestNumber(numbers, count);
    free(numbers);
    return 0;
}
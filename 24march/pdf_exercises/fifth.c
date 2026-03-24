#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        return 0;
    }

    int *numbers = (int*)malloc(n * sizeof(int));
    if (numbers == NULL)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
       printf("Enter number: ");
       scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (numbers[j] < numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    int k;
    printf("Enter which element to find: ");
    scanf("%d", &k);

    printf("Element you want to find is: %d\n", numbers[k]);

    free(numbers);
    return 0;
}
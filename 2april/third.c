#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    int *array = (int *)malloc(n * sizeof(int));

    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &array[i]) != 1)
        {
            printf("Invalid input.\n");
            free(array);
            return 1;
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("N must be positive.\n");
        return 1;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        return 1;
    }

    for(int i = 0; i < n; i++)
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter number for moves: ");
    scanf("%d", &k);
    
    k = ((k % n) + n) % n;

    int *rotated = (int*)malloc(n * sizeof(int));
    if (rotated == NULL)
    {
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        int newIndex = (i + k) % n;
        rotated[newIndex] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = rotated[i];
    }

    printf("Array after rotation:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(rotated);
    free(arr);
    return 0;
}

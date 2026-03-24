#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    for(int i = n-1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    return 0;
}
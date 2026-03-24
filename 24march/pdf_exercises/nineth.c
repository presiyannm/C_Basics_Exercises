#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("No elements.\n");
        return 0;
    }

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

    int currStart = 0;
    int currLen = 1;

    int bestStart = 0;
    int bestLen = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            currLen++;
        }
        else
        {
            currLen = 1;
            currStart = i;
        }

        if (currLen > bestLen)
        {
            bestLen = currLen;
            bestStart = currStart;
        }
    }

    printf("Longest sequence: ");
    for (int i = bestStart; i < bestStart + bestLen; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

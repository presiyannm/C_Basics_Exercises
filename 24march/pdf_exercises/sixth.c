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

    int currIncStart = 0;
    int currIncLen = 1;
    int bestIncStart = 0;
    int bestIncLen = 1;

    int currDecStart = 0;
    int currDecLen = 1;
    int bestDecStart = 0;
    int bestDecLen = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            currIncLen++;
        }
        else
        {
            currIncLen = 1;
            currIncStart = i;
        }

        if (currIncLen > bestIncLen)
        {
            bestIncLen = currIncLen;
            bestIncStart = currIncStart;
        }

        if (arr[i] < arr[i - 1])
        {
            currDecLen++;
        }
        else
        {
            currDecLen = 1;
            currDecStart = i;
        }

        if (currDecLen > bestDecLen)
        {
            bestDecLen = currDecLen;
            bestDecStart = currDecStart;
        }
    }

    if (bestIncLen >= bestDecLen)
    {
        printf("Longest monotonic subsequence is increasing.\n");
        printf("Length: %d\n", bestIncLen);
        printf("Elements: ");
        for (int i = bestIncStart; i < bestIncStart + bestIncLen; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Longest monotonic subsequence is decreasing.\n");
        printf("Length: %d\n", bestDecLen);
        printf("Elements: ");
        for (int i = bestDecStart; i < bestDecStart + bestDecLen; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}


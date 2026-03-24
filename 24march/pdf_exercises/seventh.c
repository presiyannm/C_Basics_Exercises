#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    bool found = false;
    int tries = 0;
    int k;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    if (n < 3)
    {
        printf("Need at least 3 numbers.\n");
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

    printf("Enter number to try and find: ");
    scanf("%d", &k);

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int m = j + 1; m < n; m++)
            {
                tries++;
                if (arr[i] + arr[j] + arr[m] == k)
                {
                    printf("Numbers that sum to %d are: %d, %d and %d\n", k, arr[i], arr[j], arr[m]);
                    printf("Tried %d triple(s).\n", tries);
                    found = true;
                    break;
                }
            }

            if (found)
            {
                break;
            }
        }

        if (found)
        {
            break;
        }
    }

    if (!found)
    {
        printf("Impossible to reach %d with any 3 numbers.\n", k);
        printf("Tried all %d triple(s).\n", tries);
    }

    free(arr);
    return 0;
}

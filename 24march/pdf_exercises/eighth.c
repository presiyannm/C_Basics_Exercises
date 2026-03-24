#include <stdio.h>

int main()
{
    int arr[20];

    for (int i = 10; i < 20; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        int n, p;
        printf("Enter number (0 to stop): ");
        scanf("%d", &n);

        if (n == 0)
        {
            break;
        }

        printf("Enter position (0-19): ");
        scanf("%d", &p);

        if (p < 0 || p >= 20)
        {
            printf("Invalid position. Try again.\n");
            continue;
        }

        arr[p] = n;
    }

    printf("Array: ");
    int hasPrinted = 0;
    for (int i = 0; i < 20; i++)
    {
        if (arr[i] != 0)
        {
            printf("%d ", arr[i]);
            hasPrinted = 1;
        }
    }

    if (!hasPrinted)
    {
        printf("(no non-zero elements)");
    }
    printf("\n");

    return 0;
}
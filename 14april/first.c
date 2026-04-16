#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    printf("Enter the size of the array NxN: ");

    scanf("%d", &n);
    
    int array[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter number: ");
            scanf("%d", &array[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Number of the main diagonal is: %d\n", array[i][i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        printf("Number of the anti-diagonal is: %d\n", array[i][n - 1 - i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i <= j)
            {
                printf("Number of the upper triangular matrix is: %d\n", array[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i >= j)
            {
                printf("Number of the lower triangular matrix is: %d\n", array[i][j]);
            }
        }
    }
    
    int* sums = (int*)malloc(2 * n * sizeof(int));
    if (sums == NULL)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += array[i][j];
        }
        sums[i] = sum;
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += array[j][i];
        }
        sums[n + i] = sum;
    }

    printf("Sums of rows and columns: ");
    for (int i = 0; i < 2 * n; i++)
    {
    printf("%d ", sums[i]);
    }
    printf("\n");
    
    bool isMagic = true;

    for(int i = 0; i < 2 * n - 1; i++)
    {
        if(sums[i] != sums[i + 1])
        {
            isMagic = false;
            break;
        }
    }

    if(isMagic)
    {
        printf("The matrix is a magic square.\n");
    }
    else
    {
        printf("The matrix is not a magic square.\n");
    }

    free(sums);
    
    return 0;
}
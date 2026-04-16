#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n = 3, m = 3;
    int array[n][m];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    int maxElement = array[0][0];
    int minElement = array[0][0];
    int maxRow = 0;
    int minRow = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (array[i][j] > maxElement)
            {
                maxElement = array[i][j];
                maxRow = i;
            }
            if (array[i][j] < minElement)
            {
                minElement = array[i][j];
                minRow = i;
            }
        }
    }

    if (maxRow != minRow)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = array[maxRow][j];
            array[maxRow][j] = array[minRow][j];
            array[minRow][j] = temp;
        }
    }

    printf("Max element: %d (row %d)\n", maxElement, maxRow);
    printf("Min element: %d (row %d)\n", minElement, minRow);
    printf("Array after swapping rows:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
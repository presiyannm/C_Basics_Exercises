#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n,m;
    printf("Enter the size of the array NxM: ");
    scanf("%d %d", &n, &m);
    int array[n][m];
    bool columnDecreasing = true;
    bool rowIncreasing = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Enter number: ");
            scanf("%d", &array[i][j]);
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           if (array[i][j] >= array[i-1][j])
           {
               columnDecreasing = false;
               break;
           }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
           if (array[i][j] <= array[i][j-1])
           {
               rowIncreasing = false;
               break;
           }
        }
    }

    if(rowIncreasing)
    {
        printf("The rows are increasing.\n");
    }
    else
    {
        printf("The rows are not increasing.\n");
    }
    
    if(columnDecreasing)
    {
        printf("The columns are decreasing.\n");
    }
    else
    {
        printf("The columns are not decreasing.\n");
    }

    return 0;
}
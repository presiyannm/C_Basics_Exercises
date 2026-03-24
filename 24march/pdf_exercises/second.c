#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    bool relations = true;
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
        if(i%2 != 0)
        {
            scanf("%d", &arr[i]);
            if(arr[i] <= arr[i-1])
            {
                relations = false;
            }
        }

        else if (i%2 == 0 && i !=0)
        {
            scanf("%d", &arr[i]);
            if(arr[i] >= arr[i-1])
            {
                relations = false;
            }
        }

        else
        {
            scanf("%d", &arr[i]);
        }
             
    }

    printf("Relations are: %s\n", relations ? "true" : "false");
    free(arr);
    return 0;
}

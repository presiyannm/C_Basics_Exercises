#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sizeOfArray;
    printf("Enter size of array: ");

    if (scanf("%d", &sizeOfArray) != 1 || sizeOfArray <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    int *array = (int *)malloc(sizeOfArray * sizeof(int));

    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("Enter element %d: ", i + 1);

        if (scanf("%d", &array[i]) != 1)
        {
            printf("Invalid input.\n");
            free(array);
            return 1;
        }

        if(i % 2 != 0)
        {
            if(array[i] < array[i-1])
            {
                printf("This number must be bigger than the previous one.\n");
                free(array);
                return 1;
            }
        }
        else if(i % 2 == 0 && i != 0)
        {
            if(array[i] > array[i-1])
            {
                printf("This number must be smaller than the previous one.\n");
                free(array);
                return 1;
            }
        }
    }


    printf("Array elements:\n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}

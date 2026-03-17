#include <stdio.h>

void SumOfArray(int arr[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    printf("The sum of the array is: %d\n", sum);
}

void BiggestOfArray(int arr[], int size)
{
    int biggest = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > biggest)
        {
            biggest = arr[i];
        }
    }
    printf("The biggest number in the array is: %d\n", biggest);
}

void SmallestOfArray(int arr[], int size)
{
    int smallest = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    printf("The smallest number in the array is: %d\n", smallest);
}

void EvensOfArray(int arr[], int size)
{
    int evenCount = 0;
    printf("The even numbers in the array are: ");
    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
        {
            evenCount++;
        }
    }
    printf("The count of even numbers in the array is: %d\n", evenCount);
}

void reverseArray(int arr[], int size)
{
    printf("The array in reverse order is: ");
    for(int i = size - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int numbers[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    SumOfArray(numbers, n);
    BiggestOfArray(numbers, n);
    SmallestOfArray(numbers, n);
    EvensOfArray(numbers, n);
    reverseArray(numbers, n);

    return 0;
}
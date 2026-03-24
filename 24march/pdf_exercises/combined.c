#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void runFirst();
void runSecond();
void runThird();
void runFourth();
void runFifth();
void runSixth();
void runSeventh();
void runEighth();
void runNineth();

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Combined Menu (24march/pdf_exercises) ---\n");
        printf("1. Sort ascending + first element + size\n");
        printf("2. Check zig-zag relations a0 < a1 > a2 < ...\n");
        printf("3. Print array in reverse order\n");
        printf("4. Rotate array by K positions\n");
        printf("5. Sort descending and print element by index\n");
        printf("6. Longest monotonic (increasing/decreasing) subsequence\n");
        printf("7. Find 3 numbers with sum K\n");
        printf("8. Modify fixed array by value/position until 0\n");
        printf("9. Longest sequence of equal consecutive elements\n");
        printf("0. Exit\n");
        printf("Choose exercise: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice.\n");
            while (getchar() != '\n')
            {
            }
            continue;
        }

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
            case 1: runFirst(); break;
            case 2: runSecond(); break;
            case 3: runThird(); break;
            case 4: runFourth(); break;
            case 5: runFifth(); break;
            case 6: runSixth(); break;
            case 7: runSeventh(); break;
            case 8: runEighth(); break;
            case 9: runNineth(); break;
            default: printf("Exercise not found.\n"); break;
        }
    }

    return 0;
}

void runFirst()
{
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        return;
    }

    int *numbers = (int*)malloc(n * sizeof(int));
    if (numbers == NULL)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter number: ");
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    printf("Sorted numbers: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("First number of array is: %d\n", numbers[0]);
    printf("The size of array is: %d\n", n);

    free(numbers);
}

void runSecond()
{
    int n;
    bool relations = true;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        return;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter number: ");
        if (i % 2 != 0)
        {
            scanf("%d", &arr[i]);
            if (arr[i] <= arr[i - 1])
            {
                relations = false;
            }
        }
        else if (i % 2 == 0 && i != 0)
        {
            scanf("%d", &arr[i]);
            if (arr[i] >= arr[i - 1])
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
}

void runThird()
{
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        return;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

void runFourth()
{
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("N must be positive.\n");
        return;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter number for moves: ");
    scanf("%d", &k);

    k = ((k % n) + n) % n;

    int *rotated = (int*)malloc(n * sizeof(int));
    if (rotated == NULL)
    {
        free(arr);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int newIndex = (i + k) % n;
        rotated[newIndex] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = rotated[i];
    }

    printf("Array after rotation:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(rotated);
    free(arr);
}

void runFifth()
{
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        return;
    }

    int *numbers = (int*)malloc(n * sizeof(int));
    if (numbers == NULL)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter number: ");
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (numbers[j] < numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    int k;
    printf("Enter which element to find: ");
    scanf("%d", &k);

    if (k < 0 || k >= n)
    {
        printf("Invalid index.\n");
        free(numbers);
        return;
    }

    printf("Element you want to find is: %d\n", numbers[k]);

    free(numbers);
}

void runSixth()
{
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        return;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        return;
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
}

void runSeventh()
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
        return;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        return;
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
}

void runEighth()
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
}

void runNineth()
{
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("No elements.\n");
        return;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        return;
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
}

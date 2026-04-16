#include <math.h>
#include <stdio.h>

void runFirst(void);
void runSecond(void);
void runThird(void);
void runFourth(void);

static void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

static int readSevenNumbers(int arr[7])
{
    printf("Enter 7 integers in range [-5000..5000]:\n");
    for (int i = 0; i < 7; i++)
    {
        printf("n[%d] = ", i);
        if (scanf("%d", &arr[i]) != 1)
        {
            clearInputBuffer();
            return 0;
        }

        if (arr[i] < -5000 || arr[i] > 5000)
        {
            printf("Number out of range.\n");
            clearInputBuffer();
            return 0;
        }
    }

    clearInputBuffer();
    return 1;
}

int main(void)
{
    int choice;

    while (1)
    {
        printf("\n--- Combined Menu (1april/lu6.DOCX tasks) ---\n");
        printf("1. Sum of 7 numbers\n");
        printf("2. Maximum of 7 numbers\n");
        printf("3. Average of 7 numbers\n");
        printf("4. Value closest to average and its position\n");
        printf("0. Exit\n");
        printf("Choose exercise: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid menu input.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

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
            default: printf("Exercise not found.\n"); break;
        }
    }

    return 0;
}

void runFirst(void)
{
    int arr[7];
    int sum = 0;

    if (!readSevenNumbers(arr))
    {
        printf("Failed to read numbers.\n");
        return;
    }

    for (int i = 0; i < 7; i++)
    {
        sum += arr[i];
    }

    printf("Sum: %d\n", sum);
}

void runSecond(void)
{
    int arr[7];

    if (!readSevenNumbers(arr))
    {
        printf("Failed to read numbers.\n");
        return;
    }

    int maxValue = arr[0];
    for (int i = 1; i < 7; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }

    printf("Max value: %d\n", maxValue);
}

void runThird(void)
{
    int arr[7];
    int sum = 0;

    if (!readSevenNumbers(arr))
    {
        printf("Failed to read numbers.\n");
        return;
    }

    for (int i = 0; i < 7; i++)
    {
        sum += arr[i];
    }

    double avg = sum / 7.0;
    printf("Average: %.3f\n", avg);
}

void runFourth(void)
{
    int arr[7];
    int sum = 0;

    if (!readSevenNumbers(arr))
    {
        printf("Failed to read numbers.\n");
        return;
    }

    for (int i = 0; i < 7; i++)
    {
        sum += arr[i];
    }

    double avg = sum / 7.0;
    int closestValue = arr[0];
    int closestIndex = 0;
    double bestDiff = fabs(arr[0] - avg);

    for (int i = 1; i < 7; i++)
    {
        double diff = fabs(arr[i] - avg);
        if (diff < bestDiff)
        {
            bestDiff = diff;
            closestValue = arr[i];
            closestIndex = i;
        }
    }

    printf("Average: %.3f\n", avg);
    printf("Closest value: %d at position %d\n", closestValue, closestIndex + 1);
}

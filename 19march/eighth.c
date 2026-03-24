#include <stdio.h>

int main()
{
    int poolVolume;
    int firstPipeFlowRate;
    int secondPipeFlowRate;
    int hoursForWorkerToComeBack;

    printf("Enter the pool volume in liters: ");
    if(scanf("%d", &poolVolume) < 0)
    {
        printf("Invalid input for pool volume. Please enter a non-negative number.\n");
        return 1;
    }

    printf("Enter the flow rate of the first pipe in liters per hour: ");
    if(scanf("%d", &firstPipeFlowRate) < 0)
    {
        printf("Invalid input for the first pipe flow rate. Please enter a non-negative number.\n");
        return 1;
    }

    printf("Enter the flow rate of the second pipe in liters per hour: ");
    if(scanf("%d", &secondPipeFlowRate) < 0)
    {
        printf("Invalid input for the second pipe flow rate. Please enter a non-negative number.\n");
        return 1;
    }

    int totalFlowRate = firstPipeFlowRate + secondPipeFlowRate;
    if(totalFlowRate == 0)
    {
        printf("Both pipes have a flow rate of 0. The pool will never be filled.\n");
        return 1;
    }

    printf("Enter the number of hours the worker will be away: ");
    if(scanf("%d", &hoursForWorkerToComeBack) < 0)
    {
        printf("Invalid input for hours. Please enter a non-negative number.\n");
        return 1;
    }

    int filledVolume = totalFlowRate * hoursForWorkerToComeBack;
    if(filledVolume >= poolVolume)
    {
        printf("The pool is full. %.2f%% of the pool is filled.\n", (double)poolVolume / filledVolume * 100);
    }
    else
    {
        printf("The pool is not full. %.2f%% of the pool is filled.\n", (double)filledVolume / poolVolume * 100);
    }
    return 0;
}
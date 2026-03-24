#include <stdio.h>

int main()
{
    int vineYardArea;
    int grapeKilogramsPerSquareMeter;
    int wantedWineLiters;
    printf("Enter the area of the vineyard in square meters: ");
    if(scanf("%d", &vineYardArea) < 0)
    {
        printf("Invalid input for vineyard area. Please enter a non-negative number.\n");
        return 1;
    }
    printf("Enter the kilograms of grapes produced per square meter: ");
    if(scanf("%d", &grapeKilogramsPerSquareMeter) < 0)
    {
        printf("Invalid input for grape kilograms per square meter. Please enter a non-negative number.\n");
        return 1;
    }
    printf("Enter the amount of wine in liters that you want to produce: ");
    if(scanf("%d", &wantedWineLiters) < 0)
    {
        printf("Invalid input for wanted wine liters. Please enter a non-negative number.\n");
        return 1;
    }

    int totalGrapesForVine = vineYardArea * 0.4 * grapeKilogramsPerSquareMeter;
    int totalWineProduced = totalGrapesForVine / 2.5;

    if(totalWineProduced < wantedWineLiters)
    {
        printf("It will not be possible to produce the desired amount of wine. You will produce %.2f liters of wine.\n", (double)totalWineProduced);
    }
    else
    {
        printf("You will produce %.2f liters of wine, which is enough to meet your goal. You will have %.2f liters of wine left after meeting your goal.\n", (double)totalWineProduced, (double)(totalWineProduced - wantedWineLiters));
    }
    return 0;
}
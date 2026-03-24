#include <stdio.h>

int main()
{
    float taxiStartingPrice = 0.70;
    float taxiDailyPrice = 0.79;
    float taxiNightlyPrice = 0.90;
    float busPrice = 0.09;
    float trainPrice = 0.06;
    float distance;
    char timeOfDay;
    printf("Enter the distance in kilometers: ");
    if(scanf("%f", &distance) < 0)
    {
        printf("Invalid input for distance. Please enter a non-negative number.\n");
        return 1;
    }
    printf("Enter the time of day (D for day, N for night): ");
    scanf(" %c", &timeOfDay);

    if(distance < 20)
    {
        if(timeOfDay == 'D')
        {
            printf("The price for the taxi ride is: %.2f\n", taxiStartingPrice + distance * taxiDailyPrice);
        }
        else if(timeOfDay == 'N')
        {
            printf("The price for the taxi ride is: %.2f\n", taxiStartingPrice + distance * taxiNightlyPrice);
        }
        else
        {
            printf("Invalid input for time of day. Please enter D for day or N for night.\n");
            return 1;
        }
    }
    else if(distance >= 20 && distance < 100)
    {
        printf("The price for the bus ride is: %.2f\n", distance * busPrice);
    }
    else if(distance >= 100)
    {
        printf("The price for the train ride is: %.2f\n", distance * trainPrice);
    }
    return 0;
}
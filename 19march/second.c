#include <stdio.h>

int main()
{
    int hours;
    printf("Enter the number of hours: ");
    if(scanf("%d", &hours) < 0  || hours > 24)
    {
        printf("Invalid input for hours. Please enter a number between 0 and 24.\n");
        return 1;
    }
    int minutes;
    printf("Enter the number of minutes: ");
    if(scanf("%d", &minutes) < 0 || minutes > 60)
    {
        printf("Invalid input for minutes. Please enter a number between 0 and 59.\n");
        return 1;
    }

    minutes += 15;
    if(minutes >= 60)
    {
        hours += minutes / 60;
        minutes = minutes % 60;
    }
    if(hours >= 24)
    {
        hours = hours % 24;
    }

    printf("The time after adding 15 minutes is: %d:%02d\n", hours, minutes);
    return 0;
}
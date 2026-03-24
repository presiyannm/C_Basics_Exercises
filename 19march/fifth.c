#include <stdio.h>

int main()
{
    int firstTimeSeconds, secondTimeSeconds, thirdTimeSeconds;
    printf("Enter the first time in seconds: ");
    if(scanf("%d", &firstTimeSeconds) < 0 || firstTimeSeconds > 50)
    {
        printf("Invalid input for first time. Please enter a non-negative number.\n");
        return 1;
    }
    printf("Enter the second time in seconds: ");
    if(scanf("%d", &secondTimeSeconds) < 0 || secondTimeSeconds > 50)
    {
        printf("Invalid input for second time. Please enter a non-negative number.\n");
        return 1;
    }
    printf("Enter the third time in seconds: ");
    if(scanf("%d", &thirdTimeSeconds) < 0 || thirdTimeSeconds > 50)
    {
        printf("Invalid input for third time. Please enter a non-negative number.\n");
        return 1;
    }
    int totalSeconds = firstTimeSeconds + secondTimeSeconds + thirdTimeSeconds;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    printf("The total time is: %d:%02d\n", minutes, seconds);
    return 0;
}
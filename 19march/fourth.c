#include <stdio.h>

int main()
{
    int points;
    int bonusPoints = 0;
    int bonusPointsForEvenNumbers = 1;
    int bonusPointsForNumbersEndingWith5 = 2;
    printf("Enter the number of points: ");
    scanf("%d", &points);
    if(points <= 100)
    {
        bonusPoints = 5;
    }
    else if(points > 100 && points < 1000)
    {
        bonusPoints = points * 0.2;
    }
    else if(points > 1000)
    {
        bonusPoints = points * 0.1;
    }
    if(points % 2 == 0)
    {
        bonusPoints += bonusPointsForEvenNumbers;
    }
    else if(points % 10 == 5)
    {
        bonusPoints += bonusPointsForNumbersEndingWith5;
    }
    
    printf("The total bonus points are: %d\n", bonusPoints);
    printf("The total points are: %d\n", points + bonusPoints);

    return 0;
}
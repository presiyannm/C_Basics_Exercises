#include <stdio.h>
#include <stdbool.h>

int main()
{
    int numbers[3];
    bool areEqual = true;
    for(int i = 0; i < 3; i++)
    {
        printf("Enter a number: ");
        if(scanf("%d", &numbers[i]) != 1) 
        {
           break;
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(numbers[i] != numbers[0])
        {
            areEqual = false;
            break;
        }
    }
    printf("The numbers are %s\n", areEqual ? "equal" : "not equal");
    return 0;
}
#include <stdio.h>
int main() {
    int numbers[3];
    int min;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &numbers[0], &numbers[1], &numbers[2]);
    min = numbers[0];

    for(int i = 0; i < 3; i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }
    printf("The minimum number is: %d\n", min);
    return 0;
}
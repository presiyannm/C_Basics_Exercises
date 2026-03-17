#include <stdio.h>

void checkSizeOfString(char *str)
{
    int size = 0;
    while(str[size] != '\0')
    {
        size++;
    }
    printf("The size of the string is: %d\n", size);
}

void checkCapitalLettersInString(char *str)
{
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            count++;
        }
    }
    printf("The number of capital letters in the string is: %d\n", count);
}

void checkSmallLettersInString(char *str)
{
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            count++;
        }
    }
    printf("The number of small letters in the string is: %d\n", count);
}

void checkDigitsInString(char *str)
{
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            count++;
        }
    }
    printf("The number of digits in the string is: %d\n", count);
}

void checkIfStringIsPalindrome(char *str)
{
    int size = 0;
    while(str[size] != '\0')
    {
        size++;
    }
    int left = 0;
    int right = size - 1;
    while(left < right)
    {
        if(str[left] != str[right])
        {
            printf("The string is not a palindrome\n");
            return;
        }
        left++;
        right--;
    }
    printf("The string is a palindrome\n");
}

int main()
{
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);
    checkSizeOfString(string);
    checkCapitalLettersInString(string);
    checkSmallLettersInString(string);
    checkDigitsInString(string);
    checkIfStringIsPalindrome(string);
    return 0;
}
    

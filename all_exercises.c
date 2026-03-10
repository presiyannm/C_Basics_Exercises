#include <stdio.h>

void exercise1(void) {
    int number;
    printf("Exercise 1: Enter a number: ");
    if (scanf("%d", &number) != 1) { printf("Invalid input\n"); return; }
    if (number > 6) {
        printf("The number is greater than 6.\n");
    } else {
        printf("The number is not greater than 6.\n");
    }
}

void exercise2(void) {
    int number;
    printf("Exercise 2: Enter a number: ");
    if (scanf("%d", &number) != 1) { printf("Invalid input\n"); return; }
    int remainder = number % 8;
    if (remainder > 4) {
        printf("The remainder is greater than 4. (remainder=%d)\n", remainder);
    } else {
        printf("The remainder is not greater than 4. (remainder=%d)\n", remainder);
    }
}

void exercise3(void) {
    int numbers[3];
    printf("Exercise 3: Enter three numbers: ");
    if (scanf("%d %d %d", &numbers[0], &numbers[1], &numbers[2]) != 3) {
        printf("Invalid input\n");
        return;
    }
    int min = numbers[0];
    for (int i = 1; i < 3; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    printf("The minimum number is: %d\n", min);
}

void exercise4(void) {
    int number;
    printf("Exercise 4: Enter a number between 0 and 9: ");
    if (scanf("%d", &number) != 1) { printf("Invalid input\n"); return; }

    switch (number) {
        case 0: printf("zero\n"); break;
        case 1: printf("one\n"); break;
        case 2: printf("two\n"); break;
        case 3: printf("three\n"); break;
        case 4: printf("four\n"); break;
        case 5: printf("five\n"); break;
        case 6: printf("six\n"); break;
        case 7: printf("seven\n"); break;
        case 8: printf("eight\n"); break;
        case 9: printf("nine\n"); break;
        default: printf("The number is not between 0 and 9.\n");
    }
}

void exercise5(void) {
    int numbers[50];
    int count = 0;
    int number;

    printf("Exercise 5: Enter numbers (0 to stop), duplicates kept, max 50 entries:\n");
    while (count < 50 && scanf("%d", &number) == 1 && number != 0) {
        numbers[count++] = number;
    }

    if (count == 0) {
        printf("No numbers entered.\n");
        return;
    }

    printf("Read %d value(s): ", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void exercise6(void) {
    int number;
    printf("Exercise 6 (Loop 1): Enter a number for the pyramid: ");
    if (scanf("%d", &number) != 1) { printf("Invalid input\n"); return; }

    for (int i = 1; i <= number; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

void exercise7(void) {
    int firstNumber, secondNumber;
    printf("Exercise 7 (Loop 2): Enter two numbers: ");
    if (scanf("%d %d", &firstNumber, &secondNumber) != 2) { printf("Invalid input\n"); return; }

    int sum = 0;
    for (int i = firstNumber + 1; i < secondNumber; i++) {
        sum += i;
    }
    printf("Sum: %d\n", sum);
}

void exercise8(void) {
    int firstNumber, secondNumber;
    printf("Exercise 8 (Loop 3): Enter two numbers: ");
    if (scanf("%d %d", &firstNumber, &secondNumber) != 2) { printf("Invalid input\n"); return; }

    int sumOfEvens = 0;
    int multiplicationOfOdds = 1;
    for (int i = firstNumber + 1; i < secondNumber; i++) {
        if (i % 2 == 0) {
            sumOfEvens += i;
        } else {
            multiplicationOfOdds *= i;
        }
    }
    printf("Sum of evens: %d\n", sumOfEvens);
    printf("Multiplication of odds: %d\n", multiplicationOfOdds);
}

void exercise9(void) {
    int n, k;
    int numbers[50];
    int numbers_greater_than_k = 0;

    printf("Exercise 9 (Loop 4): Enter N and K: ");
    if (scanf("%d %d", &n, &k) != 2) { printf("Invalid input\n"); return; }

    if (n < 0 || n > 50) {
        printf("N should be between 0 and 50\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter a number (%d/%d): ", i + 1, n);
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n; i++) {
        if (numbers[i] > k && numbers[i] % 3 == 0) {
            numbers_greater_than_k++;
        }
    }

    printf("Count of numbers > K and divisible by 3: %d\n", numbers_greater_than_k);
}

void exercise10(void) {
    int numbers[50];
    int count = 0;
    int number;
    int sum = 0;

    printf("Exercise 10 (Loop 5): Enter numbers (0 to stop):\n");
    while (count < 50 && scanf("%d", &number) == 1 && number != 0) {
        numbers[count++] = number;
    }

    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }

    printf("Sum of numbers: %d\n", sum);
}

void exercise11(void) {
    double start, end, x, f_x;

    printf("Exercise 11 (Loop 6): Enter the start of the interval: ");
    if (scanf("%lf", &start) != 1) { printf("Invalid input\n"); return; }
    printf("Enter the end of the interval: ");
    if (scanf("%lf", &end) != 1) { printf("Invalid input\n"); return; }

    if (start > end) {
        double temp = start;
        start = end;
        end = temp;
    }

    printf("\nValues of the function f(x) = x*x - 4:\n");
    for (x = start; x <= end + 0.0001; x += 0.001) {
        f_x = (x * x) - 4;
        printf("f(%.2lf) = %.4lf\n", x, f_x);
    }
}

int main(void) {
    int choice;

    printf("=== Exercise menu ===\n");
    printf("1) First_exercise\n");
    printf("2) Second_exercise\n");
    printf("3) Third_exercise\n");
    printf("4) Fourth_exercise\n");
    printf("5) Fifth_exercise\n");
    printf("6) Loop_exercise 1 (pyramid)\n");
    printf("7) Loop_exercise 2 (sum between)\n");
    printf("8) Loop_exercise 3 (evens/odds)\n");
    printf("9) Loop_exercise 4 (greater than K and divisible by 3)\n");
    printf("10) Loop_exercise 5 (sum until 0)\n");
    printf("11) Loop_exercise 6 (function over interval)\n");
    printf("0) Exit\n");
    printf("Choose exercise number: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid selection\n");
        return 1;
    }

    switch (choice) {
        case 0: printf("Exiting.\n"); break;
        case 1: exercise1(); break;
        case 2: exercise2(); break;
        case 3: exercise3(); break;
        case 4: exercise4(); break;
        case 5: exercise5(); break;
        case 6: exercise6(); break;
        case 7: exercise7(); break;
        case 8: exercise8(); break;
        case 9: exercise9(); break;
        case 10: exercise10(); break;
        case 11: exercise11(); break;
        default: printf("Unknown exercise number: %d\n", choice);
    }

    return 0;
}

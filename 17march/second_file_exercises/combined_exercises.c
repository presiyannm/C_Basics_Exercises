#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

static void exercise_shape_metrics(void);
static void exercise_array_operations(void);
static void exercise_number_info(void);
static void exercise_math_operations(void);
static void exercise_string_analysis(void);
static void print_main_menu(void);

static void calculateStuffOfSquare(int a)
{
    printf("The figure is square\n");
    printf("Area of square: %d\n", a*a);
    printf("Perimeter of square: %d\n", 4*a);
}

static void calculateStuffOfRectangle(int l, int b)
{
    printf("The figure is rectangle\n");
    printf("Area of rectangle: %d\n", l*b);
    printf("Perimeter of rectangle: %d\n", 2*(l+b));
}

static void calculateStuffOfCircle(int r)
{
    const double PI = 3.141592653589793;
    printf("The figure is circle\n");
    printf("Area of circle: %.2f\n", PI * r * r);
    printf("Circumference of circle: %.2f\n", 2 * PI * r);
}

static void calculateStuffOfTriangle(int b, int h)
{
    printf("The figure is triangle\n");
    printf("Area of triangle: %.2f\n", 0.5 * b * h);
    int thirdSide = (int)round(sqrt((double)b*b + (double)h*h));
    printf("Perimeter of triangle: %d\n", b + h + thirdSide);
}

static void calculateStuffOfTrapezium(int a, int b, int h)
{
    printf("The figure is trapezium\n");
    printf("Area of trapezium: %.2f\n", 0.5 * (a + b) * h);
    int side = (int)round(sqrt((double)(b - a) * (b - a) + (double)h*h));
    printf("Perimeter of trapezium: %d\n", a + b + h + side);
}

static void exercise_shape_metrics(void)
{
    printf("\n--- Shape metrics (area + perimeter) ---\n");
    printf("1) Square\n");
    printf("2) Rectangle\n");
    printf("3) Circle\n");
    printf("4) Triangle\n");
    printf("5) Trapezium\n");
    printf("0) Back\n");
    printf("Choose shape: ");

    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input\n");
        return;
    }

    switch (choice) {
        case 1: {
            int side;
            printf("Enter side: ");
            if (scanf("%d", &side) != 1 || side < 0) {
                printf("Invalid side\n");
                return;
            }
            calculateStuffOfSquare(side);
            break;
        }
        case 2: {
            int l, b;
            printf("Enter length and breadth: ");
            if (scanf("%d %d", &l, &b) != 2 || l < 0 || b < 0) {
                printf("Invalid input\n");
                return;
            }
            calculateStuffOfRectangle(l, b);
            break;
        }
        case 3: {
            int r;
            printf("Enter radius: ");
            if (scanf("%d", &r) != 1 || r < 0) {
                printf("Invalid radius\n");
                return;
            }
            calculateStuffOfCircle(r);
            break;
        }
        case 4: {
            int base, height;
            printf("Enter base and height: ");
            if (scanf("%d %d", &base, &height) != 2 || base < 0 || height < 0) {
                printf("Invalid input\n");
                return;
            }
            calculateStuffOfTriangle(base, height);
            break;
        }
        case 5: {
            int a, b, h;
            printf("Enter parallel sides a, b and height h: ");
            if (scanf("%d %d %d", &a, &b, &h) != 3 || a < 0 || b < 0 || h < 0) {
                printf("Invalid input\n");
                return;
            }
            calculateStuffOfTrapezium(a, b, h);
            break;
        }
        case 0:
            break;
        default:
            printf("Invalid option\n");
    }
}

static void sumOfArray(const int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    printf("Sum of array: %d\n", sum);
}

static void biggestOfArray(const int arr[], int size) {
    int biggest = arr[0];
    for (int i = 1; i < size; i++) if (arr[i] > biggest) biggest = arr[i];
    printf("Biggest element: %d\n", biggest);
}

static void smallestOfArray(const int arr[], int size) {
    int smallest = arr[0];
    for (int i = 1; i < size; i++) if (arr[i] < smallest) smallest = arr[i];
    printf("Smallest element: %d\n", smallest);
}

static void evensOfArray(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) if (arr[i] % 2 == 0) count++;
    printf("Count of evens: %d\n", count);
}

static void reverseArray(const int arr[], int size) {
    printf("Array in reverse: ");
    for (int i = size - 1; i >= 0; i--) printf("%d ", arr[i]);
    printf("\n");
}

static void exercise_array_operations(void)
{
    printf("\n--- Array operations ---\n");

    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size\n");
        return;
    }

    int *arr = malloc(sizeof(int) * n);
    if (!arr) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid number\n");
            free(arr);
            return;
        }
    }

    sumOfArray(arr, n);
    biggestOfArray(arr, n);
    smallestOfArray(arr, n);
    evensOfArray(arr, n);
    reverseArray(arr, n);

    free(arr);
}

static bool checkIfNumberIsPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

static int getDigitsSum(int num) {
    int sum = 0;
    num = abs(num);
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

static int getDigitsNumber(int num) {
    int count = 0;
    num = abs(num);
    if (num == 0) return 1;
    while (num) {
        count++;
        num /= 10;
    }
    return count;
}

static int reverseNumber(int num) {
    int reversed = 0;
    int sign = num < 0 ? -1 : 1;
    num = abs(num);
    while (num) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed * sign;
}

static void exercise_number_info(void)
{
    printf("\n--- Number info ---\n");
    int number;
    printf("Enter number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input\n");
        return;
    }

    printf("Prime check: %s\n", checkIfNumberIsPrime(number) ? "Prime" : "Not prime");
    printf("Digit sum: %d\n", getDigitsSum(number));
    printf("Digit count: %d\n", getDigitsNumber(number));
    printf("Reversed number: %d\n", reverseNumber(number));
}

static int sum(int a, int b) {
    return a + b;
}

static int difference(int a, int b) {
    return a - b;
}

static int product(int a, int b) {
    return a * b;
}

static double division(int a, int b) {
    if (b == 0) {
        printf("Cannot divide by zero\n");
        return 0.0;
    }
    return (double)a / (double)b;
}

static double customPow(int a, int b) {
    if (b < 0) {
        return 1.0 / customPow(a, -b);
    }
    double result = 1.0;
    for (int i = 0; i < b; i++) result *= a;
    return result;
}

static int getRemainder(int a, int b) {
    if (b == 0) {
        printf("Cannot divide by zero\n");
        return 0;
    }
    return a % b;
}

static void exercise_math_operations(void)
{
    printf("\n--- Math operations ---\n");
    int a, b;
    printf("Enter a: ");
    if (scanf("%d", &a) != 1) { printf("Invalid input\n"); return; }
    printf("Enter b: ");
    if (scanf("%d", &b) != 1) { printf("Invalid input\n"); return; }

    printf("1) Sum\n");
    printf("2) Difference\n");
    printf("3) Product\n");
    printf("4) Division\n");
    printf("5) Power (a^b)\n");
    printf("6) Remainder (a%%b)\n");
    printf("Choose operation: ");

    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("Invalid choice\n");
        return;
    }

    switch (choice) {
        case 1: printf("Sum: %d\n", sum(a, b)); break;
        case 2: printf("Difference: %d\n", difference(a, b)); break;
        case 3: printf("Product: %d\n", product(a, b)); break;
        case 4: printf("Division: %.2f\n", division(a, b)); break;
        case 5: printf("Power: %.2f\n", customPow(a, b)); break;
        case 6: printf("Remainder: %d\n", getRemainder(a, b)); break;
        default: printf("Invalid option\n"); break;
    }
}

static void checkSizeOfString(const char *str) {
    printf("Size of string: %zu\n", strlen(str));
}

static void checkCapitalLettersInString(const char *str) {
    int count = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') count++;
    }
    printf("Capital letters: %d\n", count);
}

static void checkSmallLettersInString(const char *str) {
    int count = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') count++;
    }
    printf("Small letters: %d\n", count);
}

static void checkDigitsInString(const char *str) {
    int count = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') count++;
    }
    printf("Digit characters: %d\n", count);
}

static void checkIfStringIsPalindrome(const char *str) {
    size_t len = strlen(str);
    bool palindrome = true;
    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            palindrome = false;
            break;
        }
    }
    printf("String is %s palindrome\n", palindrome ? "a" : "not a");
}

static void exercise_string_analysis(void) {
    printf("\n--- String analysis ---\n");
    char buffer[256];
    printf("Enter a string (no spaces): ");
    if (scanf("%255s", buffer) != 1) {
        printf("Invalid input\n");
        return;
    }

    checkSizeOfString(buffer);
    checkCapitalLettersInString(buffer);
    checkSmallLettersInString(buffer);
    checkDigitsInString(buffer);
    checkIfStringIsPalindrome(buffer);
}

static void print_main_menu(void)
{
    printf("\n=== second_file_exercises Combined Menu ===\n");
    printf("1) Shape metrics (first.c)\n");
    printf("2) Array operations (second.c)\n");
    printf("3) Number info (third.c)\n");
    printf("4) Math operations (fourth.c)\n");
    printf("5) String analysis (fifth.c)\n");
    printf("0) Exit\n");
    printf("Select an option: ");
}

int main(void)
{
    while (true) {
        print_main_menu();
        int option;
        if (scanf("%d", &option) != 1) {
            printf("Invalid selection\n");
            while (getchar() != '\n');
            continue;
        }

        switch (option) {
            case 0:
                printf("Exiting combined exercises.\n");
                return 0;
            case 1:
                exercise_shape_metrics();
                break;
            case 2:
                exercise_array_operations();
                break;
            case 3:
                exercise_number_info();
                break;
            case 4:
                exercise_math_operations();
                break;
            case 5:
                exercise_string_analysis();
                break;
            default:
                printf("Unknown option %d\n", option);
        }
    }
 }

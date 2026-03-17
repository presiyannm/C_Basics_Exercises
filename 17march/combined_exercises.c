#include <stdio.h>
#include <stdbool.h>
#include <math.h>

static void exercise_area_calculator(void);
static void exercise_swap_numbers(void);
static void exercise_even_odd(void);
static void exercise_base_two(void);
static void print_main_menu(void);

static double calculate_area_square(double side) {
    return side * side;
}

static double calculate_area_rectangle(double length, double breadth) {
    return length * breadth;
}

static double calculate_area_triangle(double base, double height) {
    return (base * height) / 2.0;
}

static double calculate_area_circle(double radius) {
    const double PI = 3.141592653589793;
    return PI * radius * radius;
}

static void exercise_area_calculator(void) {
    int choice;
    printf("\n--- Area Calculator ---\n");
    printf("1) Square\n");
    printf("2) Rectangle\n");
    printf("3) Triangle\n");
    printf("4) Circle\n");
    printf("0) Back to main menu\n");
    printf("Choose shape: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input\n");
        while (getchar() != '\n');
        return;
    }

    if (choice == 0) return;

    switch (choice) {
        case 1: {
            double side;
            printf("Enter the side of the square: ");
            if (scanf("%lf", &side) != 1 || side < 0) {
                printf("Invalid side\n");
                return;
            }
            printf("Square area: %.4f\n", calculate_area_square(side));
            break;
        }
        case 2: {
            double l, b;
            printf("Enter length and breadth of rectangle: ");
            if (scanf("%lf %lf", &l, &b) != 2 || l < 0 || b < 0) {
                printf("Invalid rectangle dimensions\n");
                return;
            }
            printf("Rectangle area: %.4f\n", calculate_area_rectangle(l, b));
            break;
        }
        case 3: {
            double base, height;
            printf("Enter base and height of triangle: ");
            if (scanf("%lf %lf", &base, &height) != 2 || base < 0 || height < 0) {
                printf("Invalid triangle dimensions\n");
                return;
            }
            printf("Triangle area: %.4f\n", calculate_area_triangle(base, height));
            break;
        }
        case 4: {
            double radius;
            printf("Enter radius of circle: ");
            if (scanf("%lf", &radius) != 1 || radius < 0) {
                printf("Invalid radius\n");
                return;
            }
            printf("Circle area: %.4f\n", calculate_area_circle(radius));
            break;
        }
        default:
            printf("Invalid choice - please choose 0..4\n");
            break;
    }
}

static void exercise_swap_numbers(void) {
    int x = 5, y = 10;
    printf("\n--- Swap Numbers ---\n");
    printf("Before switching: x = %d, y = %d\n", x, y);
    int temp = x;
    x = y;
    y = temp;
    printf("After switching: x = %d, y = %d\n", x, y);
}

static bool is_even(int num) {
    return (num % 2) == 0;
}

static void exercise_even_odd(void) {
    int number;
    printf("\n--- Even/Odd Checker ---\n");
    printf("Enter a number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input\n");
        return;
    }
    printf("The number %d is %s.\n", number, is_even(number) ? "even" : "odd");
}

static void exercise_base_two(void) {
    int number;
    printf("\n--- Base-2 Converter ---\n");
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &number) != 1 || number < 0) {
        printf("Invalid input\n");
        return;
    }

    if (number == 0) {
        printf("The number in base 2 is: 0\n");
        return;
    }

    int binary[32];
    int i = 0;

    while (number > 0 && i < 32) {
        binary[i++] = number % 2;
        number /= 2;
    }

    printf("The number in base 2 is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

static void print_main_menu(void) {
    printf("\n=== 17march Combined Exercises ===\n");
    printf("1) Area calculator (square/rectangle/triangle/circle)\n");
    printf("2) Swap fixed numbers example (5 and 10)\n");
    printf("3) Even/Odd check\n");
    printf("4) Decimal to binary converter\n");
    printf("0) Exit\n");
    printf("Choose an option: ");
}

int main(void) {
    while (1) {
        print_main_menu();

        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 0:
                printf("Goodbye!\n");
                return 0;
            case 1:
                exercise_area_calculator();
                break;
            case 2:
                exercise_swap_numbers();
                break;
            case 3:
                exercise_even_odd();
                break;
            case 4:
                exercise_base_two();
                break;
            default:
                printf("Unknown option: %d. Please try again.\n", choice);
                break;
        }
    }
}

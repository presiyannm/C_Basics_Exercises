#include <stdio.h>

int main() {
    int n;
    // Basic input check
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    int half_rows = n - 2;

    // Top half
    for (int i = 0; i < half_rows; i++) {
        char c = (i % 2 == 0) ? ' ' : '-'; 
        for (int j = 0; j < half_rows; j++) {
            printf("%c", c);
        }
        printf("\\ /"); // Double backslash to print one
        for (int j = 0; j < half_rows; j++) {
            printf("%c", c);
        }
        printf("\n");
    }

    // Middle row
    for (int i = 0; i < n - 1; i++) {
        printf(" ");
    }
    printf("@\n");

    // Bottom half
    for (int i = 0; i < half_rows; i++) {
        char c = (i % 2 == 0) ? ' ' : '-'; 
        for (int j = 0; j < half_rows; j++) {
            printf("%c", c);
        }
        printf("/ \\"); // Double backslash to print one
        for (int j = 0; j < half_rows; j++) {
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}
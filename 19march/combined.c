#include <stdio.h>
#include <stdlib.h>

// --- Function Prototypes ---
void runFirst();
void runSecond();
void runFourth();
void runFifth();
void runSixth();
void runSeventh();
void runEighth();
void runNineth();
void runTenth();
void runEleventh();
void runTwelveth();

int main() {
    int choice;

    while (1) {
        printf("\n--- Integrated C Lab Menu ---\n");
        printf("1.  Min/Max of 10 numbers (first.c)\n");
        printf("2.  Time + 15 Minutes (second.c)\n");
        printf("4.  Bonus Points Calculator (fourth.c)\n");
        printf("5.  Total Time in Minutes (fifth.c)\n");
        printf("6.  Point in Rectangle (sixth.c)\n");
        printf("7.  Transport Price (seventh.c)\n");
        printf("8.  Pool Pipes (eighth.c)\n");
        printf("9.  Harvest & Wine (nineth.c)\n");
        printf("10. Number Histogram (tenth.c)\n");
        printf("11. Draw a Castle (eleventh.c)\n");
        printf("12. Draw a Butterfly (twelveth.c)\n");
        printf("0.  Exit\n");
        printf("Select an exercise (0-12): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        if (choice == 0) break;

        printf("\n--- Starting Exercise %d ---\n", choice);
        switch (choice) {
            case 1: runFirst(); break;
            case 2: runSecond(); break;
            case 4: runFourth(); break;
            case 5: runFifth(); break;
            case 6: runSixth(); break;
            case 7: runSeventh(); break;
            case 8: runEighth(); break;
            case 9: runNineth(); break;
            case 10: runTenth(); break;
            case 11: runEleventh(); break;
            case 12: runTwelveth(); break;
            default: printf("Exercise not found.\n");
        }
        printf("--- Exercise Finished ---\n");
    }

    return 0;
}

// --- Exercise Implementations ---

void checkBiggerAndSmallestNumber(int* numbers, int size) {
    if (size == 0) return;
    int biggest = *numbers;
    int smallest = *numbers;
    for (int *p = numbers + 1; p < numbers + size; p++) {
        if (*p > biggest) biggest = *p;
        if (*p < smallest) smallest = *p;
    }
    printf("The biggest number is: %d\n", biggest);
    printf("The smallest number is: %d\n", smallest);
}

void runFirst() {
    int count = 0;
    int *numbers = (int*)malloc(10 * sizeof(int));
    for(int i = 0; i < 10; i++) {
        printf("Enter a number (0 to stop): ");
        if(scanf("%d", numbers + i) != 1 || *(numbers + i) == 0) break;
        count++;
    }
    checkBiggerAndSmallestNumber(numbers, count);
    free(numbers);
}

void runSecond() {
    int hours, minutes;
    int *pHours = &hours;
    int *pMinutes = &minutes;
    printf("Enter hours (0-23): ");
    scanf("%d", pHours);
    printf("Enter minutes (0-59): ");
    scanf("%d", pMinutes);

    *pMinutes += 15;
    if(*pMinutes >= 60) {
        *pHours += *pMinutes / 60;
        *pMinutes = *pMinutes % 60;
    }
    if(*pHours >= 24) *pHours = *pHours % 24;

    printf("The time after adding 15 minutes is: %d:%02d\n", *pHours, *pMinutes);
}

void runFourth() {
    int points;
    double bonusPoints = 0;
    int *pPoints = &points;
    double *pBonus = &bonusPoints;
    printf("Enter the number of points: ");
    scanf("%d", pPoints);

    if(*pPoints <= 100) *pBonus = 5;
    else if(*pPoints < 1000) *pBonus = *pPoints * 0.2;
    else *pBonus = *pPoints * 0.1;

    if(*pPoints % 2 == 0) *pBonus += 1;
    else if(*pPoints % 10 == 5) *pBonus += 2;
    
    printf("The total bonus points are: %.1f\n", *pBonus);
    printf("The total points are: %.1f\n", *pPoints + *pBonus);
}

void runFifth() {
    int t1, t2, t3;
    int *pt1 = &t1;
    int *pt2 = &t2;
    int *pt3 = &t3;
    printf("Enter 3 times in seconds (0-50): ");
    scanf("%d %d %d", pt1, pt2, pt3);
    int total = *pt1 + *pt2 + *pt3;
    printf("The total time is: %d:%02d\n", total / 60, total % 60);
}

void runSixth() {
    int x, y, x1, y1, x2, y2;
    int *px = &x;
    int *py = &y;
    int *px1 = &x1;
    int *py1 = &y1;
    int *px2 = &x2;
    int *py2 = &y2;
    printf("Enter rectangle x1 y1: ");
    scanf("%d %d", px1, py1);
    printf("Enter rectangle x2 y2: ");
    scanf("%d %d", px2, py2);
    printf("Enter point to check x y: ");
    scanf("%d %d", px, py);
    
    if(*px >= *px1 && *px <= *px2 && *py >= *py1 && *py <= *py2) printf("Inside\n");
    else printf("Outside\n");
}

void runSeventh() {
    float dist;
    char tod;
    float *pDist = &dist;
    char *pTod = &tod;
    printf("Enter distance: ");
    scanf("%f", pDist);
    printf("Enter time of day (D/N): ");
    scanf(" %c", pTod);

    if(*pDist < 20) {
        float rate = (*pTod == 'D' || *pTod == 'd') ? 0.79f : 0.90f;
        printf("Taxi price: %.2f\n", 0.70f + (*pDist) * rate);
    } else if(*pDist < 100) {
        printf("Bus price: %.2f\n", (*pDist) * 0.09f);
    } else {
        printf("Train price: %.2f\n", (*pDist) * 0.06f);
    }
}

void runEighth() {
    int vol, p1, p2, hrs;
    int *pVol = &vol;
    int *pP1 = &p1;
    int *pP2 = &p2;
    int *pHrs = &hrs;
    printf("Pool volume, P1 rate, P2 rate, Hours: ");
    scanf("%d %d %d %d", pVol, pP1, pP2, pHrs);
    int filled = (*pP1 + *pP2) * (*pHrs);
    if(filled <= *pVol) printf("Pool is %.2f%% full.\n", (double)filled / (*pVol) * 100);
    else printf("Pool overflowed by %d liters.\n", filled - vol);
}

void runNineth() {
    int area, grapes, wanted;
    int *pArea = &area;
    int *pGrapes = &grapes;
    int *pWanted = &wanted;
    printf("Area, Grapes/sqm, Wanted Wine: ");
    scanf("%d %d %d", pArea, pGrapes, pWanted);
    double totalWine = ((*pArea) * 0.4 * (*pGrapes)) / 2.5;
    if(totalWine >= *pWanted) printf("Success! %.2f liters produced. Surplus: %.2f\n", totalWine, totalWine - (*pWanted));
    else printf("Shortfall. Only %.2f liters produced.\n", totalWine);
}

void runTenth() {
    int p1=0, p2=0, p3=0, p4=0, p5=0;
    int nums[] = {100,200,300,400,500,600,700,800,900,1000};
    for(int *p = nums; p < nums + 10; p++) {
        if (*p < 200) p1++;
        else if (*p < 400) p2++;
        else if (*p < 600) p3++;
        else if (*p < 800) p4++;
        else p5++;
    }
    printf("p1: %.2f%%, p2: %.2f%%, p3: %.2f%%, p4: %.2f%%, p5: %.2f%%\n", 
           p1*10.0, p2*10.0, p3*10.0, p4*10.0, p5*10.0);
}

void runEleventh() {
    int n;
    printf("Enter castle size: ");
    if (scanf("%d", &n) != 1) return;
    if (n < 3) { printf("Size too small for full castle.\n"); return; }

    int col_size = n / 2;
    int mid_size = 2 * n - 2 * col_size - 4;

    printf("/"); for (int i = 0; i < col_size; i++) printf("^"); printf("\\");
    for (int i = 0; i < mid_size; i++) printf("_");
    printf("/"); for (int i = 0; i < col_size; i++) printf("^"); printf("\\\n");

    for (int row = 0; row < n - 3; row++) {
        printf("|"); for (int i = 0; i < 2 * n - 2; i++) printf(" "); printf("|\n");
    }

    printf("|");
    for (int i = 0; i < col_size + 1; i++) printf(" ");
    for (int i = 0; i < mid_size; i++) printf("_");
    for (int i = 0; i < col_size + 1; i++) printf(" "); printf("|\n");

    printf("\\"); for (int i = 0; i < col_size; i++) printf("_"); printf("/");
    for (int i = 0; i < mid_size; i++) printf(" ");
    printf("\\"); for (int i = 0; i < col_size; i++) printf("_"); printf("/\n");
}

void runTwelveth() {
    int n;
    printf("Enter butterfly size: ");
    if (scanf("%d", &n) != 1) return;

    int half_rows = n - 2;

    // Top half
    for (int i = 0; i < half_rows; i++) {
        char c = (i % 2 == 0) ? ' ' : '-';
        for (int j = 0; j < half_rows; j++) printf("%c", c);
        printf("\\ /");
        for (int j = 0; j < half_rows; j++) printf("%c", c);
        printf("\n");
    }

    // Middle row
    for (int i = 0; i < n - 1; i++) printf(" ");
    printf("@\n");

    // Bottom half
    for (int i = 0; i < half_rows; i++) {
        char c = (i % 2 == 0) ? ' ' : '-';
        for (int j = 0; j < half_rows; j++) printf("%c", c);
        printf("/ \\");
        for (int j = 0; j < half_rows; j++) printf("%c", c);
        printf("\n");
    }
}
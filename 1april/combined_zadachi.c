#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 500
#define MAX_ORDERS 500
#define MAX_NAME_LEN 64
#define MAX_ADDRESS_LEN 128

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
    int id;
} Product;

typedef struct {
    char address[MAX_ADDRESS_LEN];
    int productId;
} Order;

typedef struct {
    int id;
    double hourlyRate;
    double workedHours;
    double weeklySalary;
} Employee;

void runFirst(void);
void runSecond(void);
void runThird(void);
void runFourth(void);
void runFifth(void);
void runSixth(void);
void runSeventh(void);

static void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

static int readInt(const char *prompt, int *value)
{
    printf("%s", prompt);
    if (scanf("%d", value) != 1)
    {
        clearInputBuffer();
        return 0;
    }
    clearInputBuffer();
    return 1;
}

static int readDouble(const char *prompt, double *value)
{
    printf("%s", prompt);
    if (scanf("%lf", value) != 1)
    {
        clearInputBuffer();
        return 0;
    }
    clearInputBuffer();
    return 1;
}

static char *duplicateString(const char *src)
{
    size_t len = strlen(src);
    char *dest = (char *)malloc(len + 1);
    if (dest == NULL)
    {
        return NULL;
    }
    strcpy(dest, src);
    return dest;
}

static void trimNewline(char *s)
{
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
    {
        s[len - 1] = '\0';
    }
}

int main(void)
{
    int choice;

    while (1)
    {
        printf("\n--- Combined Menu (1april/za%dachi.DOCX) ---\n", 0);
        printf("1. Party inventory and missing items\n");
        printf("2. Product/order manager\n");
        printf("3. Word chain from text file to binary file\n");
        printf("4. Encode file with numeric key\n");
        printf("5. Hangman game\n");
        printf("6. Check if two strings are anagrams\n");
        printf("7. Employee binary file and weekly salary\n");
        printf("0. Exit\n");

        if (!readInt("Choose exercise: ", &choice))
        {
            printf("Invalid menu input.\n");
            continue;
        }

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
            case 1: runFirst(); break;
            case 2: runSecond(); break;
            case 3: runThird(); break;
            case 4: runFourth(); break;
            case 5: runFifth(); break;
            case 6: runSixth(); break;
            case 7: runSeventh(); break;
            default: printf("Exercise not found.\n"); break;
        }
    }

    return 0;
}

void runFirst(void)
{
    const double chairPrice = 13.99;
    const double tablePrice = 42.00;
    const double cupsSetPrice = 5.98;
    const double dishesSetPrice = 21.02;

    int guests;
    int chairsBought = 0;
    int tablesBought = 0;
    int cupsSetsBought = 0;
    int dishesSetsBought = 0;
    char item[32];

    if (!readInt("Enter number of guests: ", &guests) || guests <= 0)
    {
        printf("Invalid guest count.\n");
        return;
    }

    printf("Enter purchased items (Table, Chair, Cups, Dishes). Type PARTY! to stop.\n");
    while (1)
    {
        printf("Item: ");
        if (scanf("%31s", item) != 1)
        {
            clearInputBuffer();
            break;
        }
        clearInputBuffer();

        if (strcmp(item, "PARTY!") == 0)
        {
            break;
        }
        else if (strcmp(item, "Table") == 0)
        {
            tablesBought++;
        }
        else if (strcmp(item, "Chair") == 0)
        {
            chairsBought++;
        }
        else if (strcmp(item, "Cups") == 0)
        {
            cupsSetsBought++;
        }
        else if (strcmp(item, "Dishes") == 0)
        {
            dishesSetsBought++;
        }
        else
        {
            printf("Unknown item ignored.\n");
        }
    }

    double spent = chairsBought * chairPrice + tablesBought * tablePrice +
                   cupsSetsBought * cupsSetPrice + dishesSetsBought * dishesSetPrice;

    int requiredTables = (guests + 7) / 8;
    int requiredChairs = guests;
    int requiredCupSets = (guests + 5) / 6;
    int requiredDishSets = (guests + 5) / 6;

    int missingTables = requiredTables - tablesBought;
    int missingChairs = requiredChairs - chairsBought;
    int missingCupSets = requiredCupSets - cupsSetsBought;
    int missingDishSets = requiredDishSets - dishesSetsBought;

    if (missingTables < 0)
    {
        missingTables = 0;
    }
    if (missingChairs < 0)
    {
        missingChairs = 0;
    }
    if (missingCupSets < 0)
    {
        missingCupSets = 0;
    }
    if (missingDishSets < 0)
    {
        missingDishSets = 0;
    }

    printf("Spent: %.2f\n", spent);
    printf("Missing items:\n");
    printf("%d Table(s)\n", missingTables);
    printf("%d Chair(s)\n", missingChairs);
    printf("%d Cups set(s)\n", missingCupSets);
    printf("%d Dishes set(s)\n", missingDishSets);
}

static int findProductIndex(const Product products[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

static void processWaitingOrders(const Product products[], int productCount, Order orders[], int *orderCount, int productId)
{
    int i = 0;
    int productIndex = findProductIndex(products, productCount, productId);

    if (productIndex < 0)
    {
        return;
    }

    while (i < *orderCount)
    {
        if (orders[i].productId == productId)
        {
            printf("Client %s ordered %s\n", orders[i].address, products[productIndex].name);
            for (int j = i; j < *orderCount - 1; j++)
            {
                orders[j] = orders[j + 1];
            }
            (*orderCount)--;
        }
        else
        {
            i++;
        }
    }
}

void runSecond(void)
{
    Product products[MAX_PRODUCTS];
    Order waitingOrders[MAX_ORDERS];
    int productCount = 0;
    int waitingCount = 0;
    char command[32];

    printf("Commands: Product <name> <price> <id>, Order <address> <productId>, END\n");

    while (1)
    {
        printf("> ");
        if (scanf("%31s", command) != 1)
        {
            clearInputBuffer();
            break;
        }

        if (strcmp(command, "END") == 0)
        {
            clearInputBuffer();
            break;
        }

        if (strcmp(command, "Product") == 0)
        {
            Product p;
            if (scanf("%63s %lf %d", p.name, &p.price, &p.id) != 3)
            {
                printf("Invalid Product command format.\n");
                clearInputBuffer();
                continue;
            }

            int existingIndex = findProductIndex(products, productCount, p.id);
            if (existingIndex >= 0)
            {
                products[existingIndex] = p;
            }
            else if (productCount < MAX_PRODUCTS)
            {
                products[productCount++] = p;
            }
            else
            {
                printf("Product storage is full.\n");
            }

            processWaitingOrders(products, productCount, waitingOrders, &waitingCount, p.id);
        }
        else if (strcmp(command, "Order") == 0)
        {
            Order order;
            if (scanf("%127s %d", order.address, &order.productId) != 2)
            {
                printf("Invalid Order command format.\n");
                clearInputBuffer();
                continue;
            }

            int productIndex = findProductIndex(products, productCount, order.productId);
            if (productIndex >= 0)
            {
                printf("Client %s ordered %s\n", order.address, products[productIndex].name);
            }
            else if (waitingCount < MAX_ORDERS)
            {
                waitingOrders[waitingCount++] = order;
            }
            else
            {
                printf("Waiting orders storage is full.\n");
            }
        }
        else
        {
            printf("Unknown command.\n");
        }

        clearInputBuffer();
    }

    if (waitingCount > 0)
    {
        printf("Unfulfilled orders left: %d\n", waitingCount);
    }
}

static int appendSelectedWord(char ***arr, int *count, int *capacity, const char *word)
{
    if (*count >= *capacity)
    {
        int newCapacity = (*capacity == 0) ? 8 : (*capacity * 2);
        char **newArr = (char **)realloc(*arr, newCapacity * sizeof(char *));
        if (newArr == NULL)
        {
            return 0;
        }
        *arr = newArr;
        *capacity = newCapacity;
    }

    (*arr)[*count] = duplicateString(word);
    if ((*arr)[*count] == NULL)
    {
        return 0;
    }

    (*count)++;
    return 1;
}

static void freeWordArray(char **arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

void runThird(void)
{
    char inputFile[260];
    char binaryFile[260];

    printf("Enter input text file path: ");
    if (fgets(inputFile, sizeof(inputFile), stdin) == NULL)
    {
        printf("Invalid input path.\n");
        return;
    }
    trimNewline(inputFile);

    printf("Enter output binary file path: ");
    if (fgets(binaryFile, sizeof(binaryFile), stdin) == NULL)
    {
        printf("Invalid output path.\n");
        return;
    }
    trimNewline(binaryFile);

    FILE *in = fopen(inputFile, "r");
    if (in == NULL)
    {
        printf("Cannot open input file.\n");
        return;
    }

    char **selected = NULL;
    int selectedCount = 0;
    int selectedCapacity = 0;

    char word[64];
    int len = 0;
    int ch;

    while ((ch = fgetc(in)) != EOF)
    {
        if (isalpha((unsigned char)ch))
        {
            if (len < 50)
            {
                word[len++] = (char)tolower((unsigned char)ch);
            }
        }
        else if (len > 0)
        {
            word[len] = '\0';

            int shouldAdd = 0;
            if (selectedCount == 0)
            {
                shouldAdd = 1;
            }
            else
            {
                const char *prev = selected[selectedCount - 1];
                char prevLast = prev[strlen(prev) - 1];
                if (word[0] == prevLast)
                {
                    shouldAdd = 1;
                }
            }

            if (shouldAdd && !appendSelectedWord(&selected, &selectedCount, &selectedCapacity, word))
            {
                printf("Memory allocation failed.\n");
                freeWordArray(selected, selectedCount);
                fclose(in);
                return;
            }

            len = 0;
        }
    }

    if (len > 0)
    {
        word[len] = '\0';

        int shouldAdd = 0;
        if (selectedCount == 0)
        {
            shouldAdd = 1;
        }
        else
        {
            const char *prev = selected[selectedCount - 1];
            char prevLast = prev[strlen(prev) - 1];
            if (word[0] == prevLast)
            {
                shouldAdd = 1;
            }
        }

        if (shouldAdd && !appendSelectedWord(&selected, &selectedCount, &selectedCapacity, word))
        {
            printf("Memory allocation failed.\n");
            freeWordArray(selected, selectedCount);
            fclose(in);
            return;
        }
    }

    fclose(in);

    FILE *out = fopen(binaryFile, "wb");
    if (out == NULL)
    {
        printf("Cannot open output binary file.\n");
        freeWordArray(selected, selectedCount);
        return;
    }

    for (int i = 0; i < selectedCount; i++)
    {
        fwrite(selected[i], 1, strlen(selected[i]), out);
        if (i < selectedCount - 1)
        {
            fwrite(" ", 1, 1, out);
        }
    }
    fclose(out);

    printf("Saved %d selected words to binary file.\n", selectedCount);

    printf("Binary file content:\n");
    out = fopen(binaryFile, "rb");
    if (out == NULL)
    {
        printf("Cannot reopen binary file.\n");
        freeWordArray(selected, selectedCount);
        return;
    }

    while ((ch = fgetc(out)) != EOF)
    {
        putchar(ch);
    }
    putchar('\n');

    fclose(out);
    freeWordArray(selected, selectedCount);
}

void runFourth(void)
{
    char inputFile[260];
    char outputFile[260];
    int key;

    printf("Enter input file path: ");
    if (fgets(inputFile, sizeof(inputFile), stdin) == NULL)
    {
        printf("Invalid input file path.\n");
        return;
    }
    trimNewline(inputFile);

    if (!readInt("Enter key (2..10): ", &key) || key < 2 || key > 10)
    {
        printf("Invalid key.\n");
        return;
    }

    printf("Enter output file path: ");
    if (fgets(outputFile, sizeof(outputFile), stdin) == NULL)
    {
        printf("Invalid output file path.\n");
        return;
    }
    trimNewline(outputFile);

    FILE *in = fopen(inputFile, "rb");
    if (in == NULL)
    {
        printf("Cannot open input file.\n");
        return;
    }

    FILE *out = fopen(outputFile, "wb");
    if (out == NULL)
    {
        fclose(in);
        printf("Cannot open output file.\n");
        return;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF)
    {
        unsigned char encoded = (unsigned char)(((unsigned char)ch) + key);
        fputc(encoded, out);
    }

    fclose(in);
    fclose(out);

    printf("Encoding completed.\n");
}

void runFifth(void)
{
    const char *wordList[] = {
        "concatenation",
        "computer",
        "programming",
        "pointer",
        "function"
    };
    const int wordCount = (int)(sizeof(wordList) / sizeof(wordList[0]));

    srand((unsigned int)time(NULL));
    const char *target = wordList[rand() % wordCount];
    int len = (int)strlen(target);

    char *masked = (char *)malloc((size_t)len + 1);
    if (masked == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < len; i++)
    {
        masked[i] = '_';
    }
    masked[len] = '\0';

    bool guessed[256] = {false};
    int enteredLetters = 0;

    printf("Guess the word. You can win with at most length + 2 letters.\n");

    while (strcmp(masked, target) != 0)
    {
        char line[64];
        printf("Word: %s\n", masked);
        printf("Enter letter: ");

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            continue;
        }

        char letter = (char)tolower((unsigned char)line[0]);
        if (!isalpha((unsigned char)letter))
        {
            printf("Please enter a letter.\n");
            continue;
        }

        if (!guessed[(unsigned char)letter])
        {
            guessed[(unsigned char)letter] = true;
            enteredLetters++;
        }

        bool found = false;
        for (int i = 0; i < len; i++)
        {
            if (target[i] == letter)
            {
                masked[i] = letter;
                found = true;
            }
        }

        if (!found)
        {
            printf("No such letter.\n");
        }
    }

    printf("Word guessed: %s\n", target);
    printf("Entered letters: %d\n", enteredLetters);

    if (enteredLetters <= len + 2)
    {
        printf("You win.\n");
    }
    else
    {
        printf("You guessed the word, but with too many letters.\n");
    }

    free(masked);
}

static int isAnagram(const char *a, const char *b)
{
    int counts[256] = {0};

    for (int i = 0; a[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)a[i];
        if (!isspace(c))
        {
            c = (unsigned char)tolower(c);
            counts[c]++;
        }
    }

    for (int i = 0; b[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)b[i];
        if (!isspace(c))
        {
            c = (unsigned char)tolower(c);
            counts[c]--;
        }
    }

    for (int i = 0; i < 256; i++)
    {
        if (counts[i] != 0)
        {
            return 0;
        }
    }

    return 1;
}

void runSixth(void)
{
    char first[256];
    char second[256];

    printf("Enter first string: ");
    if (fgets(first, sizeof(first), stdin) == NULL)
    {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter second string: ");
    if (fgets(second, sizeof(second), stdin) == NULL)
    {
        printf("Invalid input.\n");
        return;
    }

    trimNewline(first);
    trimNewline(second);

    printf("Result: %d\n", isAnagram(first, second));
}

static double computeWeeklySalary(double hourlyRate, double workedHours)
{
    double regularHours = workedHours;
    double overtimeHours = 0.0;

    if (workedHours > 40.0)
    {
        regularHours = 40.0;
        overtimeHours = workedHours - 40.0;
    }

    double gross = regularHours * hourlyRate + overtimeHours * hourlyRate * 1.5;
    double net = gross * (1.0 - 0.0365);
    return net;
}

static long employeeCountInFile(const char *fileName)
{
    FILE *f = fopen(fileName, "rb");
    if (f == NULL)
    {
        return 0;
    }

    if (fseek(f, 0L, SEEK_END) != 0)
    {
        fclose(f);
        return 0;
    }

    long bytes = ftell(f);
    fclose(f);

    if (bytes < 0)
    {
        return 0;
    }

    return bytes / (long)sizeof(Employee);
}

static void addEmployeeRecord(const char *fileName)
{
    long currentCount = employeeCountInFile(fileName);
    if (currentCount >= 30)
    {
        printf("Cannot add more than 30 employees.\n");
        return;
    }

    Employee e;

    if (!readInt("Employee id: ", &e.id))
    {
        printf("Invalid id.\n");
        return;
    }

    if (!readDouble("Hourly rate: ", &e.hourlyRate) || e.hourlyRate < 0)
    {
        printf("Invalid hourly rate.\n");
        return;
    }

    if (!readDouble("Worked hours (weekly): ", &e.workedHours) || e.workedHours < 0)
    {
        printf("Invalid worked hours.\n");
        return;
    }

    e.weeklySalary = computeWeeklySalary(e.hourlyRate, e.workedHours);

    FILE *f = fopen(fileName, "ab");
    if (f == NULL)
    {
        printf("Cannot open employee file.\n");
        return;
    }

    fwrite(&e, sizeof(Employee), 1, f);
    fclose(f);

    printf("Employee saved. Weekly salary (after tax): %.2f\n", e.weeklySalary);
}

static void showEmployeeSalaries(const char *fileName)
{
    FILE *f = fopen(fileName, "rb");
    if (f == NULL)
    {
        printf("No employee file found yet.\n");
        return;
    }

    Employee e;
    int found = 0;

    while (fread(&e, sizeof(Employee), 1, f) == 1)
    {
        printf("ID: %d | Rate: %.2f | Hours: %.2f | Weekly salary: %.2f\n",
               e.id,
               e.hourlyRate,
               e.workedHours,
               e.weeklySalary);
        found = 1;
    }

    fclose(f);

    if (!found)
    {
        printf("Employee file is empty.\n");
    }
}

void runSeventh(void)
{
    const char *fileName = "employees.dat";
    int choice;

    while (1)
    {
        printf("\n--- Employee Menu ---\n");
        printf("1. Add employee record\n");
        printf("2. Show weekly salaries\n");
        printf("0. Back\n");

        if (!readInt("Choose option: ", &choice))
        {
            printf("Invalid option.\n");
            continue;
        }

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
            case 1: addEmployeeRecord(fileName); break;
            case 2: showEmployeeSalaries(fileName); break;
            default: printf("Unknown option.\n"); break;
        }
    }
}

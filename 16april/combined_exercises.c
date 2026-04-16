#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 100

typedef struct {
    int op;
    int x;
} Query;

static void print_line(void) {
    printf("============================================================\n");
}

static void print_title(const char *title) {
    print_line();
    printf("%s\n", title);
    print_line();
}

static void clear_input(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

static int read_int(const char *prompt, int *value) {
    printf("%s", prompt);
    if (scanf("%d", value) != 1) {
        clear_input();
        return 0;
    }
    return 1;
}

static int cmp_int(const void *a, const void *b) {
    int aa = *(const int *)a;
    int bb = *(const int *)b;
    if (aa < bb) {
        return -1;
    }
    if (aa > bb) {
        return 1;
    }
    return 0;
}

static int lower_bound_int(const int *arr, int n, int target) {
    int left = 0;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

static void fenwick_add(int *bit, int n, int index, int delta) {
    while (index <= n) {
        bit[index] += delta;
        index += index & -index;
    }
}

static int fenwick_sum(const int *bit, int index) {
    int result = 0;
    while (index > 0) {
        result += bit[index];
        index -= index & -index;
    }
    return result;
}

static int fenwick_find_kth(const int *bit, int n, int k) {
    int index = 0;
    int step = 1;

    while ((step << 1) <= n) {
        step <<= 1;
    }

    while (step > 0) {
        int next = index + step;
        if (next <= n && bit[next] < k) {
            index = next;
            k -= bit[next];
        }
        step >>= 1;
    }

    return index + 1;
}

static int is_prime(int number) {
    if (number < 2) {
        return 0;
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

static void print_array(const int *arr, int size, const char *label) {
    printf("%s", label);
    if (size == 0) {
        printf("[empty]\n");
        return;
    }

    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

static void exercise_1(void) {
    print_title("Exercise 1: Matrix row/column order check");

    int n, m;
    if (!read_int("Enter rows n: ", &n) || !read_int("Enter cols m: ", &m) || n <= 0 || m <= 0) {
        printf("Invalid matrix size.\n");
        return;
    }

    int *array = (int *)malloc((size_t)n * (size_t)m * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            if (scanf("%d", &array[i * m + j]) != 1) {
                printf("Invalid value.\n");
                free(array);
                clear_input();
                return;
            }
        }
    }

    bool columnDecreasing = true;
    bool rowIncreasing = true;

    for (int i = 1; i < n && columnDecreasing; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i * m + j] >= array[(i - 1) * m + j]) {
                columnDecreasing = false;
                break;
            }
        }
    }

    for (int i = 0; i < n && rowIncreasing; i++) {
        for (int j = 1; j < m; j++) {
            if (array[i * m + j] <= array[i * m + (j - 1)]) {
                rowIncreasing = false;
                break;
            }
        }
    }

    printf("\nResult:\n");
    printf("Rows increasing: %s\n", rowIncreasing ? "YES" : "NO");
    printf("Columns decreasing: %s\n", columnDecreasing ? "YES" : "NO");

    free(array);
}

static void exercise_2(void) {
    print_title("Exercise 2: Element with biggest neighbor sum");

    int n, m;
    if (!read_int("Enter N: ", &n) || !read_int("Enter M: ", &m) || n <= 0 || m <= 0 || n > MAXN || m > MAXN) {
        printf("Invalid size. Valid range is 1..%d for both dimensions.\n", MAXN);
        return;
    }

    int a[MAXN][MAXN];
    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Invalid value.\n");
                clear_input();
                return;
            }
        }
    }

    int bestVal = 0;
    int bestSum = 0;
    int found = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) {
                        continue;
                    }
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        sum += a[ni][nj];
                    }
                }
            }

            if (!found || sum > bestSum) {
                found = 1;
                bestSum = sum;
                bestVal = a[i][j];
            }
        }
    }

    printf("Element with largest adjacent sum: %d\n", bestVal);
    printf("Adjacent sum: %d\n", bestSum);
}

static void exercise_3(void) {
    print_title("Exercise 3: Swap rows of min and max element (3x3)");

    int n = 3;
    int m = 3;
    int array[3][3];

    printf("Enter 9 elements for a 3x3 matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &array[i][j]) != 1) {
                printf("Invalid value.\n");
                clear_input();
                return;
            }
        }
    }

    int maxElement = array[0][0];
    int minElement = array[0][0];
    int maxRow = 0;
    int minRow = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] > maxElement) {
                maxElement = array[i][j];
                maxRow = i;
            }
            if (array[i][j] < minElement) {
                minElement = array[i][j];
                minRow = i;
            }
        }
    }

    if (maxRow != minRow) {
        for (int j = 0; j < m; j++) {
            int temp = array[maxRow][j];
            array[maxRow][j] = array[minRow][j];
            array[minRow][j] = temp;
        }
    }

    printf("Max element: %d (row %d)\n", maxElement, maxRow);
    printf("Min element: %d (row %d)\n", minElement, minRow);
    printf("Matrix after swap:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

static void exercise_4(void) {
    print_title("Exercise 4: Friendship graph query");

    int n, m;
    if (!read_int("Enter number of people N: ", &n) || !read_int("Enter friendships M: ", &m) || n <= 0 || m < 0) {
        printf("Invalid N or M.\n");
        return;
    }

    int *head = (int *)malloc((size_t)(n + 1) * sizeof(int));
    int *degree = (int *)calloc((size_t)(n + 1), sizeof(int));
    int *to = (int *)malloc((size_t)(2 * m) * sizeof(int));
    int *next = (int *)malloc((size_t)(2 * m) * sizeof(int));

    if (head == NULL || degree == NULL || to == NULL || next == NULL) {
        printf("Memory allocation failed.\n");
        free(head);
        free(degree);
        free(to);
        free(next);
        return;
    }

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }

    int edgeIndex = 0;
    printf("Enter friendships as pairs: a b\n");
    for (int i = 0; i < m; i++) {
        int a, b;
        printf("friendship %d/%d: ", i + 1, m);
        if (scanf("%d %d", &a, &b) != 2) {
            printf("Invalid input.\n");
            clear_input();
            free(head);
            free(degree);
            free(to);
            free(next);
            return;
        }

        if (a < 1 || a > n || b < 1 || b > n) {
            continue;
        }

        to[edgeIndex] = b;
        next[edgeIndex] = head[a];
        head[a] = edgeIndex;
        edgeIndex++;

        to[edgeIndex] = a;
        next[edgeIndex] = head[b];
        head[b] = edgeIndex;
        edgeIndex++;

        degree[a]++;
        degree[b]++;
    }

    int q;
    if (!read_int("How many queries Q: ", &q) || q < 0) {
        printf("Invalid Q.\n");
        free(head);
        free(degree);
        free(to);
        free(next);
        return;
    }

    for (int i = 0; i < q; i++) {
        int person;
        printf("Person id (%d/%d): ", i + 1, q);
        if (scanf("%d", &person) != 1) {
            printf("Invalid input.\n");
            clear_input();
            break;
        }

        if (person < 1 || person > n) {
            printf("Person out of range -> 0 friends\n");
            continue;
        }
        printf("Person %d has %d friends\n", person, degree[person]);
    }

    free(head);
    free(degree);
    free(to);
    free(next);
}

static void exercise_5(void) {
    print_title("Exercise 5: Ordered multiset commands");

    int q;
    if (!read_int("Enter number of commands q: ", &q) || q < 0) {
        printf("Invalid q.\n");
        return;
    }

    Query *queries = (Query *)malloc((size_t)q * sizeof(Query));
    int *values = (int *)malloc((size_t)q * sizeof(int));
    if (queries == NULL || values == NULL) {
        printf("Memory allocation failed.\n");
        free(queries);
        free(values);
        return;
    }

    printf("Command format: op x\n");
    printf("1 x => add(x), 2 x => delete(x), 3 x => x-th smallest\n");

    int value_count = 0;
    for (int i = 0; i < q; i++) {
        if (scanf("%d %d", &queries[i].op, &queries[i].x) != 2) {
            printf("Invalid command.\n");
            clear_input();
            free(queries);
            free(values);
            return;
        }
        if (queries[i].op == 1 || queries[i].op == 2) {
            values[value_count++] = queries[i].x;
        }
    }

    if (value_count == 0) {
        for (int i = 0; i < q; i++) {
            if (queries[i].op == 3) {
                printf("invalid\n");
            }
        }
        free(queries);
        free(values);
        return;
    }

    qsort(values, (size_t)value_count, sizeof(int), cmp_int);

    int unique_count = 0;
    for (int i = 0; i < value_count; i++) {
        if (i == 0 || values[i] != values[i - 1]) {
            values[unique_count++] = values[i];
        }
    }

    int *bit = (int *)calloc((size_t)unique_count + 1, sizeof(int));
    int *freq = (int *)calloc((size_t)unique_count + 1, sizeof(int));
    if (bit == NULL || freq == NULL) {
        printf("Memory allocation failed.\n");
        free(queries);
        free(values);
        free(bit);
        free(freq);
        return;
    }

    for (int i = 0; i < q; i++) {
        int op = queries[i].op;
        int x = queries[i].x;

        if (op == 1 || op == 2) {
            int pos = lower_bound_int(values, unique_count, x) + 1;
            if (op == 1) {
                freq[pos]++;
                fenwick_add(bit, unique_count, pos, 1);
            } else {
                if (freq[pos] > 0) {
                    fenwick_add(bit, unique_count, pos, -freq[pos]);
                    freq[pos] = 0;
                }
            }
        } else if (op == 3) {
            int total = fenwick_sum(bit, unique_count);
            if (x <= 0 || x > total) {
                printf("invalid\n");
            } else {
                int pos = fenwick_find_kth(bit, unique_count, x);
                printf("%d\n", values[pos - 1]);
            }
        }
    }

    int total = fenwick_sum(bit, unique_count);
    if (total == 0) {
        printf("Final multiset: [empty]\n");
    } else {
        printf("Final multiset: ");
        for (int i = 1; i <= unique_count; i++) {
            for (int j = 0; j < freq[i]; j++) {
                printf("%d ", values[i - 1]);
            }
        }
        printf("\n");
    }

    free(queries);
    free(values);
    free(bit);
    free(freq);
}

static void exercise_6(void) {
    print_title("Exercise 6: Extract primes into second dynamic array");

    int n;
    if (!read_int("Enter n (positive): ", &n) || n <= 0) {
        printf("Invalid n.\n");
        return;
    }

    int *original = (int *)malloc((size_t)n * sizeof(int));
    int *primes = NULL;
    int primes_count = 0;
    int non_primes_count = 0;

    if (original == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &original[i]) != 1) {
            printf("Invalid value.\n");
            clear_input();
            free(original);
            free(primes);
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (is_prime(original[i])) {
            int *temp = (int *)realloc(primes, (size_t)(primes_count + 1) * sizeof(int));
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(original);
                free(primes);
                return;
            }
            primes = temp;
            primes[primes_count++] = original[i];
        } else {
            original[non_primes_count++] = original[i];
        }
    }

    if (non_primes_count == 0) {
        free(original);
        original = NULL;
    } else {
        int *temp = (int *)realloc(original, (size_t)non_primes_count * sizeof(int));
        if (temp != NULL) {
            original = temp;
        }
    }

    print_array(original, non_primes_count, "Without prime numbers: ");
    print_array(primes, primes_count, "Only prime numbers: ");

    free(original);
    free(primes);
}

static void exercise_7(void) {
    print_title("Exercise 7: Best 3x3 submatrix by maximum sum");

    int n, m;
    if (!read_int("Enter rows n (>=3): ", &n) || !read_int("Enter cols m (>=3): ", &m) || n < 3 || m < 3) {
        printf("Invalid size. Need n >= 3 and m >= 3.\n");
        return;
    }

    int *matrix = (int *)malloc((size_t)n * (size_t)m * sizeof(int));
    if (matrix == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            if (scanf("%d", &matrix[i * m + j]) != 1) {
                printf("Invalid value.\n");
                clear_input();
                free(matrix);
                return;
            }
        }
    }

    int maxSum = INT_MIN;
    int bestRow = 0;
    int bestCol = 0;

    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            int currentSum = 0;
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    currentSum += matrix[(i + r) * m + (j + c)];
                }
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
                bestRow = i;
                bestCol = j;
            }
        }
    }

    printf("Best 3x3 submatrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[(bestRow + i) * m + (bestCol + j)]);
        }
        printf("\n");
    }
    printf("Maximum sum = %d\n", maxSum);

    free(matrix);
}

static void exercise_8(void) {
    print_title("Exercise 8: Dynamic array insertion by index");

    int capacity = 10;
    int size = 10;
    int *arr = (int *)malloc((size_t)capacity * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter 10 initial integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("value #%d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid value.\n");
            clear_input();
            free(arr);
            return;
        }
    }

    while (1) {
        int value;
        int index;

        if (!read_int("Insert value (0 = stop): ", &value)) {
            printf("Invalid value.\n");
            continue;
        }

        if (value == 0) {
            break;
        }

        if (!read_int("Insert index [0..size]: ", &index)) {
            printf("Invalid index.\n");
            continue;
        }

        while (index < 0 || index > size) {
            if (!read_int("Invalid index, try again: ", &index)) {
                printf("Invalid index.\n");
            }
        }

        if (size == capacity) {
            capacity *= 2;
            int *temp = (int *)realloc(arr, (size_t)capacity * sizeof(int));
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(arr);
                return;
            }
            arr = temp;
        }

        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = value;
        size++;
    }

    printf("Final array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

static void print_menu(void) {
    print_title("16 April - Combined Exercises App");
    printf("1) Matrix order check\n");
    printf("2) Biggest adjacent-neighbor sum\n");
    printf("3) Swap min/max rows in 3x3\n");
    printf("4) Friendship queries\n");
    printf("5) Ordered multiset commands\n");
    printf("6) Prime extraction with dynamic arrays\n");
    printf("7) Maximum-sum 3x3 submatrix\n");
    printf("8) Dynamic insertions by index\n");
    printf("0) Exit\n");
    print_line();
}

int main(void) {
    while (1) {
        int option;
        print_menu();
        if (!read_int("Choose an option: ", &option)) {
            printf("Invalid option.\n\n");
            continue;
        }

        switch (option) {
            case 0:
                print_line();
                printf("Thanks for using the combined app. Goodbye.\n");
                print_line();
                return 0;
            case 1:
                exercise_1();
                break;
            case 2:
                exercise_2();
                break;
            case 3:
                exercise_3();
                break;
            case 4:
                exercise_4();
                break;
            case 5:
                exercise_5();
                break;
            case 6:
                exercise_6();
                break;
            case 7:
                exercise_7();
                break;
            case 8:
                exercise_8();
                break;
            default:
                printf("Unknown option. Try again.\n");
                break;
        }

        printf("\nPress Enter to return to main menu...");
        clear_input();
        getchar();
    }
}
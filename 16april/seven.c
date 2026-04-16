#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
	int n, m;

	printf("Въведете броя редове n (цяло число, n >= 3): ");
	scanf("%d", &n);

	printf("Въведете броя колони m (цяло число, m >= 3): ");
	scanf("%d", &m);

	if (n < 3 || m < 3) {
		printf("Грешка: за да има подматрица 3x3, n и m трябва да са поне 3.\n");
		printf("Изход: програмата приключи без изчисление.\n");
		return 0;
	}

	int *matrix = (int *)malloc((size_t)n * (size_t)m * sizeof(int));
	if (matrix == NULL) {
		printf("Грешка: неуспешно заделяне на памет.\n");
		return 1;
	}

	printf("\nВъведете елементите на матрицата (цели числа):\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("Въведете стойност за елемент a[%d][%d]: ", i, j);
			scanf("%d", &matrix[i * m + j]);
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

	printf("\nИзход:\n");
	printf("Подматрица 3x3 с максимална сума:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", matrix[(bestRow + i) * m + (bestCol + j)]);
		}
		printf("\n");
	}
	printf("Максимална сума = %d\n", maxSum);

	free(matrix);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int is_prime(int number) {
	int i;

	if (number < 2) {
		return 0;
	}

	for (i = 2; i * i <= number; i++) {
		if (number % i == 0) {
			return 0;
		}
	}

	return 1;
}

void print_array(const int *arr, int size, const char *label) {
	int i;

	printf("\n%s", label);
	if (size == 0) {
		printf("[empty]\n");
		return;
	}

	printf("[");
	for (i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main(void) {
	int n;
	int i;
	int *original = NULL;
	int *primes = NULL;
	int primes_count = 0;
	int non_primes_count = 0;

	printf("Exercise 6: Dynamic arrays and prime number extraction\n");
	printf("------------------------------------------------------\n");
	printf("Enter the number of elements n (positive integer): ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Invalid input! n must be a positive integer.\n");
		return 1;
	}

	original = (int *)malloc(n * sizeof(int));
	if (original == NULL) {
		printf("Memory allocation failed for the first array.\n");
		return 1;
	}

	printf("\nNow enter %d integer values:\n", n);
	for (i = 0; i < n; i++) {
		printf("Element %d -> enter an integer: ", i + 1);
		scanf("%d", &original[i]);
	}

	for (i = 0; i < n; i++) {
		if (is_prime(original[i])) {
			int *temp = (int *)realloc(primes, (primes_count + 1) * sizeof(int));
			if (temp == NULL) {
				printf("Memory reallocation failed for the second array.\n");
				free(original);
				free(primes);
				return 1;
			}
			primes = temp;
			primes[primes_count] = original[i];
			primes_count++;
		} else {
			original[non_primes_count] = original[i];
			non_primes_count++;
		}
	}

	if (non_primes_count == 0) {
		free(original);
		original = NULL;
	} else {
		int *temp = (int *)realloc(original, non_primes_count * sizeof(int));
		if (temp != NULL) {
			original = temp;
		}
	}

	printf("\n================ FINAL OUTPUT ================\n");
	print_array(original, non_primes_count, "Array after removing prime numbers: ");
	print_array(primes, primes_count, "Second dynamic array with only prime numbers: ");
	printf("=============================================\n");

	free(original);
	free(primes);

	return 0;
}

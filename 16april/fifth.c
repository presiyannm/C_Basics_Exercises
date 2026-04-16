#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int op;
	int x;
} Query;

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

int main(void) {
	int q;
	printf("Vavedi broi komandi q (cqlo chislo): ");
	if (scanf("%d", &q) != 1 || q < 0) {
		return 0;
	}

	printf("Vavedi vsqka komanda kato dva celi nomera: op x\n");
	printf("1 x -> add(x), 2 x -> delete(x), 3 x -> smallest(x)\n");
	printf("Primer: 1 5\n");

	Query *queries = (Query *)malloc((size_t)q * sizeof(Query));
	int *values = (int *)malloc((size_t)q * sizeof(int));

	if (queries == NULL || values == NULL) {
		free(queries);
		free(values);
		return 0;
	}

	int value_count = 0;
	for (int i = 0; i < q; i++) {
		if (scanf("%d %d", &queries[i].op, &queries[i].x) != 2) {
			free(queries);
			free(values);
			return 0;
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
		return 0;
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
		free(queries);
		free(values);
		free(bit);
		free(freq);
		return 0;
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

	{
		int total = fenwick_sum(bit, unique_count);
		if (total == 0) {
			printf("Kraen rezultat: prazno\n");
		} else {
			printf("Kraen rezultat (sortirano): ");
			for (int i = 1; i <= unique_count; i++) {
				for (int j = 0; j < freq[i]; j++) {
					printf("%d ", values[i - 1]);
				}
			}
			printf("\n");
		}
	}

	free(queries);
	free(values);
	free(bit);
	free(freq);

	return 0;
}

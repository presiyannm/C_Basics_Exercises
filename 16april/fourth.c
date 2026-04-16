#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m;
	printf("Vavedi broi hora N (1..100000) i broi priyatelstva M (1..1000000):\n");
	printf("Format: N M\n");
	if (scanf("%d %d", &n, &m) != 2)
	{
		return 0;
	}

	/* Adjacency list in arrays: head[u] -> linked edges via next[] */
	int *head = (int *)malloc((n + 1) * sizeof(int));
	int *degree = (int *)calloc((n + 1), sizeof(int));
	int *to = (int *)malloc((2 * m) * sizeof(int));
	int *next = (int *)malloc((2 * m) * sizeof(int));

	if (head == NULL || degree == NULL || to == NULL || next == NULL)
	{
		free(head);
		free(degree);
		free(to);
		free(next);
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		head[i] = -1;
	}

	int edgeIndex = 0;
	printf("Vavedi %d reda s priyatelstva (po dve chisla: a b).\n", m);
	printf("Primer: 1 3 oznachava, che 1 i 3 sa priyateli.\n");
	for (int i = 0; i < m; i++)
	{
		int a, b;
		printf("Priyatelstvo %d/%d (a b): ", i + 1, m);
		scanf("%d %d", &a, &b);

		if (a < 1 || a > n || b < 1 || b > n)
		{
			continue;
		}

		/* a -> b */
		to[edgeIndex] = b;
		next[edgeIndex] = head[a];
		head[a] = edgeIndex;
		edgeIndex++;

		/* b -> a (friendship is mutual) */
		to[edgeIndex] = a;
		next[edgeIndex] = head[b];
		head[b] = edgeIndex;
		edgeIndex++;

		degree[a]++;
		degree[b]++;
	}

	int q;
	printf("Vavedi broi zapitvaniya Q (za kolko choveka iskash broi priyateli):\n");
	if (scanf("%d", &q) != 1)
	{
		free(head);
		free(degree);
		free(to);
		free(next);
		return 0;
	}

	for (int i = 0; i < q; i++)
	{
		int person;
		printf("Vavedi nomer na chovek za zapitvane (%d/%d): ", i + 1, q);
		scanf("%d", &person);

		if (person < 1 || person > n)
		{
			printf("Nevaliden nomer. Broi priyateli: 0\n");
			continue;
		}

		/* Required output: how many friends this person has */
		printf("Chovek %d ima %d priyateli.\n", person, degree[person]);

		/*
		   If you also need to print the friend IDs, uncomment:
		   for (int e = head[person]; e != -1; e = next[e])
		   {
			   printf("%d ", to[e]);
		   }
		   printf("\n");
		*/
	}

	free(head);
	free(degree);
	free(to);
	free(next);

	return 0;
}

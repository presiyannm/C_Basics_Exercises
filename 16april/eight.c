#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int capacity = 10;
	int size = 10;
	int *arr = (int *)malloc(capacity * sizeof(int));

	if (arr == NULL)
	{
		printf("Greshka: neuspeshno zadeliane na pamet.\n");
		return 1;
	}

	printf("Vavedete 10 celi chisla za nachalni danni.\n");
	printf("Te shte se zapisvat v dinamichen masiv i posle shte mozhe da vmakvate novi elementi po index.\n\n");

	for (int i = 0; i < 10; i++)
	{
		printf("Nachalno chislo #%d (to opredelia bazovoto sastoyanie na masiva): ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("\nZapochva vmakvane na novi chisla.\n");
	printf("Pravila: parvo vavezhdate chislo za vmakvane, sled tova index.\n");
	printf("Ako vavedete 0 za chislo, procesat priklyuchva i se pechata kraen rezultat.\n\n");

	while (1)
	{
		int value;
		int index;

		printf("Vavedete chislo za vmakvane (0 = krai): ");
		scanf("%d", &value);

		if (value == 0)
		{
			break;
		}

		printf("Vavedete index za vmakvane (ot 0 do %d), za da se izbutat elementite nadiasno: ", size);
		scanf("%d", &index);

		while (index < 0 || index > size)
		{
			printf("Nevaliden index. Molya vavedete stoynost ot 0 do %d: ", size);
			scanf("%d", &index);
		}

		if (size == capacity)
		{
			capacity *= 2;
			int *temp = (int *)realloc(arr, capacity * sizeof(int));
			if (temp == NULL)
			{
				free(arr);
				printf("Greshka: neuspeshno preoformiane na pamet.\n");
				return 1;
			}
			arr = temp;
		}

		for (int i = size; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}

		arr[index] = value;
		size++;
	}

	printf("\nKraen masiv sled vsichki vmakvania:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
	return 0;
}

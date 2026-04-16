#include <stdio.h>

#define MAXN 100

int main() {
    int n, m;
    printf("Въведи N и M: ");
    scanf("%d %d", &n, &m);

    int a[MAXN][MAXN];
    printf("Въведи елементите:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    int bestVal = 0, bestSum = -1;
    int found = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                        sum += a[ni][nj];
                }
            }
            if (!found || sum > bestSum) {
                bestSum = sum;
                bestVal = a[i][j];
                found = 1;
            }
        }
    }

    printf("Число с най-голям съседен сбор: %d (сбор = %d)\n", bestVal, bestSum);
    return 0;
}

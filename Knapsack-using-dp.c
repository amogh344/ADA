#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int v[MAX][MAX], w[MAX], p[MAX], x[MAX], count = 0;

int max(int a, int b);
void findObjects(int n, int m);

int main() {
    int m, n, i, j;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &m);

    printf("Enter the weights of the objects: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter the profits: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (j < w[i]) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
        }
    }

    printf("The output is:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }

    printf("Maximum profit is: %d\n", v[n][m]);
    findObjects(n, m);

    printf("Objects included in knapsack:\n");
    for (i = 1; i <= count; i++) {
        printf("%d\t", x[i]);
    }

    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void findObjects(int n, int m) {
    int i = n, j = m;
    while (i != 0 && j != 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[++count] = i;
            j -= w[i];
        }
        i--;
    }
}

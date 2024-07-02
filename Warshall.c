#include <stdio.h>

void warshall(int a[10][10], int n);

int main() {
    int i, j, n, a[10][10];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("(%d, %d): ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    warshall(a, n);

    printf("Transitive closure for the given graph is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void warshall(int a[10][10], int n) {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
}

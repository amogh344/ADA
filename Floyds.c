#include <stdio.h>
#include <time.h>

#define INFINITY 999

int min(int a, int b) {
    return a < b ? a : b;
}

void floyd(int w[10][10], int n) {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
}

int main(void) {
    int a[10][10], n, i, j;
    double startTime, endTime;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix (0 for self-loop and 999 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    startTime = clock();
    floyd(a, n);
    endTime = clock();

    printf("\nShortest path matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("Time taken is %10.9f seconds\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

    return 0;
}

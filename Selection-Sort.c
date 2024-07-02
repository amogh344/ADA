#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20000

void selectionSort(int a[], int n);
void printArray(int a[], int n);

int main(void) {
    int a[MAX], n;
    clock_t start, end;

    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000;  // Limiting the range for better readability

    printf("Unsorted array:\n");
    printArray(a, n);

    start = clock();
    selectionSort(a, n);
    end = clock();

    printf("Sorted array:\n");
    printArray(a, n);

    printf("Time taken is %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
        if ((i + 1) % 20 == 0)  // Print 20 elements per line for better readability
            printf("\n");
    }
    printf("\n");
}

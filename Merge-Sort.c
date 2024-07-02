#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

void merge(int a[], int low, int mid, int high);
void mergeSort(int a[], int low, int high);
void printArray(int a[], int n);

int main(void) {
    int a[MAX], n;
    clock_t start, end;

    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 10000;

    printf("Unsorted array:\n");
    printArray(a, n);

    start = clock();
    mergeSort(a, 0, n - 1);
    end = clock();

    printf("Sorted array:\n");
    printArray(a, n);

    printf("Time taken is %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int c[high - low + 1];

    while (i <= mid && j <= high)
        c[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while (i <= mid)
        c[k++] = a[i++];

    while (j <= high)
        c[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = c[k];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
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

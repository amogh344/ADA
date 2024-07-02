#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void swap(int *a, int *b);
void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);
void printArray(int a[], int n);

int main(void) {
    int a[MAX], n;
    clock_t start, end;

    printf("Enter number of elements to sort: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = rand();

    printf("Unsorted array:\n");
    printArray(a, n);

    start = clock();
    quicksort(a, 0, n - 1);
    end = clock();

    printf("Sorted array:\n");
    printArray(a, n);

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int s = partition(a, low, high);
        quicksort(a, low, s - 1);
        quicksort(a, s + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low], i = low + 1, j = high;
    while (1) {
        while (i < high && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        if (i < j)
            swap(&a[i], &a[j]);
        else {
            swap(&a[low], &a[j]);
            return j;
        }
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

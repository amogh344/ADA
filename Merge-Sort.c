#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 10000

void simple_merge(int a[], int low, int mid, int high);
void merge_sort(int a[], int low, int high);

int main(void) {
    int a[MAX], n, i = 0;
    double starttime, endtime;

    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    // Generate random elements
    for (i = 0; i < n; i++)
        a[i] = rand();

    printf("Before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    starttime = clock();
    merge_sort(a, 0, n - 1);
    endtime = clock();

    printf("\n\nAfter sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    printf("\n\nTime taken is %f\n", (double)(endtime - starttime) / CLOCKS_PER_SEC);

    return 0;
}

void simple_merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low, c[MAX];

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
        c[k++] = a[i++];

    while (j <= high)
        c[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = c[i];
}

void merge_sort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        simple_merge(a, low, mid, high);
    }
}

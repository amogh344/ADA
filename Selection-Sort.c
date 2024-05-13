#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 20000

void selectionSort(int a[], int n);

int main(void)
{
    int a[MAX], n, i;
    double startTime, endTime;

    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    // Generate random numbers
    srand(time(NULL));
    for(i = 0; i < n; i++)
        a[i] = rand();

    printf("\nBefore Sorting:\n");
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);

    startTime = clock();
    selectionSort(a, n);
    endTime = clock();

    printf("\nAfter Sorting:\n");
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);

    printf("\nTime taken is %10.9f seconds\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

    return 0;
}

// Function to perform selection sort
void selectionSort(int a[], int n)
{
    int i, j, min, temp;
    for(i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

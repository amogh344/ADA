#include <stdlib.h>
#include <stdio.h>

int count = 0;
int x[10];

int place(int k, int i);
int nqueen(int k, int n);

int main() 
{
    int n;
    printf("\nEnter the number of queens: ");
    scanf("%d", &n);
    
    if (n < 1 || n > 10) 
    {
        printf("\nInvalid number of queens. Please enter a number between 1 and 10.");
        return 1;
    }
    
    nqueen(1, n);
    
    if (count == 0) 
    {
        printf("\nNo solution found.");
    } 
    else 
    {
        printf("\nNumber of solutions found: %d", count);
    }
    
    return 0;
}

int place(int k, int i) 
{
    int j;
    for (j = 1; j < k; j++) 
    {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) 
        {
            return 0;
        }
    }
    return 1;
}

int nqueen(int k, int n) 
{
    int i, j, p;
    for (i = 1; i <= n; i++) 
    {
        if (place(k, i)) 
        {
            x[k] = i;
            if (k == n) 
            {
                count++;
                printf("Solution = %d\n", count);
                for (j = 1; j <= n; j++) 
                {
                    for (p = 1; p <= n; p++) 
                    {
                        if (x[j] == p) 
                        {
                            printf("Q\t");
                        } 
                        else 
                        {
                            printf("0\t");
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            } else 
            {
                nqueen(k + 1, n);
            }
        }
    }
    return 0;
}

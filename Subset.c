#include<stdio.h>
#include<math.h>

int i, j, k, set[10], d;
int n;
double pow(double, double);
void subset(int [], int, int);

int main() {
    printf("\n Enter the number of Elements: ");
    scanf("%d", &n);
    
    printf("\n Enter the Elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    
    printf("\n Enter the Sum: ");
    scanf("%d", &d);
    
    subset(set, n, d);
    return 0;
}

void subset(int set[], int n, int d) {
    int flag = 0;
    int index[30][100];
    int i, j, sum, k;

    for (i = 0; i < pow(2, n); i++) {
        k = i;
        sum = 0;

        for (j = 0; j < n; j++) {
            if (k & 1) {
                index[i][j] = 1;
                sum += set[j];
            } else {
                index[i][j] = 0;
            }
            k = k >> 1;
        }

        if (sum == d) {
            flag = 1;
            printf("\n Solutions Are:\n");
            for (j = 0; j < n; j++) {
                if (index[i][j] == 1) {
                    printf("\n\t %d", set[j]);
                }
            }
        }
    }

    if (flag == 0) {
        printf("\n No solutions are found!!!");
    }
}

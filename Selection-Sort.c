#include<stdio.h>
int main()
{
    int min;
    int a[5],n=5;
    printf("Enter the elements of the array in jumbled order.\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("The elements of the unsorted array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    //Selection sort

    for(int i=0;i<n;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                int temp=a[min];
                a[min]=a[j];
                a[j]=temp;
            }
        }
    }

    printf("\nThe elements of the sorted array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
return 0;

}
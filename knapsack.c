/*6.Design and implement C/C++ Program to solve 0/1 Knapsack problem using Dynamic
Programming method.*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>

int  max(int,int);

int v[10][10],w[10],p[10],x[10],count=0;
int findobjects(int n,int m);
void main()
{
	int m,n,i,j;
	printf("enter the number of objects\n");
	scanf("%d",&n);
	printf("enter the capacity of knapsack\n");
	scanf("%d",&m);
	printf("enter the weights of the objects\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("enter the profits\n");
		for(i=1;i<=n;i++)
			scanf("%d",&p[i]);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0||j==0)
			v[i][j]=0;
			else if(j<w[i])
				v[i][j]=v[i-1][j];
			else
				v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
		}
	}
	printf("the output is:\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d\t",v[i][j]);
		}
		printf("\n");
	}
	printf("maximum profit is:%d\n",v[n][m]);
	findobjects(n,m);
	printf("objects included in knapsack \n");
	for(i=1;i<=count;i++)
		printf("%d\t",x[i]);
}

int max(int a,int b)
{
	if(a>b)
	return a;
	else	
	return b;
	
}


int findobjects(int n,int m)
{
	int i,j;
	i=n;
	j=m;
	while(i!=0&&j!=0)
	{
		if(v[i][j]!=v[i-1][j])
		{
			x[++count]=i;
			m=m-w[i];
			j=m;
		}
		i--;
	}
	return 0;
}



/******************************END OF THE PROGRAM*********************************/

/* OUTPUT

enter the number of objects
5
enter the capacity of knapsack
6
enter the weights of the objects
5
2
3
1
4
enter the profits
67
23
89
55
61
the output is:
0	0	0	0	0	0	0	
0	0	0	0	0	67	67	
0	0	23	23	23	67	67	
0	0	23	89	89	112	112	
0	55	55	89	144	144	167	
0	55	55	89	144	144	167	
maximum profit is:167
objects included in knapsack 
4	3	2	

*/



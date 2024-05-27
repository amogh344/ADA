/*1 Design and implement C/C++ Program to find Minimum Cost Spanning Tree of a given connected undirected graph using Kruskal's algorithm.*/

/* Kruskal's algorithm.*/

#include<stdio.h>
void main()
{	int n,v,u,cost[10][10],parent[10]={0},i,j;
	int count=1,mincost=0,min,a,b;
	printf("\n enter no of vertices");
	scanf("%d",&n);
	printf("\n enter cost matrix");
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
	   {
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		cost[i][j]=999;
	   }
	   while(count<n)
	   {    min=999;
		for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
		     if(cost[i][j]<min)
		     {	min=cost[i][j];
			a=u=i;
			b=v=j;
		     }
	   while(parent[u])
	   u=parent[u];
	   while(parent[v])
	   v=parent[v];

	   if(u!=v)
	   {
	       count++;
	       printf("\n edge(%d,%d)=%d",a,b,min);
	       mincost+=min;
	       parent[v]=u;
	   }
	   cost[a][b]=cost[b][a]=999;
	}  /*End of While */
	   printf("\n minimum cost=%d",mincost);
}


       **********************END OF PROGRAM******************
       
       
 /*OUTPUT
       
Enter no of vertices   6

 Enter cost matrix
 
 999 7 8 999 999 999 
7 999 3 6 999 999
8 3 999 4 9 999
999 6 4 999 1 5
999 999 9 1 999 2
999 999 999 5 2 999

 edge(4,5)=1
 edge(5,6)=2
 edge(2,3)=3
 edge(3,4)=4
 edge(1,2)=7
 minimum cost=17   */

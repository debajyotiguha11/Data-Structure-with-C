
/*
Author: Debjyoti Guha
Date: 08/11/2017
Description:  Graph Operations (Modified*)
*/


#include<stdio.h>
#include<stdlib.h>
void BFS(int[20][20], int, int[20], int);
void DFS(int[20][20], int, int[20], int);
void main()
{
	int n, a[20][20], i, j, visited[20], source;
	printf("Enter Vertices: ");
	scanf("%d",&n);
	printf("Enter AdjacencyMatrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
	printf("Enter The source node: ");
	scanf("%d", &source);
	visited[source]=1;
	BFS(a,source,visited,n);
	for(i=1;i<=n;i++)
	{
		if(visited[i]!=0)
			printf("\nNODE %d is reachable",i);
		else
			printf("\nNODE %d is not reachable",i);
	}
	DFS(a,source,visited,n);
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			printf("\n Graph is connected\n");
			exit(0);
		}
	}
	printf("\n Graph is connected\n");
}

void BFS(int a[20][20],int source,int visited[20],int n)
{
	int q[20],f,r,u,v;
	f=0;
	r=-1;
	q[++r]=source;
	while(f<=r)
	{
		u=q[f++];
		for(v=1;v<=n;v++)
		{
			if(a[u][v]==1 && visited[v]==0)
			{
				q[++r]=v;
				visited[v]=1;
			}
		}
	}
}

void DFS(int a[20][20],int u,int visited[20],int n)
{
	int v;
	visited[u]=1;
	for(v=1;v<=n;v++)
	{
		if(a[u][v]==1 && visited[v]==0)
		{
			DFS(a,v,visited,n);
		}
	}
}

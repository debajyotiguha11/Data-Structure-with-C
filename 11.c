#include<stdio.h>
#include<stdlib.h>
void DFS(int a[20][20],int u, int visited[20],int n);
void BFS(int a[20][20],int source,int visited[20],int n);
void main()
{
	int i,n,j,visited[20],a[20][20],source;
	printf("Enter the no of vertices: ");
	scanf("%d",&n);
	printf("Enter the adjecency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		visited[i]=0;
	printf("Enter the source node: ");
	scanf("%d",&source);
	visited[source]=1;
	BFS(a,source,visited,n);
	for(i=0;i<n;i++)
	{	if(visited[i]!=0)
			printf("Node %d is reachable\n",i);
		else
			printf("Node %d is not Reachable!\n",i);
	}
	DFS(a,source,visited,n);
	for(i=0;i<n;i++)
	{
		if(visited[i]=0){
			printf("Graph is not connected!...\n");
			exit(0);}
	}
	printf("graph is connected!...\n");
}

void BFS(int a[20][20],int source,int visited[20],int n)
{
	int q[20],f=0,r=-1,u,v;
	q[++r]=source;
	while(f<=r)
	{
		u=q[f++];
		for(v=0;v<n;v++)
		{
			if(a[u][v]==1 && visited[v] == 0)
			{
				q[++r]=v;
				visited[v]=1;
			}
		}
	}
}
void DFS(int a[20][20],int u, int visited[20],int n)
{
	int v;
	visited[u]=1;
	for(v=1;v<n;v++)
	{
		if(a[u][v]==1 && visited[v]==0)
			DFS(a,v,visited,n);
	}
}

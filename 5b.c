#include<stdio.h>
void tower(int,char,char,char);
void main()
{
	int n;
	printf("Enter no of disks: ");
	scanf("%d",&n);
	printf("Sequence involved are\n");
	tower(n,'A','C','B');
}

void tower(int n, char from, char top, char aux)
{
	if(n==1)
	{
		printf("Move Disk 1 from %c to %c\n",from,top);
		return;
	}
	tower(n-1,from,aux,top);
	printf("Move Disk %d from %c to %c\n",n,from,top);
	tower(n-1,aux,top,from);
}

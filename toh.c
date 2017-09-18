/*
Author: Debjyoti Guha
Date: 16/09/2017
Updates:
Description: Tower Of Hanoi Script.
*/

#include<stdio.h>
void tower (int,char,char,char);
void main()
{
	int n;
	printf("Enter no of disk: ");
	scanf("%d", &n);
	printf("The sequence involved are\n");
	tower(n,'A','C','B');
}
void tower(int n, char from, char top, char aux)
{
	if(n==1)
	{
		printf("Move Disk 1 from %c to %c\n", from ,top);
		return;
	}
	tower(n-1,from,aux,top);
	printf("Move Disk %d from %c to %c\n", n,from,top);
	tower(n-1,aux,top,from);
}

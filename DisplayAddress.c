/*
Author: Debjyoti Guha
Date: 09/08/2017
Description: This will read and display int stored in an arrey with the address of the position.
*/

#include<stdio.h>
void show(int b[], int l);
void main()
{
	int i, a[50], n;
	printf("Enter no of elm\n");
	scanf("%d", &n);
	printf("Enter %d elm\n", n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	show(a,n);
}

void show(int b[], int l)
{
	int i;
	printf("The values entered and corresponding add are\n");
	for(i=0;i<l;i++)
	{
		printf("%d \t %d\n", b[i],&b[i]);
	}
}

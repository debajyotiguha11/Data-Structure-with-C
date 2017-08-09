/*
Author: Debjyoti Guha
Date: 09/08/2017
Description: This will read and display n int no using an arrey.
*/

#include<stdio.h>
int read(int b[], int l);	//function declaration
void disp(int c[], int m);	//function declaration
void main()	// Main function
{
	int i, n, a[50], x[50];
	printf("Enter no of elm\n");
	scanf("%d", &n);
	printf("Enter %d elements\n", n);
	for(i=0;i<n;i++)
	{
	x[i]=read(a,n);	// call read function
	}
	disp(x,n);	// call disp function
	
}

int read(int b[], int l) //called function
{

	int i;
	for(i=0;i<l;i++)
	{
		scanf("%d", &b[i]);
		return b[i];
	}
}

void disp(int c[], int m) //called function
{
	int i;
	printf("Entered elm are\n");
	for(i=0;i<m;i++)
	{
		printf("%d\n", c[i]);
	}
}

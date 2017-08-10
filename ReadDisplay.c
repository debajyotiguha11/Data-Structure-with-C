/*
Author: Debjyoti Guha
Date: 09/08/2017
Update: 10/08/2017
Update includes Size and Time optimization algorithm.
Description: This will read and display n int no using an arrey.
*/

#include<stdio.h>
void read(int b[], int l);	//function declaration
void disp(int c[], int m);	//function declaration
void main()	// Main function
{
	int i, n, a[50];
	printf("Enter number of elm\n");
	scanf("%d", &n);
	read(a,n);	// call read function
	disp(a,n);	// call disp function

}

void read(int b[], int l) //called function
{
	int i;
	printf("Enter %d Intiger elements\n", l);
        	for(i=0;i<l;i++)
        	{
			scanf("%d", &b[i]);
		}
}

void disp(int c[], int m) //called function
{
	int i;
	printf("Entered elements are\n");
		for(i=0;i<m;i++)
		{
			printf("%d\n", c[i]);
		}
}

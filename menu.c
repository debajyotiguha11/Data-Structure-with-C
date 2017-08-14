/*
Author: Debjyoti Guha
Date: 14/08/2017
Updates: Minor Fixes and code Simplicity . 
Description: This is a MENU driven function for creating an arrey, insertion elements, deleting elements and display the arrey.
*/

#include<stdio.h>
void create(int b[], int l);
void insert(int c[], int m);
void del(int d[], int o);
void disp(int e[], int p);
int a[50], n;
void main()
{
	int i, ch, pos;
	do{	
		printf("\n------------------------------------------------------------------------");
		printf("\n\t\t\t\tMENU\n");
		printf("------------------------------------------------------------------------\n");
		printf("1. Create\t2. Insert\t3. Delete\t4.Display\t0. EXIT\n");
		printf("------------------------------------------------------------------------\n");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter The Limit\n");
				scanf("%d", &n);
				if(n==0)
				{
					printf("Please Enter a valid Limit !");
					break;
				}
				create(a,n);
				disp(a,n);
				break;
			case 2:
				if (n==0)
				{
					noelm :
						printf("Create the Arrey first, No elements in the arrey! \n");
						break;
				}
				else
				{
					printf("Enter the position to insert\n");
					scanf("%d", &pos);
					insert(a,pos);
					disp(a,n);
					break;
				}
			case 3:
				if (n==0)
				{
					goto noelm;
				}
				else
				{
					printf("Enter the position to delete\n");
					scanf("%d", &pos);
					del(a,pos);
					disp(a,n);
					break;
				}
			case 4:
				 
					disp(a,n);
					break;
		}
	
	}while(ch!=0);
	printf("Closing Menu...\n");
}

void create(int b[], int l)
{
	int i;
	printf("Enter the %d Elements\n", n);
	for(i=0; i<l; i++)
	{
		scanf("%d", &b[i]);
	}
	printf("Created an arrey having %d element(s)...\n", n);
}

void insert(int c[], int m)
{
	int i, elm;
	for(i=n-1; i>=m; i--)
	{
		c[i+1]=c[i];
		
	}
	printf("Enter The element to insert\n");
	scanf("%d", &elm);
	c[m]=elm;
	n++;
	printf("%d is Inserted...\n", elm);
}

void del(int d[], int o)
{

	int i,x;
	x=d[o];
	for(i=o; i<n-1; i++)
	{
		d[i]=d[i+1];
		
	}
	n--;
	printf("%d is Deleted...\n", x);
}

void disp(int e[], int p)
{
	int i;
	if (n==0)
	{
		printf("No Element(s) stored in the Arrey\n");
	}
	else
	{
		printf("Elements stored are\n");
		for(i=0;i<p;i++)
		{
			printf("%d\t",e[i]);
		}
	}
}


/*
Author: Debjyoti Guha
Date: 09/08/2017
Description: This will add int stored in an arrey by user.
*/

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int sum=0, i, a[10];
	printf("Enter 10 nos0\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	if (a[i]==10)
	{
	printf("entered values are \n");
	for(i=0;i<10;i++)
	{
		printf("%d\n", a[i]);
	}

	for(i=0;i<10;i++)
	{
		sum=sum+a[i];
	}
		printf("sum=%d\n",sum);
	}
	else
		exit(0);
}

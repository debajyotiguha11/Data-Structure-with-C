/*
Author: Debjyoti Guha
Date: 29/08/2017
Updates: Minor Fixes and code Simplicity . 
Description: This will find and replace a sting given by user, using a pattern matching algorithm.
*/

#include<stdio.h>
#include<string.h>

void main()
{
	char a[50], b[50], c[50], *start, *tmp, *cmp;
	int found=0;
	printf("Enter A String: ");
	gets(a);
	printf("Enter Pattern: ");
	gets(b);
	printf("Enter String to be replaced: ");
	gets(c);
	start=a;
	for( ; start<(start+strlen(a)-strlen(b)); start++)
	{
		cmp=start;
		tmp=b;
		while((*cmp==*tmp) && (*tmp!='\0'))
		{
			cmp++;
			tmp++;
		}
		if(*tmp=='\0')
		{
			found=1;
			break;
		}
	}
	if(found)
	{
		tmp=c;
		while(*tmp!='\0')
		{
			*start=*tmp;
			start++;
			tmp++;
		}
		printf("String after replacement:%s\n", a);
	}
	else
		printf("Pattern not found!\n");

}





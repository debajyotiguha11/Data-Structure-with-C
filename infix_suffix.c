/*
Author: Debjyoti Guha
Date: 16/09/2017
Updates:
Description: This script will convert the given Infix expression to postfix expression.
*/

#include<stdio.h>
#include<string.h>

void convert_fun();
int precedence(char );
void push(char );
char pop();
char infix[50], suffix[50], stack[25];
int top = -1;
void main()
{
	printf("Enter Infix Extression: ");
	scanf("%s",infix);
	convert_fun();
	printf("Infix: %s \t Suffix: %s\n",infix,suffix);
}
void convert_fun()
{
	int i=0, j=0;
	char c, tmp;
	push('#');
	while(i<strlen(infix))
	{
		c = infix[i++];
		switch(c)
		{
			case '(' :
				push(c);
				break;
			case ')' :
				tmp=pop();
				while(tmp!='(')
				{
					suffix[j++]=tmp;
					tmp=pop();
				}
				break;
			case '+' :
			case '-' :
			case '*' :
			case '/' :
			case '^' :
				while(precedence(stack[top])>=precedence(c))
				{
					tmp=pop();
					suffix[j++]=tmp;
				}
				push(c);
				break;
			default :
				suffix[j++]=c;
				break;
		}
	}
	while(top>0)
	{
		tmp=pop();
		suffix[j++]=tmp;
	}
}
void push(char c)
{
	stack[++top]=c;
}
char pop()
{
	return(stack[top--]);
}
int precedence(char c)
{
	switch (c)
	{
		case '^' :
			return (3);
		case '*' :
		case '/' :
			return (2);
		case '+' :
		case '-' :
			return (1);
		case '(' :
		case ')' :
			return (0);
		case '#' :
			return (-1);
	}
	return (0);
}

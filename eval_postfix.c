/*
Author: Debjyoti Guha
Date: 16/09/2017
Updates:
Description: This script is to evaluate a given postfix expression.
*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

float stack[25];
int top=-1;
void push(float);
float pop();
float evaluate(char [],float []);

void main()
{
	char sufix[50];
	float data[15], result;
	int i=0;
	printf("Enter a suffix expression:");
	scanf("%s", sufix);
	while (sufix[i]!='\0')
	{
		if (isalpha(sufix[i]))
		{
			fflush(stdin);
			printf("Enter the value of %c: ", sufix[i]);
			scanf("%f", &data[i]);
		}
		i++;
	}
	result=evaluate(sufix,data);
	printf("Result of %s = %f\n", sufix,result);
}

float evaluate(char s[], float d[])
{
	int i=0;
	float op1, op2;
	char c;
	while(s[i]!='\0')
	{
		c=s[i];
		if(isalpha(s[i]))
			push(d[i]);
		else
		{
			op2= pop();
			op1= pop();
			switch (c)
			{
				case '+' : push (op1+op2); break;
				case '-' : push (op1-op2); break;
				case '*' : push (op1*op2); break;
				case '/' : push (op1/op2); break;
				case '^' : push (pow(op1,op2)); break;
			}
		}
			i++;
	}
	return (pop());
}

void push (float d)
{
	stack[++top]=d;
}

float pop ()
{
	return (stack[top--]);
}

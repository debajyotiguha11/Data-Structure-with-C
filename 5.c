#include<stdio.h>
#include<math.h>
#include<ctype.h>
void push(int);
int pop();
int eval(char[],int[]);
int stack[20], data[20],result,i,c,t=-1,op1,op2;
char suffix[20];

void main()
{
	printf("Enter the SUFFIX expression: ");
	gets(suffix);
	while(suffix[i]!='\0')
	{
		if(isalpha(suffix[i]))
		{
			printf("Enter value of %c: ",suffix[i]);
			scanf("%d",&data[i]);
		}
		i++;
	}
result=eval(suffix,data);
printf("The result of %s is %d\n",suffix,result);
}

int eval(char suffix[], int d[])
{
	int i=0;
	while(suffix[i]!='\0')
	{
		c=suffix[i];
		if(isalpha(suffix[i]))
			push(d[i]);
		else{
			op2=pop();
			op1=pop();
			switch(c)
			{
				case '+':
					push(op1+op2);
					break;
				case '-':
					push(op1-op2);
					break;
				case '*':
					push(op1*op2);
					break;
				case '/':
					push(op1/op2);
					break;
				case '^':
					push(pow(op1,op2));
					break;
			}
		     }
		i++;
	}
	return (pop());
}

void push(int d)
{
	stack[++t]=d;
}

int pop()
{
	return(stack[t--]);
}




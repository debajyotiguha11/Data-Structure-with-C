/*
Author: Debjyoti Guha
Date: 29/08/2017
Updates:
Description: This is a MENU driven function for creating a Stack, insertion elements(PUSH), deleting elements(POP) , display the stack, check if the stack is palindrome or not. Supported by all Over_flow and Under_flow cases.
*/

#include<stdio.h>

//function prototypes
void create();
void push(int item);
void pop();
void display();
void palindrome();

//defining maximum stack size
#define max_size 10

//create STACK
struct stack
{
	int top;
	int ele[max_size];
};
typedef struct stack STACK;
STACK s;

int item;

void main()
{
	s.top = -1;
	int ch;
	do
	{
		printf("\n-----------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t\tMENU\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("1. CREATE\t 2. PUSH\t 3. POP\t 4. Display\t 5. Check Palindrome\t 0.EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				create();
				break;
			case 2:
				printf("Enter element to push: ");
				scanf("%d", &item);
				push(item);
				break;
			case 3:
				pop();
				break;
			case 4:
				display();
				break;
			case 5:
				palindrome();
				break;
		}
	} while(ch!=0);
	printf("Closing MENU!\n");
}

//function to create STACK
void create()
{
	printf("Enter the element to be inserted: ");
	scanf("%d", &item);
	s.top=s.top+1;
	s.ele[s.top]=item;
	printf("Created a STACK\n");

}

//function to PUSH items to STACK
void push(int item)
{

	    if (s.top == (max_size-1))
		{	
	      	   printf ("Stack is Full\n"); //over_flow
		}
	       	   else
		 {
	      	      s.top = s.top + 1;
		      s.ele[s.top] = item;
		      printf("Pushed %d\n", item);
		 }
}

//function to POP items from STACK
void pop()
{
	if(s.top == -1) //under_flow
	{
		printf("Stack is Empty!\n");
	}
	else
	{
		printf("popped item is: %d", s.ele[s.top]);
		s.top = s.top-1;
	}
	
}

//function to DISPLAY STACK elements
void display()
{
	int i;
	if(s.top == -1) //under_flow
	{
		printf("stack is empty!\n");
	}
	else
	{
		printf("The status of the stack is\n");
		for(i=s.top;i>=0;i--)
		{
			printf("%d\n", s.ele[i]);
		}
	}
}

//function to check if the STACK is PALINDROME or not
void palindrome()
{
	int i=0, j=s.top;
	if(s.top == -1)
	{
		printf("Push some elements into the stack first\n");
	}
	else
	{
		for(;j>=((s.top)/2);i++,j--)
		{
			if (s.ele[i]==s.ele[j])
			{
				printf("PALINDROME\n");
				break;
			}	
			else
			{
				printf("NOT A PALINDROME!\n");
				break;
			}
		}
	}
}


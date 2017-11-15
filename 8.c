#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void delend();
void delfront();
void inend(int id,char name[],char dept[],char designation[],int salary,int ph);
void infront(int id,char name[],char dept[],char designation[],int salary,int ph);
void create(int n);
void display();

struct emp_node
{
	struct emp_node *prev;
	int id,salary,ph;
	char name[20], dept[10], designation[10];
	struct emp_node *next;
};
typedef struct emp_node node;
node *first=NULL, *last=NULL;

void main()
{
	int i,n,ch,id,salary,ph;
	char name[20], dept[10], designation[10];
	while(1){
	printf("\n--------------------------DLL MENU-----------------------\n");
	printf("1.Create\t2.Display\t3.Insert Front\t4.Delete Front\t5.Insert End\t6.Delete End\t7.Exit\n\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter No of element: ");
			scanf("%d",&n);
			printf("Enter ID, Name, Department, Designation, Salary, Ph.No.\n");
			scanf("%d %s %s %s %d %d",&id,name,dept,designation,&salary,&ph);
			first=(node*)malloc(sizeof(node));
	first->id=id;
	first->salary=salary;
	first->ph=ph;
	strcpy(first->name,name);
	strcpy(first->dept,dept);
	strcpy(first->designation,designation);
	first->prev=NULL;
	first->next=NULL;
	last=first;
			create(n);
			
			break;
		case 2:
			if(first==NULL)
				printf("No Elements!...");
			else
				display();
			break;
		case 3:
			printf("Enter ID, Name, Department, Designation, Salary, Ph.No.\n");
				scanf("%d %s %s %s %d %d",&id,name,dept,designation,&salary,&ph);
				infront(id,name,dept,designation,salary,ph);
			break;
		case 4:
			if(first==NULL)
				printf("No Elements!...");
			else
				delfront();
			break;
		case 5:
			printf("Enter ID, Name, Department, Designation, Salary, Ph.No.\n");
				scanf("%d %s %s %s %d %d",&id,name,dept,designation,&salary,&ph);
				inend(id,name,dept,designation,salary,ph);
			break;
		case 6:
			if(first==NULL)
				printf("No Elements!...");
			else
				delend();
			break;
		case 7:
			exit(0);
	}
	}
}

void create(int n)
{
int ch,id,salary,ph;
	char name[20], dept[10], designation[10];
	int i;
	node *tmp=(node*)malloc(sizeof(node));
	for(i=1;i<n;i++)
	{
		printf("Enter ID, Name, Department, Designation, Salary, Ph.No.\n");
		scanf("%d %s %s %s %d %d",&id,name,dept,designation,&salary,&ph);
		tmp->id=id;
		tmp->salary=salary;
		tmp->ph=ph;
		strcpy(tmp->name,name);
		strcpy(tmp->dept,dept);
		strcpy(tmp->designation,designation);
		tmp->prev=last;
		last->next=tmp;
		tmp->next=NULL;
		last=tmp;
	}
	
}

void display()
{
	node *tmp=first;
	printf("ID\tNAME\tDEPARTMENT\tDESIGNATION\tSALARY\tPh.No\n");
	while(tmp!=NULL)
	{
		printf("%d\t%s\t%s\t\t%s\t\t%d\t%d\n",tmp->id,tmp->name,tmp->dept,tmp->designation,tmp->salary,tmp->ph);
		tmp=tmp->next;
	}
}

void infront(int id,char name[],char dept[],char designation[],int salary,int ph)
{
	node *tmp=(node*)malloc(sizeof(node));
	tmp->id=id;
	tmp->salary=salary;
	tmp->ph=ph;		
	strcpy(tmp->name,name);
	strcpy(tmp->dept,dept);
	strcpy(tmp->designation,designation);
	if(first==NULL)
	{
		tmp->prev=NULL;
		tmp->next=NULL;
		first=tmp;
		last=first;
	}
	else{
	tmp->prev=NULL;
	tmp->next=first;
	first->prev=tmp;
	first=tmp;}
}

void inend(int id,char name[],char dept[],char designation[],int salary,int ph)
{
	
	node *tmp=(node*)malloc(sizeof(node));
	tmp->id=id;
	tmp->salary=salary;
	tmp->ph=ph;		
	strcpy(tmp->name,name);
	strcpy(tmp->dept,dept);
	strcpy(tmp->designation,designation);
	if(first==NULL)
	{
		tmp->prev=NULL;
		tmp->next=NULL;
		first=tmp;
		last=first;
	}
	else{
	tmp->next=NULL;
	tmp->prev=last;
	last->next=tmp;
	last=tmp;}
}

void delfront()
{
	node *tmp=first, *d=first;
	tmp=first->next;
	tmp->prev=NULL;
first=tmp;
	free(d);
}

void delend()
{
	node *tmp=last, *d=last;
	tmp=last->prev;
	tmp->next=NULL;
last=tmp;
	free(d);
}
	

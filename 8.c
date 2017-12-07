#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void delend();
void delfront();
void inend(int id,char name[],char dept[],char designation[],int salary,int ph);
void infront(int id,char name[],char dept[],char designation[],int salary,int ph);
void create(int id, char name[],char dept[],char designation[],int salary,int ph);
void display();

struct node
{
	struct node *prev;
	int id,salary,ph;
	char name[20], dept[10], designation[10];
	struct node *next;
}*first,*last;

void main()
{
	first=NULL;last=NULL;
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
			for(i=0;i<n;i++)
			{
			printf("Enter ID, Name, Department, Designation, Salary, Ph.No.\n");
			scanf("%d %s %s %s %d %d",&id,name,dept,designation,&salary,&ph);
			create(id,name,dept,designation,salary,ph);
			}
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

void create(int id, char name[],char dept[],char designation[],int salary,int ph)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
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
		last=tmp;
		}
}

void display()
{
	struct node *tmp=first;
	printf("ID\tNAME\tDEPARTMENT\tDESIGNATION\tSALARY\tPh.No\n");
	while(tmp!=NULL)
	{
		printf("%d\t%s\t%s\t\t%s\t\t%d\t%d\n",tmp->id,tmp->name,tmp->dept,tmp->designation,tmp->salary,tmp->ph);
		tmp=tmp->next;
	}
}

void infront(int id,char name[],char dept[],char designation[],int salary,int ph)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
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
	
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
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
	if(first->next==NULL)
	{
		free(first);
		first=NULL;
	}
	else{
		struct node *tmp=first, *d=first;
		tmp=first->next;
		tmp->prev=NULL;
		first=tmp;
		free(d);
	     }
}

void delend()
{
	if(first->next==NULL)
	{
		free(first);
		first=NULL;
	}
	else{
		struct node *tmp=last, *d=last;
		tmp=last->prev;
		tmp->next=NULL;
		last=tmp;
		free(d);
	    }
}
	

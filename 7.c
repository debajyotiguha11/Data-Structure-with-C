#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create(int , char[], char[], int , int );
void inend(int , char [], char[], int , int );
void infront(int , char[], char[], int, int );
void delfront();
void delend();
void display();
struct node
{
	int usn,sem,ph;
	char name[20],branch[10];
	struct node *next;
}*start;


void main()
{
	int i,ch,n,usn,sem,ph;
	char name[20],branch[10];
	start=NULL;
	while(1)
	{
		printf("\n\n------------------------------------MENU-------------------------------------------\n");
		printf("1.Create\t2.Insert Front\t3.Delete Front\t4.Insert End\t5.Delete End\t6.Display\t7.Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("No of element: ");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("Enter usn, name, branch, sem, ph.no\n");
					scanf("%d %s %s %d %d",&usn,name,branch,&sem,&ph);
					create(usn,name,branch,sem,ph);
				}
				break;
			case 2:
				printf("Enter usn, name, branch, sem, ph.no\n");
					scanf("%d %s %s %d %d",&usn,name,branch,&sem,&ph);
				infront(usn,name,branch,sem,ph);
				break;
			case 3:
                                if(start==NULL)
					printf("No elements found...");
				else
				delfront();
				break;
			case 4:
				printf("Enter usn, name, branch, sem, ph.no\n");
					scanf("%d %s %s %d %d",&usn,name,branch,&sem,&ph);
				inend(usn,name,branch,sem,ph);
				break;
			case 5:
				if(start==NULL)
					printf("No elements found...");
				else
					delend();
				break;
			case 6:
				if(start==NULL)
					printf("No elements found...");
				else
				display();
				break;
			case 7:
				exit(0);
		}
	}
}

void create(int us, char na[], char br[], int sem, int ph)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->usn=us;
	strcpy(tmp->name,na);
	strcpy(tmp->branch,br);
	tmp->sem=sem;
	tmp->ph=ph;
	tmp->next=NULL;

	if(start==NULL)
		start=tmp;
	else
	{
		tmp->next=start;
		start=tmp;
	}
}

void infront(int us, char na[], char br[], int sem, int ph)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->usn=us;
	strcpy(tmp->name,na);
	strcpy(tmp->branch,br);
	tmp->sem=sem;
	tmp->ph=ph;
	tmp->next=NULL;
	if(start==NULL)
		start=tmp;
	else
	{
		tmp->next=start;
		start=tmp;
	}
}


void inend(int us, char na[], char br[], int sem, int ph)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	struct node *t=start;
	tmp->usn=us;
	strcpy(tmp->name,na);
	strcpy(tmp->branch,br);
	tmp->sem=sem;
	tmp->ph=ph;
	tmp->next=NULL;
	if(start==NULL)
		start=tmp;
	else
	{
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=tmp;
	}
}

void delfront()
{
	struct node *tmp=start;
	if(start->next==NULL)
	{
		free(start);
		start=NULL;
	}
	else
	{
		start=start->next;
		free(tmp);
	}
	printf("Element Deleted!...");
}

void delend()
{
	struct node *tmp=start, *d=start;
	if(start->next==NULL)
	{
		free(start);
		start=NULL;
	}
	else
	{
		while(tmp->next!=NULL)
		{
			d=tmp;
			tmp=tmp->next;
		}
		free(d->next);
		d->next=NULL;
	}
	printf("Element Deleted!...");
}

void display()
{
	struct node *tmp=start;
	printf("USN\tNAME\tBRANCH\tSEM\tPh.No\n");
	while(tmp!=NULL)
	{
		
		printf("%d\t%s\t%s\t%d\t%d\n",tmp->usn,tmp->name,tmp->branch,tmp->sem,tmp->ph);
		tmp=tmp->next;
	}
}




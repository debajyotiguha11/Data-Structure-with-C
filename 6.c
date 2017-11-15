#include<stdio.h>
#include<stdlib.h>
#define size 5
int cq[size],f=-1,r=-1,elm;
void display();
int full();
int empty();
void insert(int);
int delete();

void main()
{
	int ch;
	while(1){
	printf("\n############### C-Q MENU #############\n");
	printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
	printf("Enter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter the element to insert: ");
			scanf("%d",&elm);
			insert(elm);
			break;
		case 2:
			elm=delete();
			if(elm!=-1)
				printf("Deleted %d",elm);
			break;
		case 3:
			if(empty())
				printf("No Elements!...");
			else
				display();
			break;
		case 4:
			exit(0);
	}
	}
}

void insert(int elm)
{
	if(full())
		printf("CQ Overflow!...\n");
	else{
	if(f==-1)
		f=0;

	r=(r+1)%size;
	cq[r]=elm;
	   }
}

int delete()
{
	int elm;
	if(empty()){
		printf("CQ Underflow!...");
		return -1;}
	else{
	elm=cq[f];
	if(f==r){
		f=-1;
		r=-1;
	}
	else
	{
		f=(f+1)%size;
	}
	return(elm);
	}
}

int full()
{
	if((f==r+1) || (f==0 && r==size-1))
		return 1;
	return 0;
}

int empty()
{
	if(f==-1)
		return 1;
	return 0;
}

void display()
{
	int i;
	for(i=f;i!=r;i=(i+1)%size)
		printf("%d\t",cq[i]);
	printf("%d\n",cq[i]);
}

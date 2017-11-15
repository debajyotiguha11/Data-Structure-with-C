#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node *add(struct node *a,struct node *b);
void printpoly(struct node *head);
int evaluate(struct node *head,int x,int y,int z);

struct node
{
	int coeff,xpow,ypow,zpow;
	struct node *next;
};
struct node *readpoly()
{
	int i,n;
	printf("Number of elements: ");
	scanf("%d",&n);
	struct node *head=NULL;
	for(i=0;i<n;i++)
	{	struct node *tmp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the coef,xpow,ypow,zpow\n");
		scanf("%d%d%d%d",&tmp->coeff,&tmp->xpow,&tmp->ypow,&tmp->zpow);
		tmp->next=head;
		head=tmp;
	}
	return head;
}
void printpoly(struct node *head)
{
	if(head==NULL)
	printf("empty");
	else
	{
	while(head!=NULL)
	{
		if(head->coeff!=0)
		{
			if(head->coeff>0)
				printf(" +");
			printf("%d",head->coeff);
			if(head->xpow!=0)
				printf("x%d",head->xpow);
			if(head->ypow!=0)
				printf("y%d",head->ypow);
	
			if(head->zpow!=0)
				printf("z%d",head->zpow);
		}
	head=head->next;
	}
	}
	printf("\n");
}
int evaluate(struct node *head,int x,int y,int z)
{
	int sum=0;
	while(head)
	{
		if(head->coeff!=0)
		{
			int termsum=1;
			termsum *=pow(x,head->xpow);
			termsum *=pow(y,head->ypow);
			termsum *=pow(z,head->zpow);
			termsum *=head->coeff;
			sum +=termsum;
		}
		head=head->next;
	}
	return sum;
}
struct node *add(struct node *a,struct node *b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	struct node *sum=NULL;
	struct node *tmpa=a;
	while(a)
	{
	struct node *newterm=(struct node*)malloc(sizeof(struct node));
	newterm->coeff=a->coeff;
	newterm->xpow=a->xpow;
	newterm->ypow=a->ypow;
	newterm->zpow=a->zpow;
	newterm->next=sum;
	sum=newterm;
	struct node *tmpb=b;
	while(tmpb)
	{
		if((a->xpow==tmpb->xpow)&&(a->ypow==tmpb->ypow)&&(a->zpow==tmpb->zpow))
		{
			sum->coeff +=tmpb->coeff;
		}
		tmpb=tmpb->next;
	}
	a=a->next;
	}

	a=tmpa;
	while(b)
	{
		int found=0;
		struct node *tmpa=a;
		while(tmpa)
		{
			if((b->xpow==tmpa->xpow)&&(b->ypow==tmpa->ypow)&&(b->zpow==tmpa->zpow))
			{
				found=1;
				break;
			}
			tmpa=tmpa->next;
		}
	if(found==0)
	{
	struct node *newterm=(struct node*)malloc(sizeof(struct node));
	newterm->coeff=b->coeff;
	newterm->xpow=b->xpow;
	newterm->ypow=b->ypow;
	newterm->zpow=b->zpow;
	newterm->next=sum;
	sum=newterm;
	}
	b=b->next;
	}
	return sum;
}
void  main()
{
	int x,y,z;
	struct node *a,*b,*sum;
	printf("Enter The polynomial A: ");
		a=readpoly();
	printf("Enter The polynomial B: ");
		b=readpoly();
	sum=add(a,b);
	printf("Polynomial A= ");
	printpoly(a);
	printf("\nPolynomial B= ");
	printpoly(b);
	printf("\n SUM= ");
	printpoly(sum);
	printf("Enter The X,Y,Z value to evaluate: \n");
	scanf("%d %d %d",&x,&y,&z);
	printf("Result=%d\n",evaluate(sum,x,y,z));
}

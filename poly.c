/*
Author: Debjyoti Guha
Date: 08/11/2017
Description:  Polynomial operations using Singly Circular Linked List (Modified*)
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct polyterm 
{
	int coeff;
	int xpow,ypow,zpow;
	struct polyterm  *next;
};

struct polyterm *readpolynomial()
{
  int i,n;
  printf("Number of terms:");
  scanf("%d",&n);
  struct polyterm *head=NULL;
     for( i=0;i<n;i++)
     {
		struct polyterm *ptemp=(struct polyterm*)malloc(sizeof(struct polyterm));
 		printf("Enter the term %d(coeff,xpow,ypow,zpow):",i+1);
		scanf("%d%d%d%d",&ptemp->coeff,&ptemp->xpow,&ptemp->ypow,&ptemp->zpow);
 		ptemp->next=head;
   		head=ptemp;
     }
 return head;
}

void printpolynomial(struct polyterm *head)
{
     printf("polynomial:");
        if(NULL==head)
      printf("empty");
   else
    {
         while(NULL!=head)
        {
            if(head->coeff!=0)
            {
                 if(head->coeff>0)
                 	printf("+");
             	 printf("%d",head->coeff);
                 if(head->xpow!=0)
                 {
                    printf("x %d",head->xpow);
                 }
                  if(head->ypow!=0)
                 {
                       printf("y %d",head->ypow);
                 }
                 if(head->zpow!=0)
                 {
                    printf("z %d",head->zpow);
             	 }
   	    }
	    head=head->next;
    	}
    }
printf("\n");
}

int evaluate(struct polyterm *head,int x,int y,int z)
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

struct polyterm *add(struct polyterm *a,struct polyterm *b)
{
     if(a==NULL)
        return b;
     if(b==NULL)
	return a;
     struct  polyterm *sum=NULL;
     struct polyterm *tempa=a;
         while(a)
        {
		struct polyterm *newterm=(struct polyterm*)malloc(sizeof(struct polyterm));
    		newterm->coeff=a->coeff;
     		newterm->xpow=a->xpow;
     		newterm->ypow=a->ypow;
    		newterm->zpow=a->zpow;
      		newterm->next=sum;
       		sum=newterm;
              	struct polyterm *tempb=b;
        	while(tempb)
       		{
          		if((a->xpow==tempb->xpow)&&(a->ypow==tempb->ypow)&&(a->zpow==tempb->zpow))
        		{
            			sum->coeff +=tempb->coeff;
       			}
    			tempb=tempb->next;
 		}
		a=a->next;
	}

	a=tempa;
   	while(b) 
  	{
      		int found=0;
     		struct polyterm *tempa=a;
       		while(tempa)
      		{
           		if((b->xpow==tempa->xpow)&&(b->ypow==tempa->ypow)&&(b->zpow==tempa->zpow))
     			{
        			found=1;
          			break;
     			}
   			tempa=tempa->next;
  		}
 		if(found==0)
 		{
     			struct polyterm *newterm=(struct polyterm*)malloc(sizeof(struct polyterm));
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


int main()
{
	struct polyterm *a,*b,*sum;
    	a=readpolynomial();
   	b=readpolynomial();
    	sum=add(a,b);
      	printpolynomial(a);
    	printpolynomial(b);
   	printpolynomial(sum);
    	printf("value:%d\n",evaluate(sum,2,2,2));
 return 0;
}


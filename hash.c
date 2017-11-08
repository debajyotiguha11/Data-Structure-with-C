
/*
Author: Debjyoti Guha
Date: 08/11/2017
Description:  Hasing Operations (Modified*)
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int tableSize=0,totEle=0;
struct node *hashTable=NULL;
struct node
  {int salary,key;
  char name[100];
  int marker;
  };
void insertInHash(int key,char *name,int age)
{
	int hashIndex=key%tableSize;
      	if(tableSize==totEle)
        {
              printf("\n\nCan't perform insertion. Hash table is full.\n\n");
                          return;
        }
	while(hashTable[hashIndex].marker==1)
 	{
		hashIndex=(hashIndex+1)%tableSize;
     	}
	hashTable[hashIndex].key=key;
	hashTable[hashIndex].salary=age;
	strcpy(hashTable[hashIndex].name,name);
	hashTable[hashIndex].marker=1;
	totEle++;
return;
}

void deleteFromHash(int key)
{
	int hashIndex=key%tableSize,flag=0;
	if(totEle==0)
 	{
 		printf("\nHash table is empty.\n");
		return;
	}
	while(hashTable[hashIndex].marker!=0)
	{
		if(hashTable[hashIndex].key==key)
       		{
        		hashTable[hashIndex].key==0;
        		/* set marker to 0 during deletion operation*/
        		hashTable[hashIndex].marker=0;
        		hashTable[hashIndex].salary=0;
        		strcpy(hashTable[hashIndex].name,"\0");
        		totEle--;
        		flag=1;
        		break;
        	}
		hashIndex=(hashIndex+1)%tableSize;

	}
	if(flag)
      		printf("\nGiven data deleted from the hash table\n");
	else
      		printf("\nGiven data is not available in the hash table\n");
      return;
}

void searchElement(int key)
{
	int hashIndex=key%tableSize,flag=0;
	if(totEle==0)
	{
		printf("\nHash table is empty.");
		return;
	}
	while(hashTable[hashIndex].marker!=0)
       {
	       if(hashTable[hashIndex].key==key)
               {
            		printf("\nEmployee ID:%d\n",hashTable[hashIndex].key);
            		printf("\nName:%s\n",hashTable[hashIndex].name);
            		printf("Salary:%d\n",hashTable[hashIndex].salary);
            		flag=1;
            		break;
            	}
       
       hashIndex=(hashIndex+1)%tableSize;
       }
	if(!flag)
            printf("\nGiven data is not present in the hash table\n");
            return;
}

void display()
{
	int i;
        if(totEle==0)
        {
        	printf("\nHash table is empty\n");
                return;
        }
	printf("\nEmployee ID     Name            Salary          Index\n");
	printf("-----------------------------------------------------------------\n");
	for(i=0;i<tableSize;i++)
	{	
		if(hashTable[i].marker==1)
              	{
              		printf("%d\t\t",hashTable[i].key);
              		printf("%s\t\t",hashTable[i].name);
              		printf("%d\t\t",hashTable[i].salary);
              		printf("%d\n",i+1);
              	}
      	}
     	printf("\n");
      	return;
}


int checkduplicate(int key)
{
	int hashIndex=key%tableSize,flag=0;
	while(hashTable[hashIndex].marker!=0)
	{
 		if(hashTable[hashIndex].key==key)
      		{
      			flag=1;
      			return 1;
      		}

		hashIndex=(hashIndex+1)%tableSize;
	}
	if(!flag)
	       return 0;
}




int main()
{
	int key,salary,ch;
	char name[100];
	printf("\nEnter the number of elements:\n");
	scanf("%d",&tableSize);
	hashTable=(struct node*)calloc(tableSize,sizeof(struct node));
	while (1)
    	{
     		printf("\n1.Insertion\t2.Deletion\n");
     		printf("\n3.Searching\t4.Display\n");
     		printf("\n5.Exit\t\nEnter your choice:\n");

     		scanf("%d",&ch);
     		switch(ch)
      		{
			case 1:
            			printf("\nEnter the key value between 0 and 9999:\n");
            			scanf("%d",&key);
            			if(key>9999)
                    		{
					printf("\nKey value should be <10000\n");
                    			break;
                    		}
            			if(checkduplicate(key))
                    		{
					printf("\nKey value already exists\n");
                    			break;
                    		}
            			else
                   		{
                   			printf("\nName:\n");
                   			scanf("%s",name);
                   			printf("\nSalary:\n");
                   			scanf("%d",&salary);
                   			insertInHash(key,name,salary);
                   			break;
                   		}
       			case 2:
            			printf("\nEnter the key value:\n");
            			scanf("%d",&key);
            			deleteFromHash(key);
            			break;
       			case 3:
            			printf("\nEnter the key value:\n");
            			scanf("%d",&key);
            			searchElement(key);
            			break;
       			case 4:
            			display();
            			break;
       			case 5:
            			exit(0);
            		default:
            			printf("\nYou have entered the wrong option.\n");
            			break;
            	}
      }
return 0;
}



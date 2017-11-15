#include<stdio.h>
#include<stdlib.h>
struct node* min(struct node *root);
struct node* del(struct node *root, int key);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
struct node* create(struct node *root,int data);
struct node* search(struct node *root, int key);

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root;

void main()
{
	root=NULL;
	struct node *tmp;
	int i,ch,n,key,data,elm;
	while(1){
	printf("\n--------------BST MENU--------------\n");
	printf("1.CREATE\t2.TRAVERSALS\t3.SEARCH\t4.DELETE\t5.EXIT\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter No of elements: ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				printf("DATA%d=",i+1);
				scanf("%d",&data);
				root=create(root,data);
			}
			break;
		case 2:
			if(root==NULL)
				printf("Empty List!...");
			else{
			printf("INORDER:  ");
			inorder(root);
			printf("\nPREORDER: ");
			preorder(root);
			printf("\nPOSTORDER:");
			postorder(root);}
			break;
		case 3:
			printf("Enter the element to search: ");
			scanf("%d",&key);
			tmp=search(root,key);
			if(tmp)
				printf("Element found!...");
			else
				printf("Not Found!...");
			break;
		case 4:
			printf("Emter the element to delete: ");
			scanf("%d",&key);
			tmp=del(root,key);
			if(tmp)
				printf("Deleted %d",tmp->data);
			else
				printf("Element not found!...");
			break;
		case 5:
			exit(0);
	}
	}
}

struct node* create(struct node *r,int data)
{
	if(r==NULL)
	{
		r=(struct node*)malloc(sizeof(struct node));
		r->data=data;
		r->left=NULL;
		r->right=NULL;
	}
	else if(data<r->data){
		r->left=create(r->left,data);}
	else{
		r->right=create(r->right,data);}
	return r;
}

struct node* search(struct node *root, int key)
{
	if(root==NULL)
		return NULL;
	if(key<root->data){
		search(root->left,key);}
	else if(key>root->data){
		search(root->right,key);}
	else if(key==root->data)
		return root;
}

void inorder(struct node *root)
{
	if(root!=NULL){
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);}
}

void preorder(struct node *root)
{
	if(root!=NULL){
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);}
}

void postorder(struct node *root)
{
	if(root!=NULL){
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);}
}

struct node* del(struct node *root, int key)
{
	if(root==NULL)
		return NULL;
	if(key<root->data)
		root->left=del(root->left,key);
	else if(key>root->data)
		root->right=del(root->right,key);
	else{
		if(root->left==NULL)
		{
			struct node *tmp=root->right;
			return tmp;
		}
		else if(root->right==NULL)
		{
			struct node *tmp=root->left;
			return tmp;
		}
		struct node *tmp=min(root->right);
		root->data=tmp->data;
		root->right=del(root->right,tmp->data);
	   }
	return root;
}

struct node* min(struct node *root)
{
	struct node *tmp=root;
	while(tmp->left!=NULL)
		tmp=tmp->left;
	return tmp;
}

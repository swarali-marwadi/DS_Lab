/*
 * expressionTree.c
 *
 *  Created on: 11-Oct-2025
 *      Author: sharyu
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree
{
	char ch;
	struct tree *left;
	struct tree *right;
};

struct node
{
	struct tree *add;
	struct node *next;
};

int menu()
{
	int ch=0;
	do
	{
	printf("\n\n---Choose Traversal Type---");
	printf("\n1.Inorder");
	printf("\n2.Preorder");
	printf("\n3.Postorder");
	printf("\n0.Exit");
	printf("\nEnter your choice :");
	scanf("%d",&ch);
	if(ch<0||ch>3)
	{
		printf("\n!!Enter valid choice!!");
	}
	}while(ch<0||ch>3);
	return ch;
}

void push(struct node **ftop, struct tree **fdata)
{
	struct node *top = NULL;
	struct node *newnode = NULL;

	top=*ftop;

	newnode = (struct node *)calloc(1,sizeof(struct node));

	if(newnode==NULL)
	{
		printf("\n\tMemory allocation failed");
	}
	else
	{
		newnode->add=*fdata;
		newnode->next=NULL;

		if(top==NULL)
		{
			top=newnode;
		}
		else
		{
			newnode->next=top;
			top=newnode;
		}
	}

	*ftop=top;
}

void pop(struct node **ftop, struct tree **fddata)
{
	struct node *top = NULL;
	struct node *track = NULL;

	top=*ftop;

	if(top==NULL)
	{
		printf("\n\tStack is empty");
	}
	else
	{
		*fddata=top->add;
		track=top;
		top=top->next;
		free(track);
	}

	*ftop=top;
}

void create(struct tree **froot, char *fpostfix)
{
	struct tree *root=NULL;
	struct tree *newnode=NULL;
	struct tree *opnd1=NULL;
	struct tree *opnd2=NULL;
	struct node *top=NULL;
	char postfix[100];
	int i=0;

	strcpy(postfix,fpostfix);

	root=*froot;

	printf("\nPostfix : ");
	for(i=0;postfix[i]!='\0';i++)
	{
		printf(" %c",postfix[i]);
	}

	for(i=0;postfix[i]!='\0';i++)
	{
		newnode=(struct tree *)calloc(1,sizeof(struct tree));

		newnode->ch=postfix[i];
		newnode->left=NULL;
		newnode->right=NULL;

		if((postfix[i]>='a' && postfix[i]<='z')||(postfix[i]>='A' && postfix[i]<='Z'))
		{
			push(&top,&newnode);
		}
		else
		{
			pop(&top,&opnd1);
			pop(&top,&opnd2);
			newnode->right=opnd1;
			newnode->left=opnd2;
			push(&top,&newnode);
		}

	}

	pop(&top,&root);

	*froot=root;
}

void inorderTraversal(struct tree **froot)
{
	struct tree *root=NULL;
	root=*froot;

	if(root==NULL)
		return;
	inorderTraversal(&root->left);
	printf("%c ",root->ch);
	inorderTraversal(&root->right);
}

void preorderTraversal(struct tree **froot)
{
	struct tree *root=NULL;
	root=*froot;

	if(root==NULL)
		return;
	printf("%c ",root->ch);
	preorderTraversal(&root->left);
	preorderTraversal(&root->right);
}

void postorderTraversal(struct tree **froot)
{
	struct tree *root=NULL;
	root=*froot;

	if(root==NULL)
		return;
	postorderTraversal(&root->left);
	postorderTraversal(&root->right);
	printf("%c ",root->ch);
}

int main(void)
{
	struct tree *root=NULL;
	char postfix[100];
	int ch,cnt=1;

	printf("\nEnter a String : ");
	scanf(" %[^\n]%*c",postfix);

	create(&root,postfix);

	do
	{
		ch=menu();
		switch(ch)
		{
		case 1:
			printf("\nInorder :");
			inorderTraversal(&root);
			break;

		case 2:
			printf("\nPreorder :");
			preorderTraversal(&root);
			break;

		case 3:
			printf("\nPostorder :");
			postorderTraversal(&root);
			break;

		case 0:
			cnt=0;
			printf("\nThank You");
			break;
		}
	}while(cnt==1);

	return 0;

}


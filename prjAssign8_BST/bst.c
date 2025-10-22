/*
 * bst.c
 *
 *  Created on: 15-Oct-2025
 *      Author: sharyu
 */

#include<stdio.h>
#include<stdlib.h>

struct bst
{
	int data;
	int freq;
	struct bst *left;
	struct bst *right;
};

struct stack
{
	struct bst *add;
	struct stack *next;
};

void push(struct stack **ftop, struct bst **fdata)
{
	struct stack *top = NULL;
	struct stack *newnode = NULL;

	top=*ftop;

	newnode = (struct stack *)calloc(1,sizeof(struct stack));

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

void pop(struct stack **ftop, struct bst **fddata)
{
	struct stack *top = NULL;
	struct stack *track = NULL;

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

int menu()
{
	int ch=0;

	do
	{
	printf("\n\n---BST Operations---");
	printf("\n1.Insert");
	printf("\n2.Delete");
	printf("\n3.Search");
	printf("\n4.Inorder");
	printf("\n5.Postorder");
	printf("\n6.Preorder");
	printf("\n0.Exit");
	printf("\nEnter your choice :");
	scanf("%d",&ch);
	if(ch<0||ch>6)
	{
		printf("\n!!Enter valid choice!!");
	}
	}while(ch<0||ch>6);

	return ch;
}

void create(struct bst **froot, struct bst **fnewnode)
{
	struct bst *root=NULL;
	struct bst *newnode=NULL;

	root=*froot;
	newnode=*fnewnode;

	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
		if((newnode->data)<(root->data))
		{
			create(&root->left, &newnode);
		}
		else if((newnode->data)>(root->data))
		{
			create(&root->right, &newnode);
		}
		else
		{
			root->freq++;
			free(newnode);
			newnode=NULL;
		}
	}

	*froot=root;
	*fnewnode=newnode;

}

void insert(struct bst **froot, struct bst **fnewnode)
{
	struct bst *root=NULL;
	struct bst *newnode=NULL;

	root=*froot;
	newnode=*fnewnode;

	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
		if((newnode->data)<(root->data))
		{
			create(&root->left, &newnode);
		}
		else if((newnode->data)>(root->data))
		{
			create(&root->right, &newnode);
		}
		else
		{
			root->freq++;
			free(newnode);
			newnode=NULL;
		}
	}

	*froot=root;
	*fnewnode=newnode;

}

int search(struct bst **froot, struct bst **fkey)
{
	struct bst *temp=NULL;
	struct bst *key=NULL;
	struct stack *top=NULL;
	int found=1;

	temp=*froot;
	key=*fkey;

	while(temp!=NULL || top!=NULL)
	{
		while(temp!=NULL)
		{
			push(&top,&temp);
			temp=temp->left;
		}
		pop(&top,&temp);
		if(temp->data==key->data)
		{
			found=0;
		}
		temp=temp->right;
	}
	return found;
}

void delete(struct bst **froot, struct bst **fnewnode)
{
	struct bst *root=NULL;
	struct bst *newnode=NULL;
	struct bst *temp=NULL;
	struct stack *top=NULL;
	int found=0;

	root=*froot;
	newnode=*fnewnode;
	temp=*froot;

	found=search(&root,&newnode);
	if(found==0)
	{
		while(temp!=NULL || top!=NULL)
		{
			while(temp!=NULL)
			{
				push(&top,&temp);
				temp=temp->left;
			}
			pop(&top,&temp);
			if(temp->left==NULL && temp->right==NULL)
			{

			}
			temp=temp->right;
		}
	}
	else
	{
		printf("\nNumber NOT Found");
	}

	*froot=root;
	*fnewnode=newnode;

}

void inorder(struct bst **froot)
{
	struct bst *temp=NULL;
	struct stack *top=NULL;

	temp=*froot;

	while(temp!=NULL || top!=NULL)
	{
		while(temp!=NULL)
		{
			push(&top,&temp);
			temp=temp->left;
		}
		pop(&top,&temp);
		printf("%d ",temp->data);
		temp=temp->right;
	}
}

void preorder(struct bst **froot)
{
	struct bst *temp=NULL;
	struct stack *top=NULL;

	temp=*froot;

	while(temp!=NULL || top!=NULL)
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			push(&top,&temp);
			temp=temp->left;
		}
		pop(&top,&temp);
		temp=temp->right;
	}
}

void postorder(struct bst **froot)
{
	struct bst *temp=NULL;
	struct stack *top=NULL;

	temp=*froot;

	while(temp!=NULL || top!=NULL)
	{
		while(temp!=NULL)
		{
			push(&top,&temp);
			temp=temp->left;
		}
		pop(&top,&temp);
		temp=temp->right;
		printf("%d ",temp->data);
	}
}

int main(void)
{
	struct bst *root=NULL;
	struct bst *newnode=NULL;
	struct bst *key=NULL;
	int ch=0;
	char ans;
	int cnt=1;
	int found=1;

	do
	{
		newnode=(struct bst *)calloc(1,sizeof(struct bst));

		printf("\nEnter no. to add in BST :");
		scanf("%d",&newnode->data);
		newnode->freq=1;
		newnode->left=NULL;
		newnode->right=NULL;

		create(&root, &newnode);

		printf("\nDo you want to add another node? (y/n)");
		scanf(" %c",&ans);

	}while(ans=='y' || ans=='Y');

	do
	{
		ch=menu();
		switch(ch)
		{
		case 1:
			newnode=(struct bst *)calloc(1,sizeof(struct bst));
			printf("\nEnter the number to insert:");
			scanf("%d",&newnode->data);
			newnode->freq=1;
			newnode->left=NULL;
			newnode->right=NULL;
			insert(&root,&newnode);
			break;

		case 2:
			key=(struct bst *)calloc(1,sizeof(struct bst));
			printf("\nEnter Number to Delete :");
			scanf("%d",&key->data);
			newnode->freq=1;
			newnode->left=NULL;
			newnode->right=NULL;

			delete(&);


			free(key);
			break;

		case 3:
			key=(struct bst *)calloc(1,sizeof(struct bst));

			printf("\nEnter Number to Search :");
			scanf("%d",&key->data);
			newnode->freq=1;
			newnode->left=NULL;
			newnode->right=NULL;

			found=search(&root,&key);
			if(found==0)
			{
				printf("\nNumber Found");
			}
			else
			{
				printf("\nNumber NOT Found");
			}
			free(key);
			break;

		case 4:
			printf("\nInorder :");
			inorder(&root);
			break;

		case 5:
			printf("\nPostorder :");
			postorder(&root);
			break;

		case 6:
			printf("\nPreorder :");
			preorder(&root);
			break;

		case 0:
			cnt=0;
			printf("\nThank You");
			break;
		}
	}while(cnt==1);

	return 0;
}


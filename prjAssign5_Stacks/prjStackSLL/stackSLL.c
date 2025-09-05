/*
 * stack.c
 *
 *  Created on: Sep 4, 2025
 *      Author: administrator
 */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int menu();
int push(struct node **ftop, int *fidata);
int pop(struct node **ftop, int *fddata);

int menu()
{
	int ch=0;
	do
	{
		printf("\nEnter operation to perform on stack:");
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n0.Exit");
		scanf("%d",&ch);
		if(ch<0||ch>2)
		{
			printf("Enter valid choice");
		}
	}while(ch<0||ch>2);
	return ch;
}

int push(struct node **ftop, int *fidata)
{
	int fsuccess=0;
	struct node *top = NULL;
	struct node *newnode = NULL;

	top=*ftop;

	newnode = (struct node *)calloc(1,sizeof(struct node));

	if(newnode==NULL)
	{
		printf("\n\tMemory allocation failed");
		fsuccess=1;
	}
	else
	{
		newnode->data=*fidata;
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

	return fsuccess;
}

int pop(struct node **ftop, int *fddata)
{
	int fsuccess=0;

	struct node *top = NULL;
	struct node *track = NULL;

	top=*ftop;

	if(top==NULL)
	{
		printf("\n\tStack is empty");
		fsuccess=1;
	}
	else
	{
		*fddata=top->data;
		track=top;
		top=top->next;
		free(track);
	}

	*ftop=top;

	return fsuccess;
}

int main()
{
	int ch=0;
	int idata=0;
	int ddata=0;
	int conti=0;
	int success=0;
	struct node *top=NULL;

	do
	{
		ch=menu();
		switch(ch)
		{
		case 1:
			printf("\nEnter data to push :");
			scanf("%d",&idata);
			success=push(&top, &idata);
			if(success==0)
			{
				printf("\n\t push successful");
			}
			else
			{
				printf("\n\t push failed");
			}
			break;

		case 2:
			success=pop(&top,&ddata);
			if(success==0)
			{
				printf("\n\t Pop successful");
				printf("\n Pop Data : %d",ddata);
			}
			else
			{
				printf("\n\t Pop failed");
			}
			break;

		case 0:
			conti=1;
			printf("Thank You");
			break;
		}
	}while(conti==0);
	return 0;
}




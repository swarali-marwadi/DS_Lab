/*
 * PostfixEvaluation.c
 *
 *  Created on: 13-Sept-2025
 *      Author: sharyu
 */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int push(struct node **ftop, int *fidata);
int pop(struct node **ftop, int *fddata);

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
	int i=0;
	int val;
	int success=0;
	char postfix[100];
	int ans;
	int opd1;
	int opd2;
	char opr;
	struct node *top=NULL;

	printf("\nEnter a Postfix String");
	scanf("%[^\n]%*c",postfix);

	printf("\nPostfix : ");
	for(i=0;postfix[i]!='\0';i++)
	{
		printf(" %c",postfix[i]);
	}

	for(i=0;postfix[i]!='\0';i++)
	{
		if(postfix[i]>='0' && postfix[i]<='9')
		{
			val=postfix[i]-'0';
			success=push(&top, &val);
			if(success != 0)
			{
				printf("\n\tPush failed");
			}
		}
		else
		{
			opr=postfix[i];

			success = pop(&top, &opd2);
			if (success != 0)
				printf("\n\tPop failed");

			success = pop(&top, &opd1);
			if (success != 0)
				printf("\n\tPop failed");

			switch(opr)
			{
			case '+':
				ans=opd1+opd2;
				break;
			case '-':
				ans=opd1-opd2;
				break;
			case '*':
				ans=opd1*opd2;
				break;
			case '/':
				ans=opd1/opd2;
				break;
			}

			success = push(&top, &ans);
			if (success != 0)
				printf("\n\tPush failed");
		}

	}

	pop(&top, &ans);
	printf("\nAns: %d", ans);

	return 0;
}



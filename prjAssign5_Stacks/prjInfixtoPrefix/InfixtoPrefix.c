/*
 * InfixtoPrefix.c
 *
 *  Created on: 21-Sept-2025
 *      Author: sharyu
 */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int push(struct node **ftop, char *fidata);
int pop(struct node **ftop, char *fddata);

int push(struct node **ftop, char *fidata)
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

int pop(struct node **ftop, char *fddata)
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
	char ddata;
	int success=0;
	char infix[100];
	char postfix[100];
	int j=0;
	struct node *top=NULL;

	printf("\nEnter a String");
	scanf("%[^\n]%*c",infix);

	printf("\nInfix : ");
	for(i=0;infix[i]!='\0';i++)
	{
		printf(" %c",infix[i]);
	}

	for(i=0;infix[i]!='\0';i++)
	{
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='0' && infix[i]<='9'))
		{
			postfix[j]=infix[i];
			j++;
		}
		else if(infix[i]=='(')
		{
			success=push(&top, &infix[i]);
			if(success==0)
			{
				continue;
				//printf("\n\tPush successful");
			}
			else
			{
				printf("\n\tPush failed");
			}
		}
		else if(infix[i]==')')
		{
			do
			{
				success=pop(&top,&ddata);
				if(success==0)
				{
					//printf("\n\tPop successful");
					postfix[j]=ddata;
					j++;
				}
				else
				{
					printf("\n\tPop failed");
				}
				if(top==NULL)
					break;
			}while((top->data!='('));
			success=pop(&top,&ddata);
			if(success==0)
			{
				continue;
				//printf("\n\tPop successful");
			}
			else
			{
				printf("\n\tPop failed");
			}
		}
		else
		{
			if(top==NULL)
			{
				success=push(&top, &infix[i]);
				if(success==0)
				{
					continue;
					//printf("\n\tPush successful");
				}
				else
				{
					printf("\n\tPush failed");
				}
			}
			else
			{
				if((top->data=='+'||top->data=='-') && (infix[i]=='*'||infix[i]=='/'))
				{
					success=push(&top, &infix[i]);
					if(success==0)
					{
						continue;
						//printf("\n\tPush successful");
					}
					else
					{
						printf("\n\tPush failed");
					}
				}

				else if((top->data=='+'||top->data=='-')  && (infix[i]=='+'||infix[i]=='-'))
				{
					do
					{
						success=pop(&top,&ddata);
						if(success==0)
						{
							//printf("\n\tPop successful");
							postfix[j]=ddata;
							j++;
						}
						else
						{
							printf("\n\tPop failed");
						}
						if(top==NULL)
							break;
					}while((top->data=='+'||top->data=='-')  && (infix[i]=='+'||infix[i]=='-'));
					success=push(&top, &infix[i]);
					if(success==0)
					{
						continue;
						//printf("\n\tPush successful");
					}
					else
					{
						printf("\n\tPush failed");
					}

				}

				else if((top->data=='*'||top->data=='/')  && (infix[i]=='*'||infix[i]=='/'))
				{
					do
					{
						success=pop(&top,&ddata);
						if(success==0)
						{
							//printf("\n\tPop successful");
							postfix[j]=ddata;
							j++;
						}
						else
						{
							printf("\n\tPop failed");
						}
						if(top==NULL)
							break;
					}while((top->data=='*'||top->data=='/')  && (infix[i]=='*'||infix[i]=='/'));
					success=push(&top, &infix[i]);
					if(success==0)
					{
						continue;
						//printf("\n\tPush successful");
					}
					else
					{
						printf("\n\tPush failed");
					}
				}

				else if((top->data=='*'||top->data=='/')  && (infix[i]=='*'||infix[i]=='/'))
				{
					do
					{
						success=pop(&top,&ddata);
						if(success==0)
						{
							//printf("\n\tPop successful");
							postfix[j]=ddata;
							j++;
						}
						else
						{
							printf("\n\tPop failed");
						}
						if(top==NULL)
							break;
					}while((top->data=='*'||top->data=='/')  && (infix[i]=='*'||infix[i]=='/'));
					success=push(&top, &infix[i]);
					if(success==0)
					{
						continue;
						//printf("\n\tPush successful");
					}
					else
					{
						printf("\n\tPush failed");
					}
				}
				else if(top->data=='(')
				{
					success=push(&top, &infix[i]);
					if(success==0)
					{
						continue;
						//printf("\n\tPush successful");
					}
					else
					{
						printf("\n\tPush failed");
					}
				}
			}
		}
	}

	while(top!=NULL)
	{
		success=pop(&top,&ddata);
		if(success==0)
		{
			//printf("\n\tPop successful");
			postfix[j]=ddata;
			j++;
		}
		else
		{
			printf("\n\tPop failed");
		}
	}

	printf("\nPostfix : ");
	for(i=0;postfix[i]!='\0';i++)
	{
		printf(" %c",postfix[i]);
	}

	return 0;
}



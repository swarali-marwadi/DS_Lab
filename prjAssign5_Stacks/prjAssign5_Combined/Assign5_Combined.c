/*
 * stack.c
 *
 *  Created on: Sep 4, 2025
 *      Author: administrator
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *next;
};

struct oprnode
{
	char data;
	struct node *next;
};

struct opdnode
{
	char string[20];
	struct node *next;
};

int menu()
{
	int ch=0;
	do
	{
	printf("\n\n----------Stack Menu--------------");
	printf("\nEnter Your Choice :");
	printf("\n1.infix to Postfix");
	printf("\n2.Postfix Evaluation");
	printf("\n3.Infix to Prefix");
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

void push(struct node **ftop, char *fidata)
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
}

void pop(struct node **ftop, char *fddata)
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
		*fddata=top->data;
		track=top;
		top=top->next;
		free(track);
	}

	*ftop=top;
}

void intopost(char *finfix, char *fpostfix)
{
	char infix[100];
	char postfix[100];
	int i=0,j=0;
	char ddata;
	struct node *top=NULL;

	strcpy(infix,finfix);

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
			push(&top, &infix[i]);
		}
		else if(infix[i]==')')
		{
			do
			{
				pop(&top,&ddata);
				postfix[j]=ddata;
				j++;
				if(top==NULL)
				{
					printf("\nError: unbalanced parantheses in expression");
					return;
				}	
			}while(top->data!='(');
			pop(&top,&ddata);
		}
		else
		{
			if(top==NULL)
			{
				push(&top, &infix[i]);
			}
			else
			{
				if((top->data=='+'||top->data=='-') && (infix[i]=='*'||infix[i]=='/'))
				{
					push(&top, &infix[i]);
				}

				else if((top->data=='+'||top->data=='-')  && (infix[i]=='+'||infix[i]=='-'))
				{
					do
					{
						pop(&top,&ddata);
						postfix[j]=ddata;
						j++;
						if(top==NULL)
							break;
					}while((top->data=='+'||top->data=='-')  && (infix[i]=='+'||infix[i]=='-'));
					push(&top, &infix[i]);
				}

				else if((top->data=='*'||top->data=='/')  && (infix[i]=='*'||infix[i]=='/'))
				{
					do
					{
						pop(&top,&ddata);
						postfix[j]=ddata;
						j++;
						if(top==NULL)
							break;
					}while((top->data=='*'||top->data=='/')  && (infix[i]=='*'||infix[i]=='/'));
					push(&top, &infix[i]);
				}

				else if((top->data=='*'||top->data=='/')  && (infix[i]=='+'||infix[i]=='-'))
				{
					do
					{
						pop(&top,&ddata);
						postfix[j]=ddata;
						j++;
						if(top==NULL)
							break;
					}while((top->data=='*'||top->data=='/')  && (infix[i]=='+'||infix[i]=='-'));
					push(&top, &infix[i]);
				}
			}
		}
	}

	while(top!=NULL)
	{
		pop(&top,&ddata);
		postfix[j]=ddata;
		j++;
	}

	strcpy(fpostfix,postfix);
}

void push1(struct node **ftop, int *fidata)
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
}

void pop1(struct node **ftop, int *fddata)
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
		*fddata=top->data;
		track=top;
		top=top->next;
		free(track);
	}

	*ftop=top;
}

void postEval(char *fpostfixEval, int *fans)
{
	int i=0;
	int val;
	char postfix[100];
	int ans;
	int opd1;
	int opd2;
	char opr;
	struct node *top=NULL;

	strcpy(postfix,fpostfixEval);

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
			push1(&top, &val);
		}
		else
		{
			opr=postfix[i];

			pop1(&top, &opd2);
			pop1(&top, &opd1);

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

			push1(&top, &ans);
		}
	}

	pop1(&top, &ans);
	*fans=ans;
}

void push2(struct node **ftop, char *fpushstr)
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
		strcpy(newnode->data,fpushstr);
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

void pop2(struct node **ftop, char *fddata)
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
		*fddata=top->data;
		track=top;
		top=top->next;
		free(track);
	}

	*ftop=top;
}

void intopre(char *finfix, char *fprefix)
{
	char infix[100];
	char prefix[100];
	char pushstr[20];
	int i=0,j=0;
	char ddata;
	char ddata1;
	char ddata2;
	struct node *opdtop=NULL;
	struct node *oprtop=NULL;

	strcpy(infix,finfix);

	printf("\nInfix : ");
	for(i=0;infix[i]!='\0';i++)
	{
		printf(" %c",infix[i]);
	}

	for(i=0;infix[i]!='\0';i++)
	{
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='0' && infix[i]<='9'))
		{
			strcpy(pushstr,infix[i]);
			push(&opdtop,pushstr);
		}
		else if(infix[i]=='(')
		{
			push(&top, &infix[i]);
		}
		else if(infix[i]==')')
		{
			do
			{
				pop(&top,&ddata);
				postfix[j]=ddata;
				j++;
				if(top==NULL)
				{
					printf("\nError: unbalanced parantheses in expression");
					return;
				}
			}while(top->data!='(');
			pop(&top,&ddata);
		}
		else
		{
			if(oprtop==NULL)
			{
				push(&oprtop, &infix[i]);
			}
			else
			{
				if((oprtop->data=='+'||oprtop->data=='-') && (infix[i]=='*'||infix[i]=='/'))
				{
					push(&oprtop, &infix[i]);
				}

				else if((oprtop->data=='+'||oprtop->data=='-')  && (infix[i]=='+'||infix[i]=='-'))
				{
					do
					{
						pop(&oprtop,&ddata);
						pop(&opdtop,&ddata2);
						pop(&opdtop,&ddata1);

						if(oprtop==NULL)
							break;
					}while((oprtop->data=='+'||oprtop->data=='-')  && (infix[i]=='+'||infix[i]=='-'));
					push(&oprtop, &infix[i]);
				}

				else if((oprtop->data=='*'||oprtop->data=='/')  && (infix[i]=='*'||infix[i]=='/'))
				{
					do
					{

						if(top==NULL)
							break;
					}while((oprtop->data=='*'||oprtop->data=='/')  && (infix[i]=='*'||infix[i]=='/'));
					push(&oprtop, &infix[i]);
				}

				else if((oprtop->data=='*'||oprtop->data=='/')  && (infix[i]=='+'||infix[i]=='-'))
				{
					do
					{

						if(oprtop==NULL)
							break;
					}while((oprtop->data=='*'||oprtop->data=='/')  && (infix[i]=='+'||infix[i]=='-'));

				}
			}
		}
	}

	while(top!=NULL)
	{
		pop(&top,&ddata);
		postfix[j]=ddata;
		j++;
	}

	strcpy(fpostfix,postfix);
}

int main()
{
	char infix[100];
	char postfix[100];
	char postfixEval[100];
	//char prefix[100];
	int ans=0;
	int i=0;
	int ch=0;
	int cnt=1;

	do
	{
		ch=menu();
		switch(ch)
		{
		case 1:
			printf("\nEnter a String");
			scanf(" %[^\n]%*c",infix);

			intopost(infix,postfix);

			printf("\nPostfix : ");
			for(i=0;postfix[i]!='\0';i++)
			{
				printf(" %c",postfix[i]);
			}
			break;

		case 2:
			printf("\nEnter a Postfix String");
			scanf(" %[^\n]%*c",postfixEval);

			postEval(postfixEval,&ans);
			printf("\nAns: %d", ans);
			break;

		case 3:

			break;

		case 0:
			cnt=0;
			printf("\nThank You");
			break;
		}
	}while(cnt==1);

	return 0;
}


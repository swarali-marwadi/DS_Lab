/*
 * HospitalManagementSystem.c
 *
 *  Created on: 03-Oct-2025
 *      Author: sharyu
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char pname[20];
	int priority;
	struct node *next;
};

int menu()
{
	int ch=0;
	do
	{
	printf("\n\n-----------------Hospital Management System-----------------");
	printf("\nEnter Your Choice :");
	printf("\n1.Admit Patient");
	printf("\n2.Discharge Patient");
	printf("\n3.Stack Front");
	printf("\n4.Stack Rear");
	printf("\n0.Exit");
	printf("\nEnter your choice :");
	scanf("%d",&ch);
	if(ch<0||ch>4)
	{
		printf("\n!!Enter valid choice!!");
	}
	}while(ch<0||ch>4);
	return ch;
}

void admit(struct node **fhead, struct node **flast)
{
	struct node *head=NULL;
	struct node *last=NULL;
	struct node *newnode=NULL;
	struct node *i=NULL;
	char name[20];
	char ch;
	head=*fhead;
	last=*flast;

	do
	{
		newnode=(struct node *)calloc(1,sizeof(struct node));

		printf("\nEnter Patient's Details:");
		printf("\nName: ");
		scanf(" %[^\n]%*c",name);
		strcpy(newnode->pname, name);
		printf("Enter Priority: ");
		scanf("%d",&newnode->priority);
		newnode->next=NULL;

		if(newnode->priority==0)
		{
			printf("\n!!Invalid Priority!!");
			free(newnode);
			return;
		}

		if(head==NULL)
		{
			head=newnode;
			last=newnode;
		}
		else
		{
			if(newnode->priority>=last->priority)
			{
				last->next=newnode;
				last=newnode;
			}
			else if(newnode->priority==1)
			{
				if(head->priority==1)
				{
					for(i=head;(i->next->priority)==1;i=i->next)
					{
						continue;
					}
					newnode->next=i->next;
					i->next=newnode;
				}
				else
				{
					newnode->next=head;
					head=newnode;
				}
			}
			else
			{
				for(i=head;(i->next->priority)<=(newnode->priority);i=i->next)
				{
					continue;
				}
				newnode->next=i->next;
				i->next=newnode;
				if(i->next==NULL)
				{
					break;
				}
			}
		}

		printf("\nDo you want to admit another patient?");
		scanf(" %c",&ch);

	}while(ch=='y'||ch=='Y');

	*fhead=head;
	*flast=last;
}

int discharge(struct node **fhead, struct node **flast, char *fdischargedPatient)
{
	struct node *head=NULL;
	struct node *last=NULL;
	struct node *temp=NULL;

	head=*fhead;
	last=*flast;

	if(head==NULL)
	{
		return 1;
	}
	else
	{
		if(head==last)
		{
			last=NULL;
		}
		temp=head;
		strcpy(fdischargedPatient,head->pname);
		head=head->next;
		free(temp);
	}

	*fhead=head;
	*flast=last;

	return 0;
}

void display(struct node **fhead, struct node **flast)
{
	struct node *head=NULL;
	struct node *i=NULL;

	head=*fhead;

	if(head==NULL)
	{
		printf("\nNo Patients in Queue");
	}
	else
	{
		for(i=head;i!=NULL;i=i->next)
		{
			printf("\t%d|%s ->",i->priority,i->pname);
		}
		printf(" NULL\n");
	}
}

void display_Front(struct node **fhead)
{
	struct node *head=NULL;

	head=*fhead;

	if(head==NULL)
	{
		printf("\nNo Patients in Queue");
	}
	else
	{
		printf("\nQueue Front:");
		printf("\t%d|%s",head->priority,head->pname);
	}
}

void display_Rear(struct node **flast)
{
	struct node *last=NULL;

	last=*flast;

	if(last==NULL)
	{
		printf("\nNo Patients in Queue");
	}
	else
	{
		printf("\nQueue Rear:");
		printf("\t%d|%s",last->priority,last->pname);
	}
}

int main(void)
{
	struct node *head=NULL;
	struct node *last=NULL;
	char dischargedPatient[20];
	int queue_empty;
	int ch=0;
	int cnt=1;

	do
	{
		ch=menu();
		switch(ch)
		{
		case 1:
			admit(&head,&last);
			break;

		case 2:
			queue_empty=discharge(&head,&last,dischargedPatient);
			if(queue_empty==0)
			{
				printf("\nDischarged Patient :");
				printf("%s",dischargedPatient);
			}
			else
			{
				printf("\nNo Patients in Queue to Discharge");
			}
			break;

		case 3:
			display_Front(&head);
			break;

		case 4:
			display_Rear(&last);
			break;

		case 0:
			cnt=0;
			printf("\nThank You");
			break;
		}
	}while(cnt==1);
	return 0;
}

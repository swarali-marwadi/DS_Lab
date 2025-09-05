/*
 * SLL.c
 *
 *  Created on: Aug 14, 2025
 *      Author: administrator
 */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void accept(struct node **fhead,struct node **flast)
{
	struct node *head=NULL;
	struct node *last=NULL;
	struct node *newnode=NULL;

	char ch;
	int k=0;

	head=*fhead;
	last=*flast;

	do
	{
		newnode=(struct node *)calloc(1,sizeof(struct node));

		printf("\n\nEnter data : ");
		scanf("%d",&k);

		newnode -> data = k;
		newnode -> next = NULL;

		if(head==NULL)
		{
			head = newnode;
			last = newnode;
		}
		else
		{
			last -> next = newnode;
			last = newnode;
		}

		printf("\nDo you want to add another node? (y/n)");
		printf("\nEnter your Choice : ");
		scanf(" %c",&ch);

	}while(ch=='y' || ch=='Y');

	*fhead=head;
	*flast=last;
}

void display(struct node **fhead)
{
	struct node *head=NULL;
	struct node *i=NULL;

	head=*fhead;

	for(i=head;i!=NULL;i=i->next)
	{
		printf("\t%d ->",i->data);
	}

	printf(" NULL\n");
}

int countL(struct node **fhead)
{
	struct node *i=NULL;
	int count=1;
	for(i=*fhead;i->next!=NULL;i=i->next)
	{
		count++;
	}
	return count;
}

int menu()
{
	int ch=0;
	do
	{
	printf("\nEnter operation to perform on SSL :");
	printf("\n1.Insert");
	printf("\n2.Delete");
	printf("\n3.Revert");
	printf("\n4.Display");
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

void insert(struct node **fhead,struct node **flast)
{
	int how=0;
	int where=0;
	int which=0;
	int count=1;
	int size=0;
	int k=0;
	struct node *i=NULL;
	struct node *head=NULL;
	struct node *last=NULL;
	struct node *newnode=NULL;

	head=*fhead;
	last=*flast;


	newnode=(struct node *)calloc(1,sizeof(struct node));

	printf("\nEnter data to insert :");
	scanf("%d",&k);
	newnode -> data = k;
	newnode -> next = NULL;

	printf("\nHow do you want to insert?");
	printf("\n1.Using Data");
	printf("\n2.Using Position");
	printf("\nEnter your choice :");
	scanf("%d",&how);

	switch(how)
	{

	case 1:
		printf("\nWhere do you want to insert? :");
		printf("\n1.Before Data :");
		printf("\n2.After Data :");
		printf("\nEnter your choice :");
		scanf("%d",&where);
		if(where==1)
		{
			printf("\nBefore which data do you want to insert? :");
			printf("\nEnter your choice :");
			scanf("%d",&which);
			if(head->data==which)
			{
				newnode->next=head;
				head=newnode;
			}
			else
			{
				for(i=head;i->next->data!=which;i=i->next)
				{
					continue;
				}
				newnode->next=i->next;
				i->next=newnode;
			}
		}
		else if(where==2)
		{
			printf("\nAfter which data do you want to insert? :");
			printf("\nEnter your choice :");
			scanf("%d",&which);
			for(i=head;i->data!=which;i=i->next)
			{
				continue;
			}
			newnode->next=i->next;
			i->next=newnode;
		}
		else
		{
			printf("\nInvalid Choice!");
		}
		break;

	case 2:
		size=countL(&head);
		printf("\nWhich position do you want to insert? :");
		printf("\nEnter your choice :");
		scanf("%d",&which);
		if(which>0 && size+1>=which)
		{
			if(which==1)
			{
				newnode->next=head;
				head=newnode;
				if (last == NULL)
				{
					last = newnode;
				}
			}
			else
			{
				for(i=head;count!=(which-1);i=i->next)
				{
					count++;
				}
				newnode->next=i->next;
				i->next=newnode;
				if(newnode->next==NULL)
				{
					last=newnode;
				}
			}
		}
		else
		{
			printf("\nInvalid Choice!");
		}
		break;

	default:
		printf("\nInvalid Choice!");
		break;

	}

	*fhead=head;
	*flast=last;
}

void delete(struct node **fhead,struct node **flast)
{
	if(*fhead!=NULL)
	{
		int how=0;
		int which=0;
		int count=1;
		struct node *i=NULL;
		struct node *head=NULL;
		struct node *last=NULL;
		struct node *track=NULL;

		head=*fhead;
		last=*flast;

		printf("\nHow do you want to delete data?");
		printf("\n1.Using Data");
		printf("\n2.Using Position");
		printf("\nEnter your choice :");
		scanf("%d",&how);

		switch(how)
		{

		case 1:
			printf("\nWhich data do you want to delete? :");
			printf("\nEnter your choice :");
			scanf("%d",&which);

			if(head->data==which)
			{
				track=head;
				head=head->next;
				free(track);
			}
			else
			{
				for(i=head;i->next->data!=which;i=i->next)
				{
					continue;
				}
				track=i->next;
				i->next=i->next->next;
				free(track);
				if(i->next==NULL)
				{
					last=i;
				}
			}

			break;

		case 2:
			printf("\nWhich position do you want to delete? :");
			printf("\nEnter your choice :");
			scanf("%d",&which);

			if(which==1)
			{
				track=head;
				head=head->next;
				free(track);
			}
			else
			{
				for(i=head;count!=(which-1);i=i->next)
				{
					count++;
				}
				track=i->next;
				i->next=i->next->next;
				free(track);
				if(i->next==NULL)
				{
					last=i;
				}
			}

			break;


		}

		*fhead=head;
		*flast=last;
	}
	else
	{
		printf("\nNothing to delete in the Linked List");
	}
}

void revert(struct node **fhead,struct node **flast)
{
	struct node *head=NULL;
	struct node *last=NULL;
	struct node *curr=NULL;
	struct node *fwd=NULL;
	struct node *prev=NULL;

	head=*fhead;
	last=*flast;

	last=head;
	curr=head;
	prev=NULL;

	while(curr!=NULL)
	{
		fwd=curr->next;
		curr->next=prev;
		prev=curr;
		curr=fwd;
	}
	head=prev;

	*fhead=head;
	*flast=last;
}

int main(void)
{
	struct node *head=NULL;
	struct node *last=NULL;
	int ch=0;
	int cnt=1;

	printf("\nCreate Linked List :");
	accept(&head,&last);

	printf("\nEntered Linked List :");
	display(&head);
	printf("\n-------------------------------------------------------");

	do
	{
		ch=menu();
		switch(ch)
		{
		case 1:
			insert(&head,&last);
			printf("\nUpdated Linked List :");
			display(&head);
			printf("\n-------------------------------------------------------");
			break;

		case 2:
			delete(&head,&last);
			printf("\nUpdated Linked List :");
			display(&head);
			printf("\n-------------------------------------------------------");
			break;

		case 3:
			revert(&head,&last);
			printf("\nReverted Linked List :");
			display(&head);
			printf("\n-------------------------------------------------------");
			break;

		case 4:
			printf("\nLinked List :");
			display(&head);
			printf("\n-------------------------------------------------------");
			break;

		case 0:
			cnt=0;
			printf("\nThank You");
			break;
		}
	}while(cnt==1);

	return 0;
}

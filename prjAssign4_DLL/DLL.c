/*
 * DLL.c
 *
 *  Created on: 27-Aug-2025
 *      Author: sharyu
 */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

int menu()
{
	int ch=0;
	do
	{
	printf("\nEnter operation to perform on SSL :");
	printf("\n1.Insert");
	printf("\n2.Delete");
	printf("\n3.Traverse");
	printf("\n4.Reverse");
	printf("\n5.Revert");
	printf("\n0.Exit");
	printf("\nEnter your choice :");
	scanf("%d",&ch);
	if(ch<0||ch>5)
	{
		printf("\n!!Enter valid choice!!\n");
	}
	}while(ch<0||ch>5);
	return ch;
}

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
		newnode -> prev = NULL;

		if(head==NULL)
		{
			head = newnode;
			last = newnode;
		}
		else
		{
			last -> next = newnode;
			newnode -> prev = last;
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
	struct node *i=NULL;

	printf(" NULL <=>");
	for(i=*fhead;i!=NULL;i=i->next)
	{
		printf(" %d <=>",i->data);
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
	newnode -> prev = NULL;

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
				for(i=head;i->data!=which;i=i->next)
				{
					continue;
				}
				newnode->next=i;
				i->prev->next=newnode;
				newnode->prev=i->prev;
				i->prev=newnode;
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
			newnode->prev=i;
			i->next->prev=newnode;
			i->next=newnode;
			if(newnode->next==NULL)
			{
				last=newnode;
			}
		}
		else
		{
			printf("\nInvalid Choice!\n");
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
				if(i->next!=NULL)
				{
					newnode->next=i->next;
					newnode->prev=i;
					i->next->prev=newnode;
					i->next=newnode;
				}
				else
				{
					newnode->next=i->next;
					newnode->prev=i;
					i->next=newnode;
					last=newnode;
				}
			}
		}
		else
		{
			printf("\nInvalid Choice!\n");
		}
		break;

	default:
		printf("\nInvalid Choice!\n");
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
		int size=0;
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
				head->prev=NULL;
				free(track);
			}
			else
			{
				for(i=head;i->data!=which;i=i->next)
				{
					continue;
				}
				if(i->next!=NULL)
				{
					track=i;
					i->prev->next=i->next;
					i->next->prev=i->prev;
					free(track);
				}
				else
				{
					track=i;
					last=i->prev;
					i->prev->next=NULL;
					free(track);
				}
			}

			break;

		case 2:
			size=countL(&head);
			printf("\nWhich position do you want to delete? :");
			printf("\nEnter your choice :");
			scanf("%d",&which);
			if(which>0 && size>=which)
			{
				if(which==1)
				{
					track=head;
					head=head->next;
					head->prev=NULL;
					free(track);
				}
				else
				{
					for(i=head;count!=which;i=i->next)
					{
						count++;
					}
					if(i->next!=NULL)
					{
						track=i;
						i->prev->next=i->next;
						i->next->prev=i->prev;
						free(track);
					}
					else
					{
						track=i;
						last=i->prev;
						i->prev->next=NULL;
						free(track);
					}
				}
			}
			else
			{
				printf("\nInvalid Choice!\n");
			}
			break;

		default:
			printf("\nInvalid Choice!\n");
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

void reverse(struct node **fhead,struct node **flast)
{
	struct node *head=NULL;
	struct node *last=NULL;
	struct node *i=NULL;

	head=*fhead;
	last=*flast;

	printf(" NULL <=>");
	for(i=*flast;i!=NULL;i=i->prev)
	{
		printf(" %d <=>",i->data);
	}
	printf(" NULL\n");

	*fhead=head;
	*flast=last;
}

void revert(struct node **fhead,struct node **flast)
{
	struct node *head=NULL;
	struct node *last=NULL;
	struct node *temp=NULL;
	struct node *curr=NULL;
	struct node *fwd=NULL;

	head=*fhead;
	last=*flast;

	curr=head;
	fwd=head;

	while(curr!=NULL)
	{
		fwd=curr->next;

		temp=curr->next;
		curr->next=curr->prev;
		curr->prev=temp;

		curr=fwd;
	}

	temp=head;
	head=last;
	last=temp;

	*fhead=head;
	*flast=last;
}

void revertM2(struct node **fhead,struct node **flast)
{
	struct node *head=NULL;
	struct node *last=NULL;
	struct node *h1=NULL;
	struct node *l1=NULL;
	struct node *dnode=NULL;

	head=*fhead;
	last=*flast;

	while(head!=NULL && last!=NULL)
	{
		dnode=head;
		head=head->next;
		dnode->next=NULL;
		if(h1==NULL)
		{
			h1=dnode;
			l1=dnode;
		}
		else
		{
			dnode->next=h1;
			h1=dnode;
		}
	}

	head=h1;
	last=l1;

	*fhead=head;
	*flast=last;
}

int main()
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
			printf("\nLinked List :");
			display(&head);
			printf("\n-------------------------------------------------------");
			break;


		case 4:
			printf("\nReversed Linked List :");
			reverse(&head,&last);
			printf("\n-------------------------------------------------------");
			break;

		case 5:
			revertM2(&head,&last);
			printf("\nReverted Linked List :");
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

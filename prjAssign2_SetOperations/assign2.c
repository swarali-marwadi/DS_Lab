/*
 * assign2.c
 *
 *  Created on: Jul 31, 2025
 *      Author: administrator
 */
#include<stdio.h>

int accept(int *farr,int fsize)
{
	printf("\nEnter elements of array:\n");
	for(int i=0;i<fsize;i++)
	{
		printf("Enter element %d  : ",i+1);
		scanf("%d",&farr[i]);
	}
	return 0;
}

int display(int *farr,int fsize)
{
	for(int i=0;i<fsize;i++)
	{
		printf("\t%d",farr[i]);
	}
	return 0;
}


int menu(void)
{
	int choice = 0;
	do
	{
		printf("\nMenu");
		printf("\n1.");
		printf("\n2.");
		printf("\n3.");
		printf("\n0.Exit");
		printf("\nEnter Choice:");
		scanf("%d",&choice);
	}while(choice < 0 || choice > 3);
	return choice;
}

int Union(int *fu,int *fa,int *fb,int fn,int fm)
{
	int count=0;
	for(int i=0;i<fn;i++)
	{
		fu[i]=fa[i];
		count++;
	}
	for(int i=0;i<fm;i++)
	{
		int found=0;
		for(int j=0;j<fn;j++)
		{
			if(fb[i]==fa[j])
			{
				found=1;
				break;
			}
		}
		if(found==0)
		{
			fu[count]=fb[i];
			count++;
		}
	}
	return count;
}

int Intersection(int *fu,int *fa,int *fb,int fn,int fm)
{
	int count=0;
	for(int i=0;i<fm;i++)
	{
		int found=0;
		for(int j=0;j<fn;j++)
		{
			if(fb[i]==fa[j])
			{
				found=1;
				break;
			}
		}
		if(found==1)
		{
			fu[count]=fb[i];
			count++;
		}
	}
	return count;
}

int main(void)
{
	int n=0,m=0;

	printf("\nEnter the length of 1st array to enter:");
	scanf("%d",&n);
	int a[n];
	accept(a,n);
	printf("\nEntered 1st array is:");
	display(a,n);
	printf("\n");

	printf("\nEnter the length of 2nd array to enter:");
	scanf("%d",&m);
	int b[m];
	accept(b,m);
	printf("\nEntered 2nd array is:");
	display(b,m);
	printf("\n");

	int u[n+m];
	int count=Union(u,a,b,n,m);
	printf("\nUnion of arrays is: ");
	display(u,count);
	printf("\n");

	int i[n+m];
	count=Intersection(i,a,b,n,m);
	printf("\nIntersection of arrays is: ");
	display(i,count);
	printf("\n");

	return 0;
}

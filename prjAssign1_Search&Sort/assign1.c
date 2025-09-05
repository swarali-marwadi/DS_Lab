/*
 * linearSearch.c
 *
 *  Created on: Jul 24, 2025
 *      Author: administrator
 */

#include<stdio.h>

#include</home/sharyu/Desktop/eclipse-c/prjAssign1/search.h>
#include</home/sharyu/Desktop/eclipse-c/prjAssign1/sort.h>

int accept(int *fa,int fn);
int display(int *fa,int fn);


int menu(void)
{
	int choice = 0;
	do
	{
		printf("\nMenu");
		printf("\n1.Linear Search");
		printf("\n2.Bubble Sort");
		printf("\n3.Binary Search");
		printf("\n0.Exit");
		printf("\nEnter Choice:");
		scanf("%d",&choice);
	}while(choice < 0 || choice > 3);
	return choice;
}

int accept(int *fa,int fn)
{
	printf("\nEnter elements of array:");
	for(int i=0;i<fn;i++)
	{
		printf("\nEnter %d element : ",i+1);
		scanf("%d",&fa[i]);
	}
	return 0;
}

int display(int *fa,int fn)
{
	for(int i=0;i<fn;i++)
	{
		printf("\t%d",fa[i]);
	}
	return 0;
}


int main(void)
{
	int n=0;
	int a[10]={0};
	int key=0;
	int found=0;
	printf("Enter the length of array to enter:");
	scanf("%d",&n);
	if(n>0 && n<11)
	{
		accept(a,n);

		printf("\nEntered array is:");
		display(a,n);
		printf("\n");

		int ch=0;

		do
		{
			ch = menu();

			switch(ch)
			{
			case 1:

				printf("\nEnter number to search:");
				scanf("%d",&key);

				found =	linearSearch(a,n,key);
				if(found==0)
				{
					printf("Number %d found in the array\n",key);
				}
				else
				{
					printf("Number %d not found in the array\n",key);
				}
				break;

			case 2:

				sort(a,n);
				printf("\nSorted Array:");
				display(a,n);
				printf("\n");
				break;

			case 3:


				sort(a,n);
				printf("\nEnter number to search:");
				scanf("%d",&key);

				found =	binarySearch(a,n,key);
				if(found==1)
				{
					printf("Number %d found in the array\n",key);
				}
				else
				{
					printf("Number %d not found in the array\n",key);
				}
				break;

			case 0:

				printf("\nThank You");
				break;
			}

		}while(ch != 0);
	}

	else
	{
		printf("\n\tEnter array length in between 1 and 10");
	}




	return 0;
}

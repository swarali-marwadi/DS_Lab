/*
 * stackArray.c
 *
 *  Created on: Sep 4, 2025
 *      Author: administrator
 */
#include<stdio.h>

int menu();
int push();
int pop();
int stack_full();
int stack_empty();

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

int push()
{
	int success=0;

	return success;
}

int pop()
{
	int success=0;

	return success;
}

int stack_full()
{
	int success=0;

	return success;
}

int stack_empty()
{
	int success=0;

	return success;
}

int main()
{
	int ch=0;
	int idata=0;
	int success=0;

	ch=menu();
	switch(ch)
	{
	case 1:
		printf("\nEnter data to push :");
		scanf("%d",&idata);
		break;

	case 2:
		break;

	case 0:
		break;
	}
	return 0;
}




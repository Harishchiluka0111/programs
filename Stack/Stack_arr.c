#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Stack[MAX];
int top=-1;

void Push(int);
int Pop();
int Peek();

int Isfull();
int Isempty();

int main()
{
	int choice,data;
	while(1)
	{
		printf("1. Push 2 .Pop 3.Peek 4.exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the data\n");
				scanf("%d",&data);
				if(Isfull())
				{
					printf("Stack is full\n");
				}
				else
				{
					Push(data);
				}
				break;
			case 2: if(Isempty())
				{
					printf("Stack is empty\n");
				}
				else
				{
					printf("data poped by stack is %d\n",Pop());
				}
				break;
			case 3:
				if(Isempty())
				{
					printf("Stack is empty\n");
				}
				else
				{
					printf("top of the stack pointing to %d",Peek());
				}
				break;
			case 4: exit(0);
		}
	}
}

int Isfull()
{
	if(top==MAX-1)
		return 1;
	return 0;
}

int Isempty()
{
	if(top==-1)
		return 1;
	return 0;
}

void Push(int d)
{
	Stack[++top]=d;
}

int Pop()
{
	return Stack[top--];
}
int Peek()
{
	return Stack[top];
}

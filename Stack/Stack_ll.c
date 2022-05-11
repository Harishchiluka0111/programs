#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct Stack
{
	int data;
	struct Stack *link;
};
struct Stack *top=NULL;
void Push(int);
int Pop();
int Peek();
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
				Push(data);
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



void Push(int d)
{
	struct Stack *newnode=NULL;
	newnode=calloc(1,sizeof(struct Stack));
	if(newnode==NULL)
		printf("Stack is full\n");
	else
	{
		newnode->data=d;
	newnode->link=top;
	top=newnode;
	}

}

int Pop()
{
	struct Stack *temp=NULL;
		int d;
		temp=top;
		d=temp->data;
	top=top->link;
	free(temp);
	temp=NULL;
	return d;
}
int Peek()
{
	return top->data;
}

int Isempty()
{
	if(top==NULL)
		return 1;
	return 0;
}

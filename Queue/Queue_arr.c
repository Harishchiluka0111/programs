#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Queue[MAX];
int front=-1,rear=-1;
void Enq(int);
int Deq();
int Isfull();
int Isempty();

int main()
{
	int choice,data;
	while(1)
	{
		printf("1.Enq 2.Deq 3.exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: printf("enter the data\n");
			scanf("%d",&data);
			if(Isfull())
				printf("Queue is full\n");
			else
			{
				Enq(data);
			}
			break;
		case 2: if(Isempty())
				printf("Queue is empty\n");
			else
			printf("data dequed is %d\n",Deq());
			break;
		case 3: exit(0);
		}
	}
}

void Enq(int d)
{

	if(front==-1)
		front=0;
	Queue[++rear]=d;
}


int Deq()
{
	int temp;
	temp=Queue[front++];

	if(front==rear+1)
		front=rear=-1;
	return temp;
}

int Isfull()
{
	if(rear==MAX-1)
		return 1;
	return 0;
}

int Isempty()
{
	if(front==-1)  // or if(rear==-1)
		return 1;
	return 0;
}







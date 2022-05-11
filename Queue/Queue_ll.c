#include<stdio.h>
#include<stdlib.h>
struct Queue
{
	int data;
	struct Queue *link;
};
struct Queue *front,*rear;
void Enq(int d)
{
	struct Queue *newnode=NULL;
	newnode=calloc(1,sizeof(struct Queue));
	if(newnode==NULL)
	{
		printf("Queue is Full\n");
	}
	else
	{
		newnode->data=d;
		if(front==NULL) // queue is empty
			front=newnode;
		else
		//if(rear)
			rear->link=newnode;
		rear=newnode;
	}
}

int Deq()
{
	int d;
	struct Queue *temp=NULL;
	temp=front;
	d=temp->data;
	front=front->link;
	if(front==NULL)
		rear=NULL;
	free(temp);
	temp=NULL;
	return d;
}



int main()
{
	int choice,data;
	while(1)
	{
		printf("1. Enq 2.Deq 3.exit\n");
		printf("enter thr choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the data\n");
				scanf("%d",&data);
				Enq(data);
				break;
			case 2: if(front==NULL)
				printf("Queue is empty\n");
				else
			printf("data dequed is %d",Deq());
				break;
			case 3: exit(0);
		}
	}
}

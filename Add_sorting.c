#include<stdio.h>
#include<stdlib.h>

struct Student
{
	int roll;
	char name[20];
	float marks;
	struct Student *link;// selfreferential ptr
};

struct Student * Add(struct Student *);
void Display(struct Student *);
int main()
{
	int choice;
	struct Student *head=NULL;
	while(1)
	{
		printf("1.Add 2.Display 3.exit \n");
		printf("enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=Add(head);
				break;
			case 2: Display(head);
				break;
			case 3: exit(0);
				break;
			
		}
	}
}

struct Student * Add(struct Student *ptr)
{
	struct Student *newnode=NULL,*temp=NULL,*prev=NULL;
	/*** creation of the node ****/
	newnode=calloc(1,sizeof(struct Student ));

	if(newnode==NULL)
	{
		printf("node not created\n");
	}
	else
	{
		/*** initialise the node ****/
	       printf("enter the roll\n");
       		scanf("%d",&newnode->roll);
		printf("enter the name\n");
		scanf("%s",newnode->name);
		printf("enter the marks\n");
		scanf("%f",&newnode->marks);
		/* if list is empty or newnode roll is smaller than first node roll , adding newnode as first node******/
		if(ptr==NULL || newnode->roll < ptr->roll)
		{
			newnode->link=ptr;
			ptr=newnode;
		}
		else
		{	/** if list is empty and newnode roll is greater than first node roll,then traverse inthe list untill we reach end of the list or until we come across a value which is greater than newnode roll *********/
			prev=ptr;
			temp=ptr->link;
		while(temp && newnode->roll > temp->roll)
		{
			prev=temp;
			temp=temp->link;
		}
		prev->link=newnode;//newnode address is assigned to prev link
		newnode->link=temp; // temp is assigned to newnode link;
		/** we are inserting newnode between the prev and temp nodes****/ 
		}
	}
	return ptr;// returning first node address
}


void Display(struct Student *ptr)
{
	if(ptr==NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(ptr)
	{

		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
		ptr=ptr->link;
	}
}





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
struct Student *Reverse(struct Student *);



int main()
{
	int choice;
	struct Student *head=NULL;
	while(1)
	{
		printf("1.Add 2.Display 3.Reverse 4.exit ");
		printf("enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=Add(head);
				break;
			case 2: Display(head);
				break;
			case 3: head=Reverse(head);
				break;
			case 4: exit(0);
				break;
			}
	}
}

struct Student * Add(struct Student *ptr)
{
	struct Student *newnode=NULL,*temp=NULL;
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
		//newnode->link=NULL to wriiten if we use 
		//malloc func for creation of node
		if(ptr==NULL)// List is empty
		{
			ptr=newnode; // making newnode as first node


		}
		else
		{
			// if list is already existing , traverse up to last node and link newnode to last node
		for(temp=ptr;temp->link;temp=temp->link);

		temp->link=newnode; // linking newnode to last node
		}
	}
	return ptr;
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




struct Student *Reverse(struct Student *ptr)
{
	struct Student *prev=NULL,*cur=NULL,*next=NULL;

	if(ptr==NULL)// list is empty
	{
		printf("SLL is empty\n");
//		return ptr;
	}
	else if(ptr->link==NULL)
	{
		printf("SLL is having only one node\n");
	}
	else
	{
		next=ptr;
		while(next)
		{
			prev=cur;
			cur=next;
			next=next->link;
			cur->link=prev;// linking with prevnode
		}
		ptr=cur;
	}
	return  ptr;
}

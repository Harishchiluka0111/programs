#include<stdio.h>
#include<stdlib.h>

struct Student
{
	int roll;
	char name[20];
	float marks;
	struct Student *link;
};

struct Student  * Add(struct Student *);
void Display(struct Student *);
struct Student * Del_last(struct Student *);
struct Student * Del_roll(struct Student *);
int main()
{
	struct Student *head=NULL;
	int choice;
	while(1)
	{
		printf("1.Add 2. Del_last 3.Display 4.del_roll5. exit\n");
		printf("enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=Add(head);
				break;
			case 2: head=Del_last(head);
				break;
			case 3: Display(head);

				break;
			case 4: head=Del_roll(head);
				break;
			case 5: exit(0);
		}
	}
}


struct Student *Add(struct Student *ptr)
{
	struct Student *newnode=NULL,*temp=NULL;
	newnode=calloc(1,sizeof(struct Student));
	if(newnode==NULL)
	{
		printf("node not created\n");
		return ptr;
	}
	else
	{
		printf("enter the roll\n");
		scanf("%d",&newnode->roll);
		printf("enter the name\n");
		scanf("%s",newnode->name);
		printf("enter the marks\n");
		scanf("%f",&newnode->marks);
		if(ptr==NULL)
		{
			ptr=newnode;
		}
		else
		{
			for(temp=ptr;temp->link;temp=temp->link);
			temp->link=newnode; 
		}
		return ptr;
	}


}





void Display(struct Student *ptr)
{
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(ptr)
		{
			printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
					ptr=ptr->link;
					}
	}
}


struct Student * Del_last(struct Student *ptr)
{
	struct Student *temp=NULL,*prev=NULL;
	if(ptr==NULL)
	{
		printf("list is empty\n");
		return ptr;
	}
	temp=ptr;
	while(temp->link)
	{
		prev=temp;
		temp=temp->link;
	}
	free(temp);
	temp=NULL;
	if(prev)
		prev->link=NULL;
	else
		ptr=NULL;
	return ptr;
}


struct Student *Del_roll(struct Student *ptr)
{
	struct Student *temp=NULL,*prev=NULL;
	int data;
	printf("enter the data to be deleted\n");
	scanf("%d",&data);
	if(ptr==NULL)
	{
		printf("lsit is empty\n");
		return ptr;
	}
	else if(data==ptr->roll)// matching with first node data
	{
		temp=ptr;
		ptr=ptr->link;
		free(temp);
		temp=NULL;
	}
	else
	{
		temp=ptr->link;
		prev=ptr;
		// traversing until we find the data or we reached the end of the list
		while(temp && temp->roll!=data)
		{
			prev=temp;
			temp=temp->link;
		}
		if(temp==NULL)  // if we reach end of the list
		{
			printf("%d is not found\n",data);
		}
		else
		{// if data found, linking prev node with next node of temp
			prev->link=temp->link;
			free(temp);// deleting temp
			temp=NULL;
		}
	}
		return ptr;// returning first node address
}

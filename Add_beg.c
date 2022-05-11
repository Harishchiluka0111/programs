#include<stdio.h>
#include<stdlib.h>


struct Student 
{
	int roll;
	char name[20];
	float marks;
	struct Student *link;
};

struct Student *Add_beg(struct Student *);
void Display(struct Student *);
void Save(struct Student *);

int main()
{
	struct Student *head=NULL;
	int choice;
	while(1)
	{
		printf("1. Add_beg 2.Display 3. Save 4.exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=Add_beg(head);
				break;
			case 2: Display(head);
				break;
			case 3: Save(head);
				break;
			case 4: exit(0);
		}
	}
}



struct Student * Add_beg(struct Student *ptr)
{
	struct Student *newnode=NULL;
	/*** creating a node ***/
	newnode=calloc(1,sizeof(struct Student));
	if(newnode==NULL)
	{
		printf("node not created\n");
		return ptr;
	}
	/*** initisation of node ****/
	printf("enter the roll\n");
	scanf("%d",&newnode->roll);
	printf("enter the name\n");
	scanf("%s",newnode->name);
	printf("enter the marks\n");
	scanf("%f",&newnode->marks);
/** linking to list ****/
	newnode->link=ptr; // existing first node add assignedto newnode link
	ptr=newnode; // newnode added as first node
	return ptr;
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



void Save(struct Student *ptr)
{
	FILE *fp;
	if(ptr==NULL)
	{
		printf("List is empty\n");
		return;
	}
	fp=fopen("Stu","w");
	if(fp==NULL)
	{
		printf("filenot opened\n");
		return;
	}
	while(ptr)
	{
		fwrite(ptr,1,sizeof(struct Student)-sizeof(struct Student *),fp);
		ptr=ptr->link;
	}
	fclose(fp);
}

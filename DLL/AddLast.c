#include"myheader.h"

struct Person * Add_last(struct Person *ptr)
{
	struct Person *newnode=NULL,*temp=NULL;
	newnode=calloc(1,sizeof(struct Person));
	if(newnode==NULL)
	{
		printf("Node not created\n");
	}
	else
	{
		printf("enter the age\n");
		scanf("%d",&newnode->age);
		printf("enter the name\n");
		scanf("%s",newnode->name);
		if(ptr==NULL)
		{
			ptr=newnode;
		}
		else
		{
			for(temp=ptr;temp->link;temp=temp->link);
			temp->link=newnode;//forward linking
			newnode->prev=temp;// backward linking
		}
	}
	return ptr;
}


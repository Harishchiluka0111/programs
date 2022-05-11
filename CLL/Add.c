#include"myheader.h"
struct Employee * Add(struct Employee *ptr)
{
	struct Employee *newnode=NULL,*temp=NULL;

	newnode=calloc(1,sizeof(struct Employee));
	if(newnode==NULL)
	{
		printf("node not created\n");
	}
	else
	{
		printf("enter the empid\n");
		scanf("%d",&newnode->empid);
		printf("enter the name\n");
		scanf("%s",newnode->name);
		if(ptr==NULL)
		{
			// list is empty
			ptr=newnode;
			newnode->link=ptr;
			// newnode->link=newnode
		}
		else
		{
			for(temp=ptr;temp->link!=ptr;temp=temp->link);

			temp->link=newnode;
			newnode->link=ptr;
			/***
			 newnode->link=temp->link
			 temp->link=newnode
			 ****/
		}
	}
		return ptr;
}



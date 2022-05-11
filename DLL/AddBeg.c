#include"myheader.h"

struct Person * Add_beg(struct Person *ptr)
{
	struct Person *newnode=NULL;
	newnode=calloc(1,sizeof(struct Person));
	if(newnode==NULL)
	{
		printf("node not created\n");
	}
	else
	{
		printf("enter the age\n");
		scanf("%d",&newnode->age);
		printf("enter the name\n");
		scanf("%s",newnode->name);

		newnode->link=ptr;// forward linking
		if(ptr)
			ptr->prev=newnode;// backward linking
		ptr=newnode;
	}
	return ptr;
}
	

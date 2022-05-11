#include"myheader.h"

struct Person * Del_data(struct Person *ptr)
{
	struct Person *temp=NULL;
	int data;
	printf("enter the data to be deleted\n");
	scanf("%d",&data);
	if(ptr==NULL)
	{
		printf("DLL is empty\n");
	}
	else if(data==ptr->age)
	{
		/*temp=ptr;
		ptr=ptr->link;
		if(ptr)
			ptr->prev=NULL;
		free(temp);
		temp=NULL;*/
		ptr=Del_first(ptr);
	}
	else
	{
		temp=ptr;
		while(temp && temp->age !=data)
			temp=temp->link;
		if(temp==NULL)
		{
			printf("%d is not found\n",data);
		}
		else
		{
			temp->prev->link=temp->link;
			if(temp->link)
			temp->link->prev=temp->prev;
			free(temp);
			temp=NULL;
		}

	}
	return ptr;
}






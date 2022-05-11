#include"myheader.h"

struct Person * Dellast(struct Person *ptr)
{
	struct Person *temp=NULL;
	if(ptr==NULL)
	{
		printf("DLL is empty\n");
		//return ptr;
	}
	else
	{
		for(temp=ptr;temp->link;temp=temp->link);
		if(temp->prev)
			temp->prev->link=NULL;
		else
			ptr=NULL;
		free(temp);
		temp=NULL;
	//	return ptr;

	}
	return ptr;
}

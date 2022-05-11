#include"myheader.h"

struct Person * Del_first(struct Person *ptr)
{
	struct Person *temp=NULL;
	if(ptr==NULL)
	{
		printf("DLL is empty\n");
	}
	else
	{
		temp=ptr;// assigning first node to temp
		ptr=ptr->link;// moving ptr to next node
		if(ptr)
			ptr->prev=NULL;// making ptr->prevto NULL
		free(temp);// deleting first node
		temp=NULL;
	}
	return ptr;
}

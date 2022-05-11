#include"myheader.h"

struct Person *Reverse(struct Person *ptr)
{
	struct Person *temp=NULL,*temp1=NULL;
	if(ptr==NULL)
	{
		printf("DLL is empty\n");
	}
	else if(ptr->link==NULL)
	{
		printf("DLL is having one node\n");
	}
	else
	{
		temp=ptr;
		while(temp)
		{
			temp1=temp->prev;
			temp->prev=temp->link;
			temp->link=temp1;
			temp=temp->prev;// moving ot next node
		}
		ptr=temp1->prev;
	}
	return ptr;
}

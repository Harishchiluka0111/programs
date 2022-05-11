#include"myheader.h"
void RDisplay(struct Person* ptr)
{
	if(ptr==NULL)
	{
		printf("DLL is empty\n");
	}
	else
	{
		for(;ptr->link;ptr=ptr->link);
		
		while(ptr)
		{
		printf("%d %s\n",ptr->age,ptr->name);
		ptr=ptr->prev;// backward traversing
		}
	}
}

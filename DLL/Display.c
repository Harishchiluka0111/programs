#include"myheader.h"

void Display(struct Person *ptr)
{
	if(ptr==NULL)
	{
		printf("DLL is empty\n");
	}
	else
	{
		while(ptr)
		{
			printf("%d %s\n",ptr->age,ptr->name);
			ptr=ptr->link;
		}
	}
}

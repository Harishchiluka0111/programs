#include"myheader.h"

void Display(struct Employee *ptr)
{
	struct Employee *temp=NULL;
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		temp=ptr;
		do
		{
			printf("%d %s\n",temp->empid,temp->name);
			temp=temp->link;
		}while(temp!=ptr);
	}
}

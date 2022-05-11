#include"myheader.h"

struct Employee * Del(struct Employee *ptr)
{
	int data;
	struct Employee *temp=NULL,*temp1=NULL;
	printf("enter the data to be deleted\n");
	scanf("%d",&data);
	if(ptr==NULL)
	{
		printf("CLL is empty\n");
	}
	else if(data==ptr->empid)
	{//matching with first node data
		temp=ptr;
		ptr=ptr->link;
		if(ptr==temp)// only single node
			ptr=NULL;
		else
		{
	// making second node or next node address to ptr
	
		for(temp1=temp;temp1->link!=temp;temp1=temp1->link);
		temp1->link=ptr;
		}

	// lastnode link should be updated with lastest first node address
		free(temp);
		temp=NULL;
	}
	else
	{
		temp=ptr;
		temp1=ptr->link;
		while(temp1!=ptr && data != temp1->empid)
		{
			temp=temp1;
			temp1=temp1->link;
		}
		if(temp1==ptr)
		{
			printf("&d is not found\n",data);
		}
		else
		{
			temp->link=temp1->link;
			free(temp1);
			temp1=NULL;
		}
	}
return ptr;
}


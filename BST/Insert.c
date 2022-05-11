#include"myheader.h"

struct BST* insert(struct BST *ptr,int d)
{
	struct BST *newnode=NULL;
	if(ptr==NULL) // if their is a vaccance create node 
	{
		newnode=calloc(1,sizeof(struct BST));
		if(newnode==NULL)
		{
			printf("node not created\n");
			//return ptr;
		}
		newnode->data=d;
		ptr=newnode;
		//return ptr;
	}
	else if(d < ptr->data) // if data is smaller than cur node data ,traverse to left subtree
		ptr->left=insert(ptr->left,d);
	else if(d > ptr->data)// if data is greater than cur node data,traverse to right subtree
		ptr->right=insert(ptr->right,d);
	else
		printf("duplicates are not allowed\n");
	return ptr;
}

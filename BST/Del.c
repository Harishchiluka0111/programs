#include"myheader.h"

struct BST * Del(struct BST *ptr,int d)
{
	struct BST *temp=NULL;
	if(ptr==NULL)
	{
		printf("%d not found\n",d);
	}
	else if(d < ptr->data)
	{
		ptr->left=Del(ptr->left,d);
	}
	else if(d > ptr->data)
	{
		ptr->right=Del(ptr->right,d);
	}
	else// data matched
	{
		if(ptr->left && ptr->right)// node having two children
		{
			temp=findmin(ptr->right); // finding node with min val fron right subtree
			ptr->data=temp->data;// overwriting node to de deleted with node with min val
			ptr->right=Del(ptr->right,temp->data);// searching and deleting node with min val from right subtree
		}
		else// node having only single child or no child
		{
			temp=ptr;
			if(ptr->left==NULL)// node having right child or no childrens
				ptr=ptr->right;
			else // node having left child
				ptr=ptr->left;
			free(temp);
			temp=NULL;
		}
	}
	return ptr;
}

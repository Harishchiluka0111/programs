#include"myheader.h"

struct BST * Search(struct BST* ptr,int d)
{	static int cnt=-1;
	cnt++;
	if(ptr==NULL)
		return NULL;
	// data is smaller than cur node data
	else if(d < ptr->data)
		return Search(ptr->left,d);// traversing to left subtree
	// data is greater than cur node data
	else if(d > ptr->data)
		return Search(ptr->right,d);// traversing to right subtree

	else  // data matched
	{
		printf("level is %d\n",cnt);
		cnt=-1;
		return ptr;// returning matched data node 
	}
}

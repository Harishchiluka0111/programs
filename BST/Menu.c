#include"myheader.h"

int main()
{
	int choice,data;
	struct BST *root=NULL,*temp=NULL;
	while(1)
	{
		printf("1.Insert 2. Preorder 3.Inorder 4.postorder5. Search 9.exit\n");
		printf("enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the data\n");
				scanf("%d",&data);
				root=insert(root,data);
				break;
			case 2: preorder(root);
				break;
			case 3 :  inorder(root);
				  break;
			case 4: postorder(root);
				break;
			case 5: printf("enter the data to be searched\n");
				scanf("%d",&data);
				temp=Search(root,data);
				if(temp==NULL)
					printf("%d is not found\n",data);
				else
					printf("%d is found\n",temp->data);
				break;
			case 9: exit(0);
		}
	}
}


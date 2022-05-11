#include"myheader.h"

int main()
{
	struct Person *head=NULL;
	int choice;
	while(1)
	{
		printf("1. Add_last 2.Display 3.RDisplay 4.exit 5.Del_first\n");
		printf("enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=Add_last(head);
				break;
			case 2:Display(head);
			       break;
			case 3: RDisplay(head);
				break;
			case 4: exit(0);
			case 5: head=Del_first(head);

		}
	}
}

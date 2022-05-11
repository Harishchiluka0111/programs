#include"myheader.h"

int main()
{
	struct Person *head=NULL;
	int choice;

	while(1)
	{
		printf("1.Add_beg 2.Display 3.exit 4.Reverse\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=Add_beg(head);
				break;
			case 2: Display(head);
				break;
			case 3: exit(0);
			case 4: head=Reverse(head);
		}
	}
}

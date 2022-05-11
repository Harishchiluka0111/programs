#include"myheader.h"

int main()
{
	struct Employee *head=NULL;
	int choice;
	while(1)
	{
		printf("1.Add 2.Del 3.Display 4.Exit\n");
		printf("enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=Add(head);
				break;
			case 3: Display(head);
				break;
			case 2: head=Del(head);
				break;
			case 4: exit(0);
		}
	}
}


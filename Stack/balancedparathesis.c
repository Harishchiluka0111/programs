#include<stdio.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void Push(char);
char Pop();



int main()
{
	char exp[SIZE];
	int i=0;
	printf("enter the exp\n");
	scanf("%s",exp);
	while(exp[i])
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			
			Push(exp[i]);
		else if(exp[i]==')')
		{
			if(Pop()!='(')
			{//printf("%s is invalid exp\n",exp);
				break;
			}
		}
		else if(exp[i]=='}')
		{
			if(Pop()!='{')
			{
			 //printf("%s is invalid exp\n",exp);
			 break;
			}
		}
		else if(exp[i]==']')
		{
			if(Pop()!='[')
			{
			//printf("%s is invalid exp\n",exp);
			break;
			}
		}
		i++;
	}
	if(exp[i]=='\0' && top==-1)
	{
		printf("%s is balanced parathesis\n",exp);
	}
	else
	{
		printf("%s is invalid\n",exp);
	}
		
}

void Push(char ch)
{
	if(top==SIZE-1)// stack is full
		return;
	stack[++top]=ch;
}
char Pop()
{
	if(top==-1)// stack is empty
		return -1;
	return stack[top--];
}



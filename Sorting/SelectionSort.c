#include<stdio.h>
#include<stdlib.h>

#define SIZE 100000
void Input(int *,int);
void Display(int *,int);
void Selection(int *,int);

int main()
{
	int A[SIZE];
	Input(A,SIZE);
	printf("elements of an array before sorting\n");
	Display(A,SIZE);
	Selection(A,SIZE);
	printf("elements of an array after sorting\n");
	Display(A,SIZE);
}

void Input(int *p,int size)
{
int i=0;
srand(getpid());
for(i=0;i<size;i++)
	p[i]=rand()%10000;  //p[i]---->*(p+i)
}

void Display(int *p,int size)
{	int i=0;
	for(i=0;i<size;i++)
		printf("%d ",p[i]);
	printf("\n");
}

void Selection(int *p,int size)
{
	int i=0,j=0,temp;
	for(i=0;i<size-1;i++)   
	{
		for(j=i+1;j<size;j++) 
		{
			if(p[i]>p[j])
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}

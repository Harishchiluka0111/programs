#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
void Input(int *,int);
void Display(int *,int);
void Bubble(int *,int);

int main()
{
	int A[SIZE];
	Input(A,SIZE);
	printf("elements of an array before sorting\n");
	Display(A,SIZE);
	Bubble(A,SIZE);
	printf("elements of an array after sorting\n");
	Display(A,SIZE);
}

void Input(int *p,int size)
{
int i=0;
srand(getpid());
for(i=0;i<size;i++)
	p[i]=rand()%1000;  //p[i]---->*(p+i)
}

void Display(int *p,int size)
{	int i=0;
	for(i=0;i<size;i++)
		printf("%d ",p[i]);
	printf("\n");
}

void Bubble(int *p,int size)
{
	int i=0,j=0,temp;
	for(i=1;i<size;i++)   // for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i;j++) // for(j=0;j<size-i-1;j++)
		{
			if(p[j]>p[j+1])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}

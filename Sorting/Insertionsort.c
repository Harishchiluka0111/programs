#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
void Input(int *,int);
void Display(int *,int);
void Insertion(int *,int);

int main()
{
	int A[SIZE];
	Input(A,SIZE);
	printf("elements of an array before sorting\n");
	Display(A,SIZE);
	Insertion(A,SIZE);
	printf("elements of an array after sorting\n");
	Display(A,SIZE);
}

void Input(int *p,int size)
{
int i=0;
srand(getpid());
for(i=0;i<size;i++)
	p[i]=rand()%100;  //p[i]---->*(p+i)
}

void Display(int *p,int size)
{	int i=0;
	for(i=0;i<size;i++)
		printf("%d ",p[i]);
	printf("\n");
}

void Insertion(int *p,int size)
{
	int i=0,j=0,temp;
	for(i=1;i<size;i++)  // index of unsorted part
	{
		temp=p[i]; // unsorted ele to be inserted in sorted part
		j=i-1; // index of last ele in sorted part
		while(j>=0 && temp<p[j])  // if j is valid index and temp is smaller than p[j], move p[j] to next index
		{
			p[j+1]=p[j];
			j--;
		}
		p[j+1]=temp;
	}
}

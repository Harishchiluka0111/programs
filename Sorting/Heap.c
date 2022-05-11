#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
void Input(int *,int);
void Display(int *,int);
void Heap(int *,int);
void Heapify(int *,int,int);

int main()
{
	int A[SIZE];
	Input(A,SIZE);
	printf("elements of an array before sorting\n");
	Display(A,SIZE);
	Heap(A,SIZE);
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

void Heap(int *p,int size)
{
	int i,temp;
	i=size/2-1;// calculating the index of last subtree parent
	for(;i>=0;i--)
	{
		Heapify(p,i,size);
	}
	for(i=size-1;i>=0;i--)
	{
		temp=p[0];
		p[0]=p[i];
		p[i]=temp;
		Heapify(p,0,i);
	}
}

void Heapify(int *p,int parent,int size)
{
	int li,ri,large=parent,temp;
	// li represents the left child index
	// ri represents the right child index
	// large repredents the index of largest among the three
	li=2*parent+1;  // calculating left child index
	ri=2*parent+2; // calcuylating right child index
	if(li < size && p[li]>p[parent])
		large=li;
	if(ri < size && p[ri] > p[large])
		large=ri;
	if(large !=parent) // if parent is not the largest of three then swap parent with largest child
	{
		temp=p[parent];
		p[parent]=p[large];
		p[large]=temp;
		Heapify(p,large,size);
	}
}

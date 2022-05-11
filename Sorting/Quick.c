#include<stdio.h>
#include<stdlib.h>

void Input(int *,int);
void Display(int *,int);
void Quick(int *,int,int);
int Partition(int * ,int,int);


int main()
{
	int a[1000000];
	Input(a,1000000);
	printf("elements before sorting\n");
	Display(a,1000000);
	Quick(a,0,999999);
	printf("elements after sorting\n");
	Display(a,1000000);
}

void Input(int *p,int size)
{	int i;
	srand(getpid());
	for(i=0;i<size;i++)
		p[i]=rand()%1000001;
}
void Display(int *p,int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",p[i]);
	printf("\n");
}

void Quick(int *p,int low,int high)
{
	int pindex;
	if(low < high)
	{
		pindex=Partition(p,low,high);
		Quick(p,low,pindex-1);  // left arr
		Quick(p,pindex+1,high); // right arr
	}
}


int Partition(int *p,int low,int high)
{
	int temp,pivotval,l,h;
	pivotval=p[low];   // taking left most ele of an aee as pivot val
	l=low;
	h=high;

	while(l<h)
	{
		while(l<=high && p[l]<=pivotval)
			l++;
		while(h>=low && p[h]>pivotval)
			h--;
		if(l<h)
		{
			temp=p[l];
			p[l]=p[h];
			p[h]=temp;
		}

	}

	// swaping between the pivot val and val i  h index
	p[low]=p[h];
	p[h]=pivotval;
	return h;
}

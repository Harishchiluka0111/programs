#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
void Input(int *,int);
void Display(int *,int);
void Merge(int *,int);
void Partition(int *,int ,int);
void Mergearr(int *,int,int,int);
int main()
{
	int A[SIZE];
	Input(A,SIZE);
	printf("elements of an array before sorting\n");
	Display(A,SIZE);
	Merge(A,SIZE);
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

void Merge(int *p,int size)
{
	Partition(p,0,size-1);
}

void Partition(int *p,int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		Partition(p,low,mid);// left arra
		Partition(p,mid+1,high);//right arra
		Mergearr(p,low,mid,high);
	
	}
}

void Mergearr(int *p,int low,int mid,int high)
{
	int li,ri,i;
	int temp[SIZE];
	li=low;
	ri=mid+1;
	i=li;
	while(li<=mid && ri<=high)
	{
		if(p[li] < p[ri])
		{
			temp[i]=p[li];
			li++;
		}
		else{
			temp[i]=p[ri];
			ri++;
		}
		i++;
	}
	if(li>mid)// left arr is completely copied, so append the left over elementsof right arr  to temp arr
	{
		for(;ri<=high;ri++,i++)
			temp[i]=p[ri];
	}
	else
	{
		// right arr is completely copied so append the left over eles of left arr to temp arr
		 for(;li<=mid;li++,i++)
			 temp[i]=p[li];
	}
	// updating from temp arr to actual arr
	for(i=low;i<=high;i++)
		p[i]=temp[i];
}

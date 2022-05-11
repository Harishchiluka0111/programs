#include<stdio.h>
#include<stdlib.h>


struct Employee
{
	int empid;
	char name[20];
	struct Employee *link;
};

struct Employee *Add(struct Employee *);
void Display(struct Employee *);
struct Employee *Del(struct Employee *);



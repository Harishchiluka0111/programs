#include<stdio.h>
#include<stdlib.h>

struct Person
{
	int age;
	char name[20];
	struct Person *prev,*link;
};

// prev to hold the address of previous node
// link to hold the address of next node
struct Person *Add_last(struct Person *);
void Display(struct Person *);
void RDisplay(struct Person *);
struct Person * Del_first(struct Person *);
struct Person * Dellast(struct Person *);
struct Person * Del_data(struct Person *);
struct Person *Add_beg(struct Person *);
struct Person *Reverse(struct Person *);


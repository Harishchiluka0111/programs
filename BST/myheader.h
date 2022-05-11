#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left,*right;
};


struct BST* insert(struct BST *,int );

void preorder(struct BST *);
void inorder(struct BST *);
void postorder(struct BST *);
struct BST* Search(struct BST *,int );

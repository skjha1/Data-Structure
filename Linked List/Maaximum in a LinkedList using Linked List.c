#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
	int i;
	struct Node *t,*last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	
	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}


int RMax(struct Node *p)
{
	int max=-32768;
	if(p!=NULL)
	{
		max=RMax(p->next);
		if(max>p->data)
		return max;
		else
		return p->data;
	}
	else
	{
		return max;
	}	  	
}


int main()
{
	int *A;
	int i,n;
	printf("Enter the number of elements: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	create(A,n);
	printf("The maximum elements in the linked list using the recursion is %d: \n",RMax(first));
}

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create1(int A[],int n)
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

void create2(int A[],int n)
{
	int i;
	struct Node *t,*last;
	second=(struct Node *)malloc(sizeof(struct Node));
	second->data=A[0];
	second->next=NULL;
	last=second;
	
	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}	
}

void display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void Merge(struct Node *p,struct Node *q)
{
	struct Node *last=NULL;
	if(p->data<q->data)
	{
		third=p;
		last=p;
		p=p->next;
		third->next=NULL;
	}
	else
	{
		third=q;
		last=q;
		q=q->next;
		third->next=NULL;
	}
	while(p && q)
	{
		if(p->data<q->data)
		{
			last->next=p;
			last=p;
			p=p->next;
			last->next=NULL;
		}
		else
		{
			last->next=q;
			last=q;
			q=q->next;
			last->next=NULL;
		}
	}
	if(p)
	last->next=p;
	if(q)
	last->next=q;
}


int main()
{
	int i,m,n;
	int *A,*B;
	printf("Enter the number of elements you want to input in the first linked list: \n");
	scanf("%d",&m);
	A=(int *)malloc(sizeof(int)*m);
	printf("Enter the elements: \n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Enter the number of elements you want to input in the second linked list: \n");
	scanf("%d",&n);
	B=(int *)malloc(sizeof(int)*n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&B[i]);
	}
	create1(A,m);
	create2(B,n);
	printf("First linked list\n");
	display(first);
	printf("Second linked list\n");
	display(second);
	printf("\n\n");
	printf("The Merged linked list is: \n");
	Merge(first,second);
	display(third);
}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define NULL 0
typedef struct node
{
	int profit;
	char job[2];
	int deadline;
	int visited;
	struct node *next;
}node;
node *first=NULL;
node *createNode(int x,int y,char z[2])
{
	node *pnode;
	pnode = (node*)malloc(sizeof(node));
	if(pnode==NULL)
		return NULL;
	pnode->profit=x;
	pnode->deadline=y;
	strcpy(pnode->job,z);
	pnode->next=NULL;
	pnode->visited=0;
	return pnode;
}
void insertAtBegg()
{
	int n1,n2;
	char s[2];
	printf("\nEnter the profit");
	scanf("%d",&n1);
	printf("\nEnter the job");
	scanf("%s",&s);
	printf("\nEnter the deadline");
	scanf("%d",&n2);
	node *pnode;
	pnode=createNode(n1,n2,s);
	if(pnode==NULL)
	{
		printf("memory overflow");
		return;
	}

	if(first==NULL)
	{
		first=pnode;
	}
	else
	{
		pnode->next=first;
		first=pnode;
	}
	printf("\n Node Inserted");
}
void display()
{
	node *current=first;

	while(current!=NULL)
	{
		printf(" %d ",current->profit);
		printf(" %s",current->job);
		printf(" %d ",current->deadline);
		printf("\n");
		current=current->next;

	}

}
int size()
{
int count=0;
node *current=first;
while(current->next!=NULL)
{
	++count;
	current=current->next;
}
return count+1;
}


void sort()
{
	node *current=first,*current1=NULL;
	int temp;
	char s[2];
	int p,d;
	while(current!=NULL)
	{
		current1=current->next;
		while(current1!=NULL)
		{

		if(current->profit < current1->profit)
		{
			//temp   , temp=A
			strcpy(s,current->job);
			p=current->profit;
			d=current->deadline;
			//a=b
			strcpy(current->job,current1->job);
			current->profit=current1->profit;
			current->deadline=current1->deadline;
			//b=temp
			strcpy(current1->job,s);
			current1->profit=p;
			current1->deadline=d;

		}
		current1=current1->next;

		}
		current=current->next;
	 }
}
int maxDeadline()
{
	int max=0;
	node *current=first;
	while(current!=NULL)
	{
		if(max<current->deadline)
		{
			max=current->deadline;
		}
		current=current->next;
	}
	return max;
}
void jobs()
{
	node *current=first;
	int n=maxDeadline()+1;
	int arr[100];
	int cj=0;
	for(int i=0;i<n;i++)
	{
		arr[i]=0;
	}

	printf("\n main");
	while(current!=NULL)
	{

		if(current->deadline < n)
		{
			if(arr[current->deadline]==0)
			{

				arr[current->deadline]=1;
				current->visited=1;
			}
		}
		current=current->next;
	}

	for(i=1;i<n;i++)
	{
		if(arr[i]==0)
		{
			cj++;
		}
	}
	node *current1=first;
		while(current1!=NULL)
		{
			if(cj>0)
			{
				if(current1->visited==0)
				{
					current1->visited=1;
					cj--;
				}
			}

			current1=current1->next;
		}

	node *current2=first;
	while(current2!=NULL)
	{

		if(current2->visited==1)
		{
			printf("\n");
			printf("%s ",current2->job);
		}
		current2=current2->next;
	}

}
void main()
{


int n;
int arr[100];
printf("\n How many jobs you want to do");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
	insertAtBegg();
}
printf("\n %d",maxDeadline())   ;
printf("\n");
sort();
display();
printf("\n");
jobs();
getch();
}


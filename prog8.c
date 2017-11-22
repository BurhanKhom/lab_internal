#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	char ssn[20], name[20], dept[20], desg[20];
	int sal;
	long mob;
	struct node *next;
}*first=NULL;

struct node *create()
{
	struct node *new;
	new=(struct node *) malloc(sizeof(struct node));

	if(new==NULL)
	{
		printf("Memory couldn't be allocated!\n");
		return NULL;
	}
	printf("Name : ");
	scanf("%s", new->name);
	printf("SSN : ");
	scanf("%s", new->ssn);
	printf("Dept : ");
	scanf("%s", new->dept);
	printf("Desg : ");
	scanf("%s", new->desg);
	printf("Salary : ");
	scanf("%d", &new->sal);
	printf("Phone : ");
	scanf("%ld", &new->mob);
	new->prev=NULL;
	new->next=NULL;

	return new;
}
void insertEnd(struct node *new)
{
	struct node *temp;
	temp=first;
	if(temp==NULL)
	{
		first=new;
		return;
	}
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new;
	new->prev=temp;
}
void createList()
{
	struct node *new;
	int n, i;
	printf("Enter the number of employees : ");
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		printf("Enter the details of employee %d\n", i);
		new=create();
		insertEnd(new);
	}
}
void deleteEnd()
{
	struct node *temp;
	temp=first;
	if(temp==NULL)
	{
		printf("List is Empty!\n");
		return;
	}
	if(temp->next==NULL)
	{
		printf("The deleted employee's SSN is : %s\n", temp->ssn);
		first=NULL;
		free(temp);
		return;
	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		printf("The deleted employee's SSN is : %s\n", temp->ssn);
		temp->prev->next=NULL;
		free(temp);
		
	}
}
void insertFront(struct node *new)
{
	struct node *temp;
	temp=first;
	if(temp==NULL)
	{
		first=new;
		return;
	}

	new->next=first;
	first->prev=new;
	first=new;
}
void deleteFront()
{
	struct node *temp;
	temp=first;
	if(temp==NULL)
	{
		printf("List is Empty!\n");
		return;
	}
	if(temp->next==NULL)
	{
		printf("The deleted employee's SSN is : %s\n", temp->ssn);
		first=NULL;
		free(temp);
	}
	else
	{
		printf("The deleted employee's SSN is : %s\n", temp->ssn);
		first=temp->next;
		first->prev=NULL;
		free(temp);
	}
}
void display()
{
	struct node *temp;
	temp=first;
	if(temp==NULL)
	{
		printf("List is empty!\n");
		return;
	}
	int count=0;
	while(temp!=NULL)
	{
		printf("Name        : %s\n", temp->name);
		printf("SSN         : %s\n", temp->ssn);
		printf("Department  : %s\n", temp->dept);
		printf("Designation : %s\n", temp->desg);
		printf("Salary      : %d\n", temp->sal);
		printf("Phone No.   : %ld\n", temp->mob);
		count++;
		temp=temp->next;
	}
	printf("The total no. of employees are : %d\n", count);
}
int main()
{
	int ch;
	struct node *new;
	while(1)
	{
		printf("Doubly Linked List Operations\n");
		printf("1.Create\n2.Display\n3.Insert End\n4.Delete End\n5.Insert Front\n6.Delete Front\n7.Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : createList();
					 break;
			case 2 : display();
					 break;
			case 3 : new=create();
					 insertEnd(new);
					 break;
			case 4 : deleteEnd();
					 break;
			case 5 : new=create();
					 insertFront(new);
					 break;
			case 6 : deleteFront();
					 break;
			case 7 : return 0; 
		}
	}
}























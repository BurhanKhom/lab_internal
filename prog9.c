#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int c, x, y, z;
	struct node *next;	
};
void insertEnd(struct node *head, struct node *new)
{
	struct node *temp;
	temp=head->next;
	if(head->next==head)
	{
		head->next=new;
		new->next=head;
		return;
	}
	while(temp->next!=head)
		temp=temp->next;
	temp->next=new;
	new->next=head;
}
void input(struct node *head)
{
	int c;
	
	while(1)
	{
		struct node *new = (struct node *) malloc(sizeof(struct node));
		printf("Enter Coefficient : ");
		scanf("%d", &c);
		if(c==0)
			break;
		new->c=c;
		printf("Enter Power of x : ");
		scanf("%d", &new->x);
		printf("Enter Power of y : ");
		scanf("%d", &new->y);
		printf("Enter Power of z : ");
		scanf("%d", &new->z);
		insertEnd(head, new);
	}
}
int polyEval(struct node * head, int x, int y, int z)
{
	int sum;
	struct node *temp = head->next;
	while(temp!=head)
	{
		sum=sum+(temp->c * pow(x, temp->x) * pow(y, temp->y) * pow(z, temp->z));
		temp=temp->next;
	}
	return sum;
}
void display(struct node *head)
{
	struct node *temp = head->next;
	while(temp!=head)
	{
		printf("%d(x)^%d(y)^%d(z)^%d\n", temp->c, temp->x, temp->y, temp->z);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	int x, y, z;
	struct node *head = (struct node *) malloc(sizeof(struct node));
	head->next=head;
	input(head);
	printf("Entered Polynomial is :");
	display(head);
	printf("Enter the values of x, y and z : ");
	scanf("%d%d%d", &x, &y, &z);
	printf("\nResult = %d\n", polyEval(head, x, y, z));
	return 0;
}
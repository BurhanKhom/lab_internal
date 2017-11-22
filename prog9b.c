#include<stdio.h>
#include<stdlib.h>
struct node
{
	int c, x, y, z;
	struct node *next;	
};
void insertEnd(struct node *head, int c, int x, int y, int z)
{
	struct node *temp, *new;
	new=(struct node *) malloc(sizeof(struct node));
	new->c=c;
	new->x=x;
	new->y=y;
	new->z=z;

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
	int c, x, y, z;
	
	while(1)
	{
		printf("Enter Coefficient : ");
		scanf("%d", &c);
		if(c==0)
			break;
		printf("Enter Power of x : ");
		scanf("%d", &x);
		printf("Enter Power of y : ");
		scanf("%d", &y);
		printf("Enter Power of z : ");
		scanf("%d", &z);
		insertEnd(head, c, x, y, z);
	}
}
void polyAdd(struct node *head1, struct node *head2, struct node *head3)
{
	struct node *t1, *t2;
	int flag;
	t1=head1->next;
	t2=head2->next;
	while(t1!=head1)
	{
		flag=0;
		t2=head2->next;
		while(t2!=head2)
		{
			if((t1->x == t2->x) && (t1->y== t2->y) && (t1->z == t2->z))
			{
				flag=1;
				insertEnd(head3, (t1->c+t2->c), t1->x, t1->y, t1->z);
				t2->c=0;
			}
				t2=t2->next;
		}
		if(!flag)
			insertEnd(head3, t1->c, t1->x, t1->y, t1->z);

		t1=t1->next;
	}
	t2=head2->next;
	while(t2!=head2)
	{	
		if(t2->c!=0)
		insertEnd(head3, t2->c, t2->x, t2->y, t2->z);
		t2=t2->next;
	}
}
void display(struct node *head)
{
	struct node *temp = head->next;
	while(temp!=head)
	{
		printf("%d(x)^%d(y)^%d(z)^%d+", temp->c, temp->x, temp->y, temp->z);
		temp=temp->next;
	}
	printf("0\n");
}
int main()
{
	struct node *head1, *head2, *head3;
	head1 = (struct node *) malloc(sizeof(struct node));
	head2 = (struct node *) malloc(sizeof(struct node));
	head3 = (struct node *) malloc(sizeof(struct node));
	head1->next=head1;
	head2->next=head2;
	head3->next=head3;
	printf("Enter Polynomial 1 : ");
	input(head1);
	display(head1);
	printf("Enter Polynomial 2 : ");
	input(head2);
	display(head2);
	polyAdd(head1, head2, head3);
	printf("Poly1+Poly2 = ");
	display(head3);
}
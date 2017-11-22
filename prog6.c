#include<stdio.h>
#define MAX 5
int q[MAX], front=-1, rear=-1;
void insertQueue(int elem)
{
	if((front==0 && rear==MAX-1) || front==rear+1)
	{
		printf("QUEUE FULL!\n");
		return;
	}
	if(rear==-1)
		front=rear=0;
	else if(rear==MAX-1)
		rear=0;
	else
		rear++;
	q[rear]=elem;
}
void deleteQueue()
{
	if(front==-1)
	{
		printf("QUEUE EMPTY!\n");
		return;
	}
	printf("The deleted elemet is : %d\n", q[front]);
	if(front==rear)
		front=rear=-1;
	else if(front==MAX-1)
		front=0;
	else
		front++;
}
void display()
{
	int i;
	if(front<=rear)
		for(i=front; i<=rear; i++)
			printf("%d ", q[i]);
	else
	{
		for(i=front; i<MAX; i++)
			printf("%d ", q[i]);
		for(i=0; i<=rear; i++)
			printf("%d ", q[i]);
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("Circular Queue Operations\n");
		printf("1.Insert\n2.Display\n3.Delete\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : printf("Enter the element to insert : ");
					 int x;
					 scanf("%d", &x);
					 insertQueue(x);
					 break;
			case 2 : display();
					 break;
			case 3 : deleteQueue();
					 break;
			case 4 : return 0;
		}
	}
}
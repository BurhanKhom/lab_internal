#include<stdio.h>
#include<stdlib.h>
struct node 
{
	char name[20], usn[10], branch[20];
	int sem;
	long mob;
	struct node *next;	
} *first=NULL;
struct node *create()
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	printf("Name : ");
	scanf("%s", new->name);
	printf("USN : ");
	scanf("%s", new->usn);
	printf("Branch : ");
	scanf("%s", new->branch);
	printf("Sem : ");
	scanf("%d", &new->sem);
	printf("Phone : ");
	scanf("%ld", &new->mob);
	new->next=NULL;
	return new;
}
void createList()
{
	int i, n;
	printf("Enter the number of students : ");
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		printf("Enter the details of student %d : \n", i);
		struct node *new = create();

		if(first==NULL)
			first=new;
		else
			{
				new->next=first;
				first=new;
			}
	}
}
void insertEnd()
{
	struct node *temp, *new;
	new=create();
	temp=first;
	if(first==NULL)
	{
		first=new;
		return;
	}
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new;	
}
void deleteEnd()
{
	struct node *temp, *prev;
	temp=first;
	if(first==NULL)
	{
		printf("List EMPTY!\n");
		return;
	}
	if(temp->next==NULL)
	{
		printf("The deleted student's USN is : %s\n", temp->usn);
		free(temp);
		first=NULL;
		return;
	}
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	printf("The deleted student's USN is : %s\n", temp->usn);
	prev->next=NULL;
	free(temp);
}
void insertFront()
{
	struct node *new;
	new=create();
	if(first==NULL)
	{
		first=new;
		return;	
	}
	new->next=first;
	first=new;
}
void deleteFront()
{
	struct node *temp;
	temp=first;
	if(temp==NULL)
	{
		printf("List EMPTY!\n");
		return;
	}
	if(temp->next==NULL)
	{
		printf("The deleted student's usn is : %s\n", temp->usn);
		first=NULL;
		free(temp);
		return;
	}
	printf("The deleted student's USN is %s\n", temp->usn);
	first=temp->next;
	free(temp);
}
void display()
{
	struct node *temp;
	temp=first;
	if(first==NULL)
	{
		printf("List EMPTY!\n");
		return;
	}	
	int count=0;
	while(temp!=NULL)
	{
		printf("NAME   : %s\n", temp->name);
		printf("USN    : %s\n", temp->usn);
		printf("BRANCH : %s\n", temp->branch);
		printf("SEM    : %d\n", temp->sem);
		printf("PHONE  : %ld\n\n", temp->mob);	
		temp=temp->next;
		count++;
	}
	printf("Total number of students = %d\n", count);

}
int main()
{
	int ch, ch2, ch3, ch4;
	while(1)
	{
		printf("Singly Linked List Operations\n");
		printf("1.Create\n2.Display\n3.Insert/Delete @ END\n4.Insert/Delete @ FRONT\n5.STACK\n6.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : createList();
					 break;
			case 2 : display();
					 break;
			case 3 : printf("1.Insert\n2.Delete\nEnter your choice : ");
					 scanf("%d", &ch2);
					switch(ch2)
					{
						case 1 : insertEnd();
								 break;
						case 2 : deleteEnd();
								 break;
					}
					break;
			case 4 : printf("1.Insert\n2.Delete\nEnter your choice : ");
					 scanf("%d", &ch3);
					switch(ch3)
					{
						case 1 : insertFront();
								 break;
						case 2 : deleteFront();
								 break;
					}
					break;
			case 5 : printf("1.PUSH\n2.POP\nEnter your choice : ");
					 scanf("%d", &ch4);
					 switch(ch4)
					 {
					 	case 1 : insertEnd();
					 			 break;
					 	case 2 : deleteFront();
					 			 break;
					 }
					 break;
			case 6 : return 0;
		}
	}
}
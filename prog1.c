#include<stdio.h>
int n;
void insert(int a[])
{
	int i, key, pos;
	printf("Enter the element to insert : ");
	scanf("%d", &key);
	printf("Enter the position : ");
	scanf("%d", &pos);
	for(i=n-1; i>=pos; i--)
		a[i+1]=a[i];
	a[pos]=key;
	n++;
}
void delete(int a[])
{
	int i, pos;
	printf("Enter the position of element to be deleted : ");
	scanf("%d", &pos);
	printf("Element deleted = %d\n", a[pos]);
	for(i=pos; i<n; i++)
		a[i]=a[i+1];
	n--;
}
void display(int a[])
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void create(int a[])
{
	int i;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	printf("Enter the elements : ");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
}
int main()
{
	int ch, a[20];
	while(1)
	{
		printf("Array Operations\n");
		printf("1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : create(a);
					 break;
			case 2 : display(a);
					 break;
			case 3 : insert(a);
					 break;
			case 4 : delete(a);
					 break;
			case 5 : return 0;
		}
	}
}
#include<stdio.h>
#define MAX 10
char s[MAX];
int top=-1;
void push(char elem)
{
	if(top==MAX-1)
		printf("Stack Overflow!\n");
	else
		s[++top]=elem;
}
void pop()
{
	if(top==-1)
		printf("Stack Underflow!\n");
	else
		printf("The element popped is : %c\n", s[top--]);
}
void checkPalindrome()
{
	int i=top, j, flag=0;
	for(j=0; j<i/2; j++, i--)
		if(s[j]!=s[i])
			{
				flag=1;
				break;
			}
	if(flag)
		printf("NOT PALINDROME!\n");
	else
		printf("PALINDROME!\n");
}
void display()
{
	int i;
	if(top==-1)
		{
			printf("Stack is Empty!\n");
			return;
		}
	for(i=top; i>=0; i--)
		printf("%c\n", s[i]);
}
int main()
{
	int ch;
	while(1)
	{
		printf("Stack operations\n");
		printf("1.Push\n2.Pop\n3.Display\n4.Check Palindrome\n5.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : printf("Enter the element to be pushed on to the Stack : ");
					 char x;
					 scanf("\n%c", &x);
					 push(x);
					 break;
		    case 2 : pop();
		    		 break;
		    case 3 : display();
		    		 break;
		    case 4 : checkPalindrome();
		    		 break;
		    case 5 : return 0;					
		}
	}
}
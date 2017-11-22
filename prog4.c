#include<stdio.h>
#define MAX 100
int s[100], top=-1;
void push(char c)
{
	if(top==MAX-1);
	else
		s[++top]=c;
}
char pop()
{	
	char del;
	if(top==-1);
	else
		del=s[top--];
	return del;
}
int isOperand(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^')
		return 0;
	else
		return 1;
}
int priority(int c)
{
	if(c=='^')
		return 99;
	else if(c=='*' || c=='/' || c=='%')
		return 9;
	else if(c=='+' || c=='-')
		return 1;
	else 
		return 0;
}
int main()
{
	int i, j=0;
	char infix[100], postfix[100];
	printf("Enter the infix expression : ");
	scanf("%s", infix);
	for(i=0; infix[i]!='\0'; i++)
	{
		char c = infix[i];

		if(c=='(')
			push(c);
		else if(c==')')
		{
			while(s[top]!='(')
				postfix[j++]=pop();
			top--;
		}
		else if(isOperand(c))
			postfix[j++]=c;
		else
		{
			if(priority(s[top]) >= priority(c))
				postfix[j++]=pop();
			push(c);
		}
	}
	while(top!=-1)
		postfix[j++]=pop();
	postfix[j]='\0';
	printf("%s\n", postfix);
}

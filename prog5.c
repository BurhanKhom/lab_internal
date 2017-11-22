#include<stdio.h>
#include<math.h>
#define MAX 100
int s[MAX], top=-1;
void push(int c)
{
	s[++top]=c;
}
int pop()
{
	return s[top--];
}
int operate(int op)
{
	int op2 = pop();
	int op1 = pop();

	switch(op)
	{
		case '+' : return op1+op2;
				   break;
		case '-' : return op1-op2;
				   break;
		case '*' : return op1*op2;
				   break;
		case '/' : return op1/op2;
				   break;
		case '^' : return pow(op1, op2);
				   break;
		case '%' : return fmod(op1, op2);
	}
}
int isOperand(int c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%')
		return 0;
	else
		return 1;
}
int main()
{
	int i;
	char postfix[100];
	printf("Enter the postfix expression : ");
	scanf("%s", postfix);
	for(i=0; postfix[i]!='\0'; i++)
	{
		char c = postfix[i];

		if(isOperand(c))
			push(c-'0');
		else
			push(operate(c));
	}
	printf("Result = %d\n", s[top]);
}
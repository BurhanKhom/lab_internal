/*******************************************
DEPTH FIRST SEARCH AND BREADTH FIRST SEARCH
********************************************/
#include<stdio.h>
int n, visited[20]={0}, g[20][20], s[20], q[20], top=-1, front=0, rear=-1;
void push(int x) //ignore overflow
{
	s[++top]=x;
}
int pop() //ignore underflow
{	
	return s[top--];
}
void enq(int x) //ignore queue full
{
	q[++rear]=x;
}
int deq() //ignore queue empty
{
	return q[front++];
}
void dfs(int c)
{
	int i;
	push(c);
	visited[c]=1;
	//USING STACK
	while(top!=-1)
	{
		int x = pop();
		printf("%d ", x);
		for(i=0; i<n; i++)
			if(!visited[i] && g[c][i]==1)
				dfs(i);
	}
	//USING RECURSION
	/*for(i=0; i<n; i++)
		if(!visited[i])
			dfs(i);*/
}
//USING QUEUE
void bfs(int c)
{
	int i;
	for(i=0; i<n; i++)
		if(!visited[i] && g[c][i]==1)
			enq(i);
	if(front<=rear)
	{	
		visited[q[front]]=1;
		printf("%d ", q[front]);
		bfs(deq());
	}
}
int main()
{
	printf("Enter no. of cities : ");
	scanf("%d", &n);
	printf("Enter adjacency matrix : ");
	int i, j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &g[i][j]);
	printf("Enter source city : ");
	int c;
	scanf("%d", &c);
	dfs(c);
	printf("\n");
	for(i=0; i<20; i++)
		visited[i]=0;
	bfs(c);
}
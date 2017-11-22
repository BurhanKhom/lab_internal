#include<stdio.h>
void toh(int n, char src, char temp, char dest)
{	
	if(n==1)
	{
		printf("Move disk %d from %c to %c\n", n, src, dest);
		return;
	}

	toh(n-1, src, dest, temp);

	printf("Move disk %d from %c to %c\n", n, src, dest);

	toh(n-1, temp, src, dest);
}
int main()
{
	int n;
	printf("Enter the number of disks : ");
	scanf("%d", &n);
	toh(n, 'A', 'B', 'C');
	return 0;
}
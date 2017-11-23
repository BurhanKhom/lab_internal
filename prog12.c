#include<stdio.h>
#define MAX 20
int ht[MAX]={0}, f[MAX], i=0;
void linear(int k, int key)
{
	int l = k%MAX;
	if(ht[l]==0)
		ht[l]=key;
	else
		linear(k+1, key);
}
int main()
{
	FILE *fp = fopen("data.txt", "r");
	while(fscanf(fp, "%d", &f[i]) != EOF)
		linear(f[i], f[i++]);
	for(i=0; i<MAX; i++)
		printf("H[%d] = %d\n", i, ht[i]);
}
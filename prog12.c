#include<stdio.h>
#define MAX 20
int ht[MAX]={0}, f;
void linear(int k, int key)
{
	if(ht[k%MAX]==0)
		ht[k%MAX]=key;
	else
		linear(k+1, key);
}
int main()
{
	FILE *fp = fopen("data.txt", "r");
	while(fscanf(fp, "%d", &f) != EOF)
		linear(f, f);
	for(int i=0; i<MAX; i++)
		printf("H[%d] = %d\n", i, ht[i]);
}

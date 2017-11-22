#include<stdio.h>
#include<string.h>
void read(char s[], char pat[], char rep[])
{
	printf("Enter the main string : ");
	gets(s);
	printf("Enter the pattern string : ");
	gets(pat);
	printf("Enter the replace string : ");
	gets(rep);
}
void operate(char s[], char pat[], char rep[])
{
	int i, j, k, patLen=0;
	for(i=0; pat[i]!='\0'; i++)
		patLen++;
	pat[patLen]='\0';
	i=0;
	while(s[i]!='\0')
	{
		j=0;
		k=i;
		while((s[k]==pat[j]) && pat[j]!='\0')
		{
			j++;
			k++;
		}
		if(j==patLen)
		{
			for(j=0, k=i; pat[j]!='\0'; j++, k++)
				s[k]=rep[j];
		}
		i++;
	}
	printf("%s\n", s);
}
int main()
{
	char s[20], pat[20], rep[20];
	read(s, pat, rep);
	operate(s, pat, rep);
	return 0;
}


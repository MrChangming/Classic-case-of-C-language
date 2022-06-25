#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int skip[256];

void table(char *key)
{
	int k,n;
	n = strlen(key);
	for(k = 0;k <= 255;k++)
		skip[k] = n;
	for(k = 0;k < n - 1;k++)
		skip[key[k]] = n - k - 1;
}

void substring(char *text,char *tmp,int s ,int e)
{
	int i,j;
	for(i = s,j = 0;i <=e;i++,j++)
	{
		tmp[j] = text[i];
		tmp[j] = '\0';
	}
}

int search(int p,char* input,char *key)
{
	int i,m,n;
	char tmp[80] = {'\0'};
	m = strlen(input);
	n = strlen(key);
	while(p < m)
	{
		substring(input,tmp,p - n + 1,p);
		if(!strcmp(tmp,key))
			return p - n + 1;
		p += skip[input[p]];
	}
	return -1;
}

int main()
{
	char str_input[80];
	char str_key[80];
	char tmp[80] = {'\0'};
	int m,n,p;
	printf("ÇëÊäÈë×Ó´®£º");
	gets(str_input);
	printf("ÇëÊäÈëËÑË÷µÄ¹Ø¼ü×Ö£º");
	gets(str_key);
	m = strlen(str_input);
	n = strlen(str_key);
	table(str_key);
	p = search(n - 1,str_input,str_key);
	while(p != -1)
		{
			substring(str_input,tmp,p,m);
			printf("%s\n",tmp);
			p = search(p + n + 1,str_input,str_key);
		}
	printf("\n");
	return 0;
}




#include<stdio.h>
#define L 1000
#define N L/4+1

//L为位数，N是array长度

void add(int *a,int *b,int *c)
{
	int i,carry = 0;
	for(i = N + 1;i >= 0;i--)
	{
		c[i] = a[i] + b[i] + carry;
		if(c[i] < 10000)
		carry = 0;
		else
		{
			c[i] = c[i] - 10000;
			carry = 1;
		}
	}
}

void sub(int *a,int *b,int *c)
{
	int i,borrow = 0;
	for(i = N + 1;i >=0;i--)
	{
		c[i] = a[i] - b[i] - borrow;
		if(c[i] >= 0)
		borrow  =0;
		else
		{
			c[i] = c[i] + 10000;
			borrow = 1;
		}
	}
}

void div(int *a,int b,int *c)
{
	int i,tmp,remain = 0;
	for(i = 0;i < N;i++)
	{
		tmp = a[i] + remain;
		c[i] = tmp /b;
		remain = (tmp % b) * 10000;
	}
} 

int main()
{
	int s[N + 3] = {0};
	int w[N + 3] = {0};
	int v[N + 3] = {0};
	int q[N + 3] = {0};
	int n = (int)(L/1.39793 + 1);
	int k;
	w[0] = 16*5;
	v[0] = 4*239;
	for(k = 1;k <= n;k++)
	{
		div(w,25,w);
		div(v,239,v);
		div(v,239,v);
		sub(w,v,q);
		div(q,2 * k -1,q);
		if(k % 2)
			add(s,q,s);
		else
			sub(s,q,s);
	}
	printf("%d",s[0]);
	for(k = 1;k < N;k++)
		printf("%04d",s[k]);
	printf("\n");
	while(1)getchar();
	return 0;
}

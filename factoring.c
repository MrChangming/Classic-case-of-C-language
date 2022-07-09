//不用质数表
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,n;
	printf("请输入整数");
	scanf("%d",&n);
	printf("%d = ",n);
	for(i = 2;i * i <= n;)
	{
		if(n % i == 0)
		{
			printf("%d *",i);
			n /= i;
		}
		else
		{
			i++;
		}
	}
	printf("%d\n",n);
	while(1)getchar();
	return 0;
}

////使用质数表

//#include<stdio.h>
//#include<stdlib.h>
//#define N 1000 
//
//int prime(int* pNum)
//{
//	int i,j;
//	int prime[N + 1];
//	for(i = 2;i <= N;i++)
//		prime[i] =1;
//	for(i = 2;i * i <= N;i++)
//	{
//		if(prime[i] == 1)
//		{
//			for(j = 2 * i;j <= N;j++)
//			{
//				if(j % i == 0)
//					prime[j] = 0;
//			}
//		}
//	}
//	for(i = 2,j = 0;i < N;i++)
//	{
//		if(prime[i] == 1)
//			pNum[j++] =i;
//	}
//	return j;
//}
//
//void factor(int *table,int num)
//{
//	int i;
//	for(i = 0;table[i] * table[i] <= num;)
//	{
//		if(num % table[i] == 0)
//		{
//			printf("%d *",table[i]);
//			num /= table[i];
//		}
//		else
//			i++;
//	}
//	printf("%d\n",num);
//}
//
//int main()
//{
//	int ptable[N + 1] ={0};
//	int count,i,temp;
//	count = prime(ptable);
//	printf("请输入数:");
//	scanf("%d",&temp);
//	factor(ptable,temp);
//	printf("\n");
//	while(1)getchar();
//	return 0;
//}

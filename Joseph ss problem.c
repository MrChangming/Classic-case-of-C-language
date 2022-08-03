#include<stdio.h> 
#include<stdlib.h>
#define N 41
#define M 3

int main(void){
	int man[N] = {0};
	int count = 1;
	int i = 0,pos = -1;
	int alive = 0;
	
	while(count <= N){
		do{
			pos = (pos + 1) % N;//环状处理
			if((man[pos]) == 0)
				i++;
				
				if(i == M){
					i = 0;
					break;
				}			
			}while(1);
			man[pos] = count;
			count++;
		}
		printf("约瑟夫排列：\n");
		for(i = 0;i < N; i++)
			printf("%d   ", man[i]);
		printf("\n\n您想要救多少人？");
		scanf("%d", &alive);
		printf("\nL表示这%d人要放的位置：\n", alive);
		for(i = 0;i < N;i++) {
			if(man[i] > (N - alive)) printf("L");
			else printf("*");
			if((i + 1) % 5 == 0) printf(" ");
		}
	printf("\n");
	return 0;
}





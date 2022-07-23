#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define WON 0
#define LOST 1
#define CONTINUE 2

int rollDice(){
	return (rand() % 6) + (rand() % 6) + 2;
}

int main(void){
	int firstRoll;
	int gameStatus = CONTINUE;
	int die1,die2,sumOfDice;
	int firstPoint = 0;
	char c;
	
	srand(time(0));
	printf("Craps赌博游戏，按Enter键开始游戏****");
	while(1){
		getchar();
		if(firstRoll){
			sumOfDice = rollDice();
			printf("\n玩家投掷出的点数和：%d\n", sumOfDice);
			switch(sumOfDice){
				case 7:case 11:
					gameStatus = WON;
					break;
				case 2:case 3:case 12:
					gameStatus = LOST;
					break; 
				default:
					firstRoll = 0;
					gameStatus = CONTINUE;
					firstPoint = sumOfDice;
					break; 
			}
		}
		else{
			sumOfDice = rollDice();
			printf("\n玩家掷出的点数和：%d\n", sumOfDice); 
			if(sumOfDice == firstPoint)
				gameStatus = WON;
			else if(sumOfDice == 7)
				gameStatus = LOST;
			
		}
		if(gameStatus == CONTINUE)
			puts("未分胜负，再掷一次****\n");
		else{
			if(gameStatus == WON)
				puts("玩家胜");
			else
				puts("玩家输"); 
		printf("再玩一次？");
		scanf("%c", &c);
		if(c == 'n'){
			puts("游戏结束");
			break; 
		}
		firstRoll = 1;
		}
	}
	return 0;
}










 

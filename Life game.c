#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXROW 10
#define MAXCOL 25
#define DEAD 0
#define ALIVE 1
int map[MAXROW][MAXCOL],newmap[MAXROW][MAXCOL];

void init()
{
	int row,col;
	for(row = 0;row < MAXROW;row++)
		for(col = 0;col < MAXCOL;col++)
			map[row][col] = DEAD;
	puts("Game of life Program");
	puts("Enter x,y where x,y is living cell");
	printf("0 <= x <= %d,0 <= y <= %d\n",MAXROW - 1,MAXCOL - 1);
	puts("Terminate with x,y = -1,-1");
	while(1)
	{
		scanf("%d %d",&row ,&col);
		if(0 <= row && row < MAXROW && 0 <=col && col < MAXCOL)
		{	
			map[row][col] = ALIVE;
		}
		else if (row == -1|| col == -1)
			break;
		else
			printf("(x,y)exceeds map ranage!");
	} 
}

int neighbors(int row,int col)
{
	int count = 0,c,r;
	for(r = row - 1;r <= row + 1;r++){
		for(c = col - 1;c <= col + 1;c++)
		{
			if(r < 0 || r >= MAXROW || c < 0 || c >= MAXCOL)
				continue;
			if(map[r][c] == ALIVE)
				count++;
		}
		if(map[row][col] == ALIVE)
			count--;
		return count;
	}
}

void outputMap()
{
	int row,col;
	printf("\n\n Game of life cell status\n");
	for(row = 0;row < MAXROW ;row++)
	{
		for(col = 0;col < MAXROW;col++)
		{
			if(map[row][col] == ALIVE)
				putchar('#');
			else
				putchar('-');
		}
	}
}

void copyMap()
{
	int row,col;
	for(row = 0;row < MAXROW;row++)
	{
		for(col = 0;col < MAXROW;col++)
		{
			map[row][col] = newmap[row][col];
		}
	}
}

int main()
{
	int row,col;
	char ans;
	init();
	while(1)
	{
		printf("\n\n Game of life cell status\n");
		for(row = 0;row < MAXROW ;row++)
		{
			for(col = 0;col < MAXROW;col++)
			{
				if(map[row][col] == ALIVE)
					putchar('#');
				else
					putchar('-');
			}
		}
		for(row = 0;row < MAXROW;row++)
		{
			for(col = 0;col < MAXROW;col++)
			{
				switch(neighbors(row,col))
				{
				case 0:
				case 1:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
					newmap[row][col] = DEAD;
					break;
				case 2:
					newmap[row][col] = map[row][col];
					break;
				case 3:
					newmap[row][col] = ALIVE;
					break;
				}
			}
		}
		copyMap();
		printf("\nnContine next Generation ?");
		getchar();
		ans = toupper(getchar());
		if(ans != 'Y')
			break;
	}
	while(1)getchar();
	return 0;
}



#include<stdio.h>
#include<stdlib.h>

int postfix(char*);
int priority(char);

int main(){
	char input[80];
	printf("������������ʽ");
	scanf("%s", input);
	postfix(input);
	
	return 0;
}

int postfix(char* infix){
	int i = 0,top = 0;
	char stack[80] = {"\0"};
	char op;
	
	while(1){
		op = infix[i];
		switch(op){
			case'\0':
				while(top > 0){
					printf("%c", stack[top]);
					top--;
				}
			printf("\n");
			return 0;
			//�������Ӷ�
			case '(':
				if(top < (sizeof(stack) / sizeof(char))){
					top++;
					stack[top] = op;
				} 
				break;
				case'+':case'-':case'*':case'/':
					while(priority(stack[top]) >= priority(op)){
						printf("%c", stack[top]);
						top--;
					}
				//����ѵ�
				if(top < (sizeof(stack) / sizeof(char))) {
					top++;
					stack[top] = op;
					
				}
				break;
				//����)�����(
				case ')':
				while(stack[top] != '(') {
					printf("%c", stack[top]);
					top--;
				}
				top--;//�����(
				break; 
		}
		i++;
	}
}

int priority(char op){
	int p;
	switch(op){
		case '+':case'-':
			p = 1;
			break;
		case'*':case'/':
			p = 2;
			break;
		default:
			p = 0;
			break;
	}
	return p;
}


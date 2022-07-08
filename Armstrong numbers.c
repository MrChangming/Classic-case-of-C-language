#include<stdio.h>
#include<time.h>
#include<math.h>

int main(){
	int a, b, c;
	int input;
	printf("Ñ°ÕÒAmstrongÊı£º\n");
	for(input = 100; input <= 999; input++){
		a = input / 100;
		b = (input % 100) / 10;
		c = input % 10;
		if (a * a * a + b * b * b + c * c * c == input)
			printf("%2d \n", input);
	}
	printf("\n");
	return 0;
}

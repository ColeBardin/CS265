#include <stdio.h>
#include <stdlib.h>

int main(){
	double sub, tax, tip = 0;
	
	printf("Enter your subtotal amount: $");
	if (scanf("%lf", &sub) != 1) {
		fprintf(stderr, "ERROR: scanf did not match one double for subtotal\n");
		return EXIT_FAILURE;
	}

	tax=0.07*sub;
	tip=0.22*sub;

	printf("Item subtotal: $%.2lf\n", sub);
	printf("7 Percent Tax: $%.2lf\n", tax);
	printf("22 Percent Tip: $%.2lf\n", tip);
	printf("User total: $%.2lf\n", sub+tip+tax);
	return 0;
}

#include <stdio.h>

void int2string(int n, char answer[]){
	int ndig=0;
	int buff[11];
	/* Do once and repeat if condition is true */
	do {
		/* Save ones digit to buffer */
		buff[ndig] = n%10;
		/* Integer divide number by 10 */
		n/=10;
		/* Increment digit counter */
		ndig++;
	} while ( n != 0 ); /* Repeat while n != 0 */

	/* Reverse order of buffer and store in answer string */
	for (int i=0; i<ndig; i++) {
		answer[i]= (char)buff[ndig-i-1] + '0'; /* Convert int numbers to appropriate chars */
	}
	/* Add nullchar to end of char array */
	answer[ndig]='\0';
	return;
}

int main(){
	char answer[11];
	int n;

	printf("Enter integers no larger than 10 digits\n");
	/* Read from stdin until EOF */	
	while ( 1 ) {
		/* Scan for integers, ends loop on EOF */
		if ( scanf("%d", &n) < 1 ) break;

		/* Pass the int to our function */
		int2string(n, answer);
		/* Prints the string function to STDOUT */
		printf("In String form: %s\n", answer);
	}
	return 0;
}

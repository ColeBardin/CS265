#include <stdio.h>

/* Base struct from example */
struct time {
	int hr;
	int min;
	int sec;
};

/* sec2hms function:
Given number of seconds since midnight, calculates the time of day
Expected to not get number of seconds that would overflow to next day
Retruns struct time object
Parameters:
	int secs: 	Number of seconds since midnight
*/
struct time sec2hms( int secs ){
	/* Create temporary struct time */
	struct time temp;
	/* Divide by 3600 to get number of hours */
	temp.hr = secs / 3600;
	/* Subtract hours from count */
	secs = secs % 3600;
	/* Divide by 60 to get number of minutes */
	temp.min = secs / 60;
	/* Subtract minutes from count, leaves number of seconds */
	temp.sec = secs % 60;
	/* Return the address of the struct */
	return temp;
}

int main(){
	struct time t1;

	t1 = sec2hms(3600);
	printf("HR: %d\nMin: %d\nSec: %d\n\n", t1.hr, t1.min, t1.sec);

	t1 = sec2hms(2*3600 + 5*60);
	printf("HR: %d\nMin: %d\nSec: %d\n\n", t1.hr, t1.min, t1.sec);

	t1 = sec2hms(10*3600 + 45*60 + 10);
	printf("HR: %d\nMin: %d\nSec: %d\n\n", t1.hr, t1.min, t1.sec);
	return 0;
}

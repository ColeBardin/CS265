#include <stdio.h>
#include <stddef.h>

/* Performs Binary Search on integer array.
If target is found, returns its index.
If target is not found, returns size_t n 
Parameters:
	int *arr: 		array of integers to search
	size_t n: 		length of arr as size_t
	int target: 	target value of binary search */
size_t binSearch(int *arr, size_t n, int target){
	int index;
	/* Iterate through each element of the array */
	for (index=0; index<n; index++){
		/* If the current element is the target, return index */
		if (arr[index] == target) return index;
	}
	/* If target is not found, return n for failure */
	return n;
}

/* Computes statistics on array of doubles.
Stores min, max and mean in double pointers provided to it 
Parameters:
	double *arr: 	array of doubles to use for calculations
	size_t n: 		length of arr as size_t
	double *min: 	pointer to double to store minimum value in arr
	double *max: 	pointer to double to store maximum value in arr
	double *mean: 	pointer to double to store mean of values in arr */
void arrStats(double *arr, size_t n, double *min, double *max, double *mean) {
	int index;
	double num;

	/* Set min, max and mean to be first element *arr = arr[0] */
	*min=*arr; 
	*max=*arr; 
	*mean=*arr;

	/* Iterate through the remaining elements */
	for (index=1; index<n; index++) {
		/* Parse current element *(arr + index) = arr[index] */
		num = *(arr + index);
		/* Compare current val to min and max */
		if ( num > *max ) *max = num;
		if ( num < *min ) *min = num;
		/* Sum all elements to into mean variable */
		*mean += num;
	}
	/* Calculate mean */
	*mean /= (double)n;
	return;
}

/* Searches an array of integers of size n for a target integer.
If found, returns poiner to target value in arr.
If not found, returns NULL 
Parameters:
	int *arr: 		array of integers to search
	size_t n: 		length of arr as size_t
	int target: 	target value to search for in arr */
int *arrFind(int *arr, size_t n, int target) {
	int index, num;
	/* Iterate through each element of array */
	for (index=0; index<n; index++){
		/* Get current element. *(arr+index) = arr[index] */
		num = *(arr + index);
		/* If current value matches target */
		if (target == num) {
			/* Return address target value */
			return arr + index;
		}
	}
	/* If no matches are found, return NULL */
	return NULL;
}

int main(){
	size_t n = 10;
	double arrd[] = {10,20,30,40,50,60,70,80,90,100};
	int arri[] = {10,20,30,40,50,60,70,80,90,100};
	int target = 40;
	int invalid = 110;
	double min, max, mean;

	printf("binSearch valid: %zu\n", binSearch(arri, n, target));
	printf("binSearch invalid: %zu\n", binSearch(arri, n, invalid));
	arrStats(arrd, n, &min, &max, &mean);
	printf("arrStats: min: %lf max: %lf mean: %lf\n", min, max, mean);
	int *num = (arrFind(arri, n, target));
	if (num != NULL) printf("arrFind valid: %d\n", *num);
	num = (arrFind(arri, n, invalid));
	if (num != NULL) printf("arrFind valid: %d\n", *num);
	else printf("arrFind invalid: NULL\n");
	return 0;
}

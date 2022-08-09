#include <stddef.h>

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

void arrStats(double *arr, size_t n, double *min, double *max, double *mean) {
	int index;
	double num;

	/* Set min, max and mean to be first element *arr = arr[0] */
	*min=*arr; 
	*max=*arr; 
	*mean=*arr;

	/* Iterate through the remaining elements */
	for (index=1; index<n; index++) {
		/* Parse current element *(arr + index*sizeof(arr)) = arr[index] */
		num = *(arr + index*sizeof(arr));
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

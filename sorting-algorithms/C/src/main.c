#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils.h"
#include "selection.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include "heap.h"
#include "counting.h"
#include "bucket.h"

//#define _POSIX_C_SOURCE 199309L

#define LIST_SIZE 50
#define BILLION 1E9

int main(int argc, char *argv[]) {
	char isBenchmark = 0;

	// Check arguments
	if (argc < 2) {
		printErrMsg(argv[0]);
		return 1;
	}

	// Sort function
	void (*sort)(t_element*, unsigned int);
	char isDefault = 0;

	// Select sort algorithm
	if (strcmp(argv[1], "-s") == 0)
		sort = &selectionSort;
	else if (strcmp(argv[1], "-i") == 0)
		sort = &insertionSort;
	else if (strcmp(argv[1], "-m") == 0)
		sort = &mergeSort;
	else if (strcmp(argv[1], "-q") == 0)
		sort = &quickSort;
	else if (strcmp(argv[1], "-h") == 0)
		sort = &heapSort;
	else if (strcmp(argv[1], "-c") == 0)
		sort = &countSort;
	else if (strcmp(argv[1], "-bk") == 0)
		sort = &bucketSort;
	else if (strcmp(argv[1], "-d") == 0)
		isDefault = 1;
	else {
		printErrMsg(argv[0]);
		return 1;
	}

	if (argc == 3) {
		if (strcmp(argv[2], "-b") == 0)
			isBenchmark = 1;
	}

	int len;

	// Get list size
    if(scanf("%i", &len) != 1)
		return 1;

    if(len <= 0)
        len = LIST_SIZE;

	// Create list
	t_element list[len];

	// Fill list
    for(unsigned int i = 0; i < len; i++)
        if(scanf("%i", &list[i]) != 1)
			return 1;

	struct timespec begin = {0, 0}, end = { 0, 0 };

	if (isDefault == 1) {
		// Get start time
		clock_gettime(CLOCK_REALTIME, &begin);

		// Sorting
		qsort(list, len, sizeof(int), cmpfunc);

		// Get end time
		clock_gettime(CLOCK_REALTIME, &end);
	}
	else {
		// Get start time
		clock_gettime(CLOCK_REALTIME, &begin);

		// Sorting
		sort(list, len);

		// Get end time
		clock_gettime(CLOCK_REALTIME, &end);
	}

	// Print list
	if (isBenchmark) {
		printf("%lf", (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / BILLION);
		printf(";");
	} //else
		//printList(list, len);

    return 0;
}

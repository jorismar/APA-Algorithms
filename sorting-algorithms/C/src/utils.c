#include "utils.h"

// *************************************************************************

void printList(t_element *list, unsigned int list_size) {
	//printf("%s: ", name);

	for (unsigned int i = 0; i < list_size; i++)
		printf("%i\n", list[i]);

	//printf("\n\n");
}

// *************************************************************************

void printErrMsg(char* exec_name) {
	printf("Invalid Arguments\n\nUsage:\n\n %s -[s|i|m|q|h]\n\n", exec_name);
	printf(" -s\tUse selection sort algorithm\n");
	printf(" -i\tUse insertion sort algorithm\n");
	printf(" -m\tUse merge sort algorithm\n");
	printf(" -q\tUse quick sort algorithm\n");
	printf(" -h\tUse heap sort algorithm\n\n");
	printf(" -d\tUse default sort algorithm (qsort)\n\n");
}

// *************************************************************************

void timespec_diff(struct timespec *start, struct timespec *stop, struct timespec *result) {
	if ((stop->tv_nsec - start->tv_nsec) < 0) {
		result->tv_sec = stop->tv_sec - start->tv_sec - 1;
		result->tv_nsec = stop->tv_nsec - start->tv_nsec + 1000000000;
	}
	else {
		result->tv_sec = stop->tv_sec - start->tv_sec;
		result->tv_nsec = stop->tv_nsec - start->tv_nsec;
	}
}

// *************************************************************************

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

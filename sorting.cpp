#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 50

void fillList(int *list);
void insertionSort(int *list);
void selectionSort(int *list);
void mergeSort(int *list);
void quickSort(int *list);
void heapSort(int *list);
void printList(char *name, int *list);

int main()
{
	int list[LIST_SIZE];

	fillList(list);
	printList("Values", list);

	selectionSort(list);
	printList("Selection Sort", list);

	getchar();

    return 0;
}

void fillList(int *list) {
	for (unsigned int i = 0; i < LIST_SIZE; i++)
		list[i] = (0 + rand() / (RAND_MAX / LIST_SIZE));
}

void insertionSort(int *list) {
	
}

void selectionSort(int *list) {
	int value, lesser = 0;

	for (unsigned int i = 0; i < LIST_SIZE; i++) {
		lesser = i;

		for (unsigned int j = i + 1; j < LIST_SIZE; j++)
			if (list[j] < list[lesser])
				lesser = j;

		if (lesser == i)
			continue;

		value = list[i];
		list[i] = list[lesser];
		list[lesser] = value;
	}
}

void mergeSort(int *list) {

}

void quickSort(int *list) {

}

void heapSort(int *list) {

}

void printList(char * name, int *list) {
	printf("%s: ", name);

	for (unsigned int i = 0; i < LIST_SIZE; i++)
		printf("%i ", list[i]);

	printf("\n\n");
}
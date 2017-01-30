#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "selection.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include "heap.h"

#define LIST_SIZE 50

// *************************************************************************

void printList(char * name, t_element *list, unsigned int list_size) {
	printf("%s: ", name);

	for (unsigned int i = 0; i < list_size; i++)
		printf("%i ", list[i]);

	printf("\n\n");
}
// *************************************************************************

int main(int argc, char *argv[]) {
    int len;

    scanf("%i", &len);

    if(len <= 0)
        len = LIST_SIZE;

    t_element selection_list[len];
    t_element insertion_list[len];
    t_element merge_list[len];
    t_element quick_list[len];
    t_element heap_list[len];

    for(unsigned int i = 0; i < len; i++) {
        t_element elem;

        scanf("%i", &elem);

        selection_list[i] = elem;
        insertion_list[i] = elem;
        merge_list[i] = elem;
        quick_list[i] = elem;
        heap_list[i] = elem;        
    }

	printList("Values", selection_list, len);

	selectionSort(selection_list, len);
    insertionSort(insertion_list, len);
	mergeSort(merge_list, len);
    quickSort(quick_list, len);
    heapSort(heap_list, len);
	
    printList("Selection Sort", selection_list, len);
    printList("Insertion Sort", insertion_list, len);
    printList("Merge Sort", merge_list, len);
    printList("Quick Sort", quick_list, len);
    printList("Heap Sort", heap_list, len);

    return 0;
}

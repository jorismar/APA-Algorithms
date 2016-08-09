#include "list.h"

#define LIST_SIZE 50

// *************************************************************************

void merge(t_element *list) {
    int mid = LIST_SIZE / 2;
    int i, j, k;
 
    t_element aux[LIST_SIZE];
    
    for(unsigned int i = 0, j = mid, k = 0; i < mid && j < LIST_SIZE; k++)
        if(list[i] <= list[j])
            aux[k] = list[i++];
        else
            aux[k] = list[j++];


    if(i == mid)
        while(j < LIST_SIZE)
            aux[k++] = list[j++];
    else
        while(i < mid)
            aux[k++] = list[i++];

    for(i = 0; i < LIST_SIZE; ++i)
        list[i] = aux[i];
}

// *************************************************************************

void mergeSort(t_element *list, unsigned int size) {
    if(LIST_SIZE > 1) {
        int mid = LIST_SIZE / 2;
        mergeSort(list, mid);
        mergeSort(list + mid, LIST_SIZE - mid);
        merge(list);
    }
}

// *************************************************************************

int main() {
	t_element list[LIST_SIZE];

	fillList(list, LIST_SIZE);
	printList("Values", list, LIST_SIZE);

	mergeSort(list, LIST_SIZE);
	printList("Merge Sort", list, LIST_SIZE);

    return 0;
}

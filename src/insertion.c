#include "list.h"

#define LIST_SIZE 50

// *************************************************************************

void insertionSort(t_element *list) {
    for(unsigned int i = 1; i < LIST_SIZE; i++) {
        for(int j = i - 1; j >= 0 && list[j] > list[j + 1]; j--) {
            t_element value = list[j];
            list[j] = list[j + 1];
            list[j + 1] = value;
        }
    }
}

// *************************************************************************

int main() {
	t_element list[LIST_SIZE];

	fillList(list, LIST_SIZE);
	printList("Values", list, LIST_SIZE);

	insertionSort(list);
	printList("Insertion Sort", list, LIST_SIZE);

    return 0;
}

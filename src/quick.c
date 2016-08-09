#include "list.h"

#define LIST_SIZE 50

// *************************************************************************

unsigned int partition(t_element *list, unsigned int begin, unsigned int end) {
    t_element piv = list[begin];
    unsigned int top = begin;
 
    for(unsigned int i = begin + 1; i <= end; i++) {
        if(piv > list[i]) {
            list[top++] = list[i];
            list[i] = list[top];
        }
    }

    list[top] = piv;

    return top;
}

// *************************************************************************

void swap(t_element *p, t_element *s) {
    int a = *p;
    *p = *s;
    *s = a;
}
 
// *************************************************************************

void quickSort(t_element *list, unsigned int begin, unsigned int end) {
    unsigned int mid = 0;
 
    if(begin < end){
        mid = partition(list, begin, end);
        quickSort(list, begin, mid);
        quickSort(list, mid + 1, end);
    }
}

// *************************************************************************

int main() {
	t_element list[LIST_SIZE];

	fillList(list, LIST_SIZE);
	printList("Values", list, LIST_SIZE);

	quickSort(list, 0, LIST_SIZE);
	printList("Quick Sort", list, LIST_SIZE);

    return 0;
}


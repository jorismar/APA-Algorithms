#include "quick.h"

// *************************************************************************

unsigned int partition(t_element *list, unsigned int begin, unsigned int end) {
    t_element piv = list[begin];
    unsigned int top = begin;
 
    for(unsigned int i = begin + 1; i < end; i++) {
        if(piv > list[i]) {
            list[top++] = list[i];
            list[i] = list[top];
        }
    }

    list[top] = piv;

    return top;
}
 
// *************************************************************************

void quick(t_element *list, unsigned int begin, unsigned int end) {
    unsigned int mid;
 
    if(begin < end) {
        mid = partition(list, begin, end);
        quick(list, begin, mid);
        quick(list, mid + 1, end);
    }
}

// *************************************************************************

void quickSort(t_element *list, unsigned int len) {
	quick(list, 0, len);
}

// *************************************************************************

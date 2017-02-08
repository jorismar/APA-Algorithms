#include "insertion.h"

// *************************************************************************

void insertionSort(t_element *list, unsigned int len) {
    for(unsigned int i = 1; i < len; i++) {
        for(int j = i - 1; j >= 0 && list[j] > list[j + 1]; j--) {
            t_element value = list[j];
            list[j] = list[j + 1];
            list[j + 1] = value;
        }
    }
}

// *************************************************************************

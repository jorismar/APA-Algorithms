#include "merge.h"

// *************************************************************************

void merge(t_element *list, unsigned int len) {
    int mid = len / 2;
    int i, j, k;
 
    t_element aux[len];
    
    for(i = 0, j = mid, k = 0; i < mid && j < len; k++)
        if(list[i] <= list[j])
            aux[k] = list[i++];
        else
            aux[k] = list[j++];

    if(i == mid)
        while(j < len)
            aux[k++] = list[j++];
    else
        while(i < mid)
            aux[k++] = list[i++];

    for(i = 0; i < len; i++)
        list[i] = aux[i];
}

// *************************************************************************

void mergeSort(t_element *list, unsigned int len) {
    if(len > 1) {
        int mid = len / 2;
        mergeSort(list, mid);
        mergeSort(list + mid, len - mid);
        merge(list, len);
    }
}

// *************************************************************************

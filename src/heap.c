#include "heap.h"

// *************************************************************************

void heap(t_element *list, unsigned int index, int len) {
    int max = 2 * index + 1;

    if(max < len) {
        if((max + 1) < len && list[max] < list[max + 1])
            max++;

       if(list[max] > list[index]) {
            t_element aux = list[index];
            list[index] = list[max];
            list[max] = aux;

            heap(list, max, len);
       }
    }
}

// *************************************************************************

void heapSort(t_element *list, unsigned int len) {
    for(int i = len / 2 - 1; i >= 0; i--)
        heap(list, i, len);

    for(int i = len - 1; i > 0; i--) {
        t_element aux = list[i];
        list[i] = list[0];
        list[0] = aux;

        heap(list, 0, --len);
    }
}

// *************************************************************************


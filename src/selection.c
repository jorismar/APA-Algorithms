#include "selection.h"

// *************************************************************************

void selectionSort(t_element *list, unsigned int len) {
	t_element value;

	for (unsigned int i = 0,  lesser = 0; i < len; i++) {
		lesser = i;

		for (unsigned int j = i + 1; j < len; j++)
			if (list[j] < list[lesser])
				lesser = j;

		if (lesser == i)
			continue;

		value = list[i];
		list[i] = list[lesser];
		list[lesser] = value;
	}
}

// *************************************************************************

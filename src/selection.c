#include "list.h"

#define LIST_SIZE 50

// *************************************************************************

void selectionSort(t_element *list) {
	t_element value;

	for (unsigned int i = 0,  lesser = 0; i < LIST_SIZE; i++) {
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

// *************************************************************************

int main()
{
	t_element list[LIST_SIZE];

	fillList(list, LIST_SIZE);
	printList("Values", list, LIST_SIZE);

	selectionSort(list);
	printList("Selection Sort", list, LIST_SIZE);

    return 0;
}


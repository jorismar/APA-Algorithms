#include "list.h"

// *************************************************************************

void fillList(t_element *list, unsigned int list_size) {
	for (unsigned int i = 0; i < list_size; i++)
		list[i] = (0 + rand() / (RAND_MAX / list_size));
}

// *************************************************************************

void printList(char * name, t_element *list, unsigned int list_size) {
	printf("%s: ", name);

	for (unsigned int i = 0; i < list_size; i++)
		printf("%i ", list[i]);

	printf("\n\n");
}
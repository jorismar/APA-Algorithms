#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int t_element;

void fillList(t_element *list, unsigned int list_size);
void printList(char * name, t_element *list, unsigned int list_size);

#endif // !LIST_H
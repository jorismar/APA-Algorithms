#include "dynamiclist.h"

// *************************************************************************

void dl_Init(DynamicList* dynlist) {
	dynlist->size = 0;
	dynlist->next = NULL;
	dynlist->begin = NULL;
	dynlist->last = NULL;
}

// *************************************************************************

void dl_Add(DynamicList* dynlist, t_element elem) {
	if (dynlist->size == 0) {
		dynlist->begin = (dl_cell*)malloc(sizeof(dl_cell));
		
		dynlist->begin->element = elem;
		dynlist->begin->previous = NULL;
		dynlist->begin->next = NULL;

		dynlist->next = dynlist->begin;
		dynlist->last = dynlist->begin;
		dynlist->size++;
	}
	else {
		dynlist->last->next = (dl_cell*)malloc(sizeof(dl_cell));

		dynlist->last->next->element = elem;
		dynlist->last->next->previous = dynlist->last;
		dynlist->last->next->next = NULL;

		dynlist->last = dynlist->last->next;
		dynlist->size++;
	}
}

// *************************************************************************

void dl_AddSorted(DynamicList* dynlist, t_element elem) {
	printf("%i ", elem);
	if (dynlist->size == 0 || elem >= dynlist->last->element)
		dl_Add(dynlist, elem);
	else {
		if (elem <= dynlist->begin->element) {
			dynlist->begin->previous = (dl_cell*)malloc(sizeof(dl_cell));
			dynlist->begin->previous->element = elem;
			dynlist->begin->previous->next = dynlist->begin;
			dynlist->begin->previous->previous = NULL;

			if (dynlist->begin == dynlist->next)
				dynlist->next = dynlist->begin->previous;

			dynlist->begin = dynlist->begin->previous;

			dynlist->size++;
		}
		else {
			dl_cell *current = dynlist->begin->next;

			while(current != NULL && current->element < elem)
				current = current->next;

			if (current == NULL) {
				dl_Add(dynlist, elem);
				return;
			}

			dl_cell *aux = current->previous;
			current->previous = (dl_cell*)malloc(sizeof(dl_cell));
			current->previous->element = elem;
			current->previous->previous = aux;
			current->previous->next = current;
			aux->next = current->previous;

			if (current == dynlist->next)
				dynlist->next = current->previous;

			dynlist->size++;
		}
	}
}

// *************************************************************************

t_element dl_Next(DynamicList* dynlist) {
	t_element elem = INVALID_ELEMENT;

	if (dynlist->next != NULL) {
		elem = dynlist->next->element;
		dynlist->next = dynlist->next->next;
	}

	return elem;
}

// *************************************************************************

void dl_Set(DynamicList* dynlist, unsigned int index, t_element elem) {
	if (index >= dynlist->size)
		return;

	dl_cell *current = dynlist->begin;

	for (unsigned int i = 0; current != NULL && i < index; i++)
		current = current->next;

	current->element = elem;
}

// *************************************************************************

t_element dl_Get(DynamicList* dynlist, unsigned int index) {
	if (index >= dynlist->size)
		return INVALID_ELEMENT;

	dl_cell *current = dynlist->begin;

	for (unsigned int i = 0; current != NULL && i < index; i++)
		current = current->next;

	if (current == NULL)
		return INVALID_ELEMENT;

	return current->element;
}

// *************************************************************************

void dl_Push(DynamicList* dynlist, t_element elem) {
	dl_Add(dynlist, elem);
}

// *************************************************************************

t_element dl_Pop(DynamicList* dynlist) {
	t_element elem;

	elem = dynlist->last->element;

	dl_cell *current = dynlist->last;

	dynlist->last = dynlist->last->previous;
	dynlist->last->next = NULL;
	
	free(current);

	dynlist->size--;

	return elem;
}

// *************************************************************************

t_element dl_Remove(DynamicList* dynlist, unsigned int index) {
	if (index >= dynlist->size)
		return INVALID_ELEMENT;

	t_element elem;

	dl_cell *current = dynlist->begin;

	for (unsigned int i = 0; current != NULL && i < index; i++)
		current = current->next;

	if (current == NULL)
		return INVALID_ELEMENT;

	elem = current->element;
	current->previous->next = current->next;
	current->next->previous = current->previous;

	free(current);

	dynlist->size--;

	return elem;
}

// *************************************************************************

void dl_Clear(DynamicList* dynlist) {
	dl_cell *current = dynlist->begin;
	dl_cell *next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	dl_Init(dynlist);
}

// *************************************************************************

void dl_Seek(DynamicList* dynlist, int index) {
	if (index >= dynlist->size)
		return;

	if (index == DL_BEGIN)
		if (dynlist->begin != NULL)
			dynlist->next = dynlist->begin;
	else if (index == DL_END)
		if (dynlist->last != NULL)
			dynlist->next = dynlist->last;
	else {
		dl_cell *current = dynlist->begin;

		for (unsigned int i = 0; current != NULL && i < index; i++)
			current = current->next;

		if (current == NULL)
			return;

		dynlist->next = current;
	}
}
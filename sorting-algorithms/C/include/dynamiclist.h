#ifndef JB_DYNAMIC_LIST_H
#define JB_DYNAMIC_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

#define DL_BEGIN 0
#define DL_END -1

typedef struct cell {
	t_element element;
	struct cell *previous;
	struct cell *next;
} dl_cell;

typedef struct {
	unsigned int size;
	dl_cell *next;
	dl_cell *begin;
	dl_cell *last;
} DynamicList;

void dl_Init(DynamicList* dynlist);

void dl_Add(DynamicList* dynlist, t_element elem);
void dl_AddSorted(DynamicList* dynlist, t_element elem);
t_element dl_Next(DynamicList* dynlist);

void dl_Set(DynamicList* dynlist, unsigned int index, t_element elem);
t_element dl_Get(DynamicList* dynlist, unsigned int index);

void dl_Push(DynamicList* dynlist, t_element elem);
t_element dl_Pop(DynamicList* dynlist);

t_element dl_Remove(DynamicList* dynlist, unsigned int index);

void dl_Clear(DynamicList* dynlist);

void dl_Seek(DynamicList* dynlist, int index);
#endif // !JB_DYNAMIC_LIST_H
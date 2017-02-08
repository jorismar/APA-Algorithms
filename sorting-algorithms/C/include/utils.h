#ifndef JB_UTILS_H
#define JB_UTILS_H

#include <stdio.h>
#include <sys/time.h>

typedef int t_element;

void printList(t_element *list, unsigned int list_size);
void printErrMsg(char* exec_name);
int cmpfunc(const void* a, const void* b);

#endif // !JB_UTILS_H
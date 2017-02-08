#ifndef JB_COUNT_SORT_H
#define JB_COUNT_SORT_H

#include <string.h>
#include "utils.h"

// *************************************************************************

void countSort(t_element *list, unsigned int len);
unsigned int getMaxRange(t_element *list, unsigned int len);

// *************************************************************************

#endif // !JB_COUNT_SORT_H
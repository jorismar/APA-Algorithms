#include "counting.h"

void countSort(t_element *list, unsigned int len)
{
	t_element aux[len];
	unsigned int range = getMaxValue(list, len);

	unsigned int counter[range + 1];

	for (unsigned int i = 0; i <= range; i++)
		counter[i] = 0;

	for (unsigned int i = 0; i < len; i++)
		if(list[i] >= 0)
			counter[list[i]] += 1;

	for (unsigned int i = 1; i <= range; i++)
		counter[i] += counter[i - 1];

	for (unsigned int i = 0; i < len; i++)
		if (list[i] >= 0) {
			aux[counter[list[i]] - 1] = list[i];
			counter[list[i]] -= 1;
		}

	for (unsigned int i = 0; i < len; i++)
		list[i] = aux[i];
}
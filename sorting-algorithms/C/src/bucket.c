#include "bucket.h"

// *************************************************************************

void bcktSort(t_element *list, int len) {
	DynamicList bucketList[len];
	memset(bucketList, 0, sizeof(DynamicList) * len);

	t_element max = list[0];

	for (int i = 1; i < len; i++)
		if (max < list[i])
			max = list[i];

	max++;

	for (int i = 0; i < len; i++)
		dl_AddSorted(&bucketList[list[i] * len / max], list[i]);

	int k = 0;
	memset(list, 0, sizeof(t_element) * len);
	for (int i = 0; i < len; i++)
		for (int j = 0; j < bucketList[i].size; j++)
			list[k++] = dl_Get(&bucketList[i], j);
}

// *************************************************************************

void bucketSort(t_element *list, unsigned int len) {
	int posLen = 0;
	int negLen = 0;
	t_element positives[len];
	t_element negatives[len];

	for (int i = 0; i < len; i++)
		if (list[i] < 0)
			negatives[negLen++] = -1 * list[i];
		else
			positives[posLen++] = list[i];
	
	if (negLen > 0) {
		bcktSort(negatives, negLen);

		//for (unsigned int i = 0, j = negLen - 1; i < len && j >= 0; i++, j--) { // Por que encerra a funcao??
		for (int i = 0; i < negLen; i++)
			list[i] = -1 * negatives[negLen - 1 -i];
	}

	if (posLen > 0) {
		bcktSort(positives, posLen);

		for (int i = negLen; i < len; i++)
			list[i] = positives[i - negLen];
	}
}

// *************************************************************************


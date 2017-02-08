/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Sorting;

/**
 *
 * @author Jorismar
 */
public class Selection implements SortAlgorithm {
    @Override
    public void Sort(int[] list) {
	int value;

	for (int i = 0,  lesser; i < list.length; i++) {
            lesser = i;

            for (int j = i + 1; j < list.length; j++)
                if (list[j] < list[lesser])
                        lesser = j;

            if (lesser == i)
                continue;

            value = list[i];
            list[i] = list[lesser];
            list[lesser] = value;
	}
    }
}

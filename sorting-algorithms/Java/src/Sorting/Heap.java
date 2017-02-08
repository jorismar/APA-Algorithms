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
public class Heap implements SortAlgorithm {
    @Override
    public void Sort(int[] list) {
        int len = list.length;
        
        for(int i = len / 2 - 1; i >= 0; i--)
            this.heap(list, i, len);

        for(int i = len - 1; i > 0; i--) {
            int aux = list[i];
            list[i] = list[0];
            list[0] = aux;

            this.heap(list, 0, --len);
        }
    }

    private void heap(int[] list, int index, int len) {
        int max = 2 * index + 1;

        if(max < len) {
            if((max + 1) < len && list[max] < list[max + 1])
                max++;

           if(list[max] > list[index]) {
                int aux = list[index];
                list[index] = list[max];
                list[max] = aux;

                this.heap(list, max, len);
           }
        }
    }
}

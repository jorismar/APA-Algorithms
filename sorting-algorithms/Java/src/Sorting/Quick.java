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
public class Quick implements SortAlgorithm {
    @Override
    public void Sort(int[] list) {  
        this.Quick(list, 0, list.length);
    }  

    private void Quick(int[] list, int begin, int end) {
        int mid;

        if(begin < end) {
            mid = this.Partition(list, begin, end);
            this.Quick(list, begin, mid);
            this.Quick(list, mid + 1, end);
        }
    }

    private int Partition(int[] list, int begin, int end) {
        int piv = list[begin];
        int top = begin;

        for(int i = begin + 1; i < end; i++) {
            if(piv > list[i]) {
                list[top++] = list[i];
                list[i] = list[top];
            }
        }

        list[top] = piv;

        return top;
    }
}

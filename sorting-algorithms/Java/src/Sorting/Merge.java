/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Sorting;

import java.util.Arrays;

/**
 *
 * @author Jorismar
 */
public class Merge implements SortAlgorithm {
    @Override
    public void Sort(int[] list) {
        this.Sort(list, 0, list.length);
    }  

    private void Sort(int[] list, int begin, int end) {
        int len = end - begin;
        
        if(len > 1) {
            int mid = begin + (len / 2);
            this.Sort(list, begin, mid);
            this.Sort(list, mid, end);
            this.Merge(list, begin, end);
        }
    }
    
    private void Merge(int[] list, int begin, int end) {
        int len = end - begin;

        int mid = begin + (len / 2);
        
        int i, j, k;

        int[] aux = new int[len];

        for(i = begin, j = mid, k = 0; i < mid && j < end; k++)
            if(list[i] <= list[j])
                aux[k] = list[i++];
            else
                aux[k] = list[j++];

        if(i == mid)
            while(j < end)
                aux[k++] = list[j++];
        else
            while(i < mid)
                aux[k++] = list[i++];
        
        for(i = begin, j = 0; i < end && j < len; i++, j++) 
            list[i] = aux[j];
    }
}

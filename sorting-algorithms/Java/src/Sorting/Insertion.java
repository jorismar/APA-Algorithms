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
public class Insertion implements SortAlgorithm {
    @Override
    public void Sort(int[] list) {
        for(int i = 1; i < list.length; i++) {
            for(int j = i - 1; j >= 0 && list[j] > list[j + 1]; j--) {
                int value = list[j];
                list[j] = list[j + 1];
                list[j + 1] = value;
            }
        }
    }
}

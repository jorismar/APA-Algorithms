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
public class Default implements SortAlgorithm {
    @Override
    public void Sort(int[] list) {
        Arrays.sort(list);
    }
}

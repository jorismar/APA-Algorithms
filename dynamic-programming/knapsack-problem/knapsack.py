#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

# ============================================================== #

def dynamicKnapsack(num_itens, knapsack_capacity, weights, values):
    # Init table
    table = [[0 for x in range(knapsack_capacity + 1)] for y in range(num_itens + 1)] 

    # Capacity columns
    for c in range(knapsack_capacity + 1):
        table[0][c] = 0

        # Items lines
        for i in range(num_itens):
            # Previous item
            prev = table[i][c]

            # New item to add
            new = 0 if weights[i] > c else table[i][c - weights[i]] + values[i]

            # Add value in table
            table[i + 1][c] = prev if prev > new else new

    # Result
    return table[num_itens][knapsack_capacity]

# ============================================================== #

if __name__ == '__main__':
    # Input list
    lines = []

    # Input read
    for i in range(3):
        lines.append(input(''))
    
    # n = Quantity of items
    # M = Knapsack capacity
    n, M = list(map(int, lines[0].split(' ')))

    # Weights of the objects
    pi = list(map(int, lines[1].split(' ')))

    # Values of the objects
    vi = list(map(int, lines[2].split(' ')))

    # Result
    print(dynamicKnapsack(n, M, pi, vi))
else:
	print("This class can not be imported.")

#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

# ============================================================== #

def dynamicKnapsack(num_itens, knapsack_capacity, weights, values):
    # Init dynamic programming table
    table = [[0 for x in range(knapsack_capacity + 1)] for y in range(num_itens + 1)] 

    # Capacity columns
    for c in range(knapsack_capacity + 1):
        table[0][c] = 0

        # Items lines
        for i in range(num_itens):
            # Previous item
            prev = table[i][c]

            # New weights to add
            new = 0 if weights[i] > c else table[i][c - weights[i]] + values[i]

            # Add value in table
            table[i + 1][c] = prev if prev > new else new

    # List of selected items
    knapsack = []

    # Last capacity column
    c = knapsack_capacity

    # Last items line
    i = num_itens

    # Get selected itens
    while c > 0 and i > 0:
        if table[i][c] != table[i - 1][c]:
            # Storage the index of item in table
            knapsack.append(i)

            # Update capacity
            c = c - weights[i - 1]

        # Update item position
        i = i - 1

    # Result (Best value, List of selected items)
    return (table[num_itens][knapsack_capacity], knapsack)

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
    value, knapsack = dynamicKnapsack(n, M, pi, vi)
    
    # Sort knapsack
    knapsack.sort()

    # Print result
    print("\nValue: " + str(value) + "\nSelected items: " + str(knapsack) + "\n")
else:
	print("This class can not be imported.")

#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys, Heap

INFINITY = sys.maxsize

# ============================================================== #

def prim(num, weights):
    # Initiate controllers
    V = [i for i in range(num)]
    keys = [INFINITY] * num
    fathers = [None] * num

    # Sets initial node key to zero.
    keys[0] = 0

    # Generates a heap
    Q = Heap.Heap(V)

    while not Q.is_empty():
        u = Q.pop()
        
        # Stops if the last node was reached.
        if Q.is_empty():
            break

        for i in range(len(weights[u])):
            # Gets the parent node.
            v = (num - 1) - i

            # Selects a candidate path.
            if Q.contains(v) and weights[u][i] < keys[v]:
                fathers[v] = u
                keys[v] = weights[u][i]

    # Returns the weight of the MST
    return keys

# ============================================================== #

if __name__ == '__main__':
    # Number of nodes
    num = int(input(''))

    # Init adjacency matrix
    weights = []

    # Read edge weights
    for i in range(num):
        try:
            line = input('')
            vertWeights = line.split(' ')
            weights.append([])

            for v in vertWeights:
                weights[i].append(int(v))
        except:
            pass

    # Get the minimal spanning tree
    mst = prim(num, weights)

    # Print result
    print("\nValue: " + str(sum(mst)) + "\nSelected edges: " + str(mst[1:]) + "\n")
else:
	print("This class can not be imported.")

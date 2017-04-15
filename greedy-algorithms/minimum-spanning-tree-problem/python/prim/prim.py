#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys, Heap

INFINITY = sys.maxsize

# ============================================================== #

def prim(num, weights):
    # Initiate controllers
    nodes = [i for i in range(num)]
    keys = [INFINITY] * num
    fathers = [None] * num

    # Sets initial node key to zero.
    keys[0] = 0

    # Generates a heap
    q = Heap.Heap(nodes)

    while not q.is_empty():
        v = q.pop()
        
        # Stops if the last node was reached.
        if q.is_empty():
            break

        for i in range(len(weights[v])):
            # Gets the parent node.
            e = (num - 1) - i

            # Selects a candidate path.
            if q.contains(e) and weights[v][i] < keys[e]:
                fathers[e] = v
                keys[e] = weights[v][i]

    # Returns the total weight of the MST
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

#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys, Heap

INFINITY = sys.maxsize

# ============================================================== #

def dijkstra(num, weights):
    # Initiate controllers
    V = [i for i in range(num)]
    dists = [INFINITY] * num
    fathers = [None] * num

    # Sets initial node key to zero.
    dists[0] = 0

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

            dist = dists[u] + weights[u][i]

            # Selects a candidate path.
            if dist < dists[v]:
                fathers[v] = u
                dists[v] = dist

    # Returns selecteds edges list
    return dists

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
    mst = dijkstra(num, weights)

    # Print result
    print("\nValue: " + str(sum(mst)) + "\nSelected edges: " + str(mst[1:]) + "\n")
else:
	print("This class can not be imported.")

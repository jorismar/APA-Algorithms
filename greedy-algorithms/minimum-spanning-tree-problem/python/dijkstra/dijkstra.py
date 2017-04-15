#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys, Heap

INFINITY = sys.maxsize

# ============================================================== #

def dijkstra(num, weights):
    return weights

# ============================================================== #

if __name__ == '__main__':
    # Number of vertices
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
    tree = dijkstra(num, weights)

    # Print solution
    print(tree)
else:
	print("This class can not be imported.")

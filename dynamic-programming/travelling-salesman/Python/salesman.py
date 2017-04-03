#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys, re

# ============================================================== #

def dynamicSalesman(num_vertices):
    # Fill the initial set of paths
    setpath = [i for i in range(1, num_vertices)]

    # Get cost and selected paths
    return getCost(0, setpath)

# ============================================================== #

def getCost(origin, setpath):
    # Check if set of path is empty
    if len(setpath) == 0:
        return distances[0][origin], [1, origin + 1]

    # Initiates auxiliar variables
    selected_path = []
    lower = sys.maxsize

    # Select the minimum path
    for s in range(len(setpath)):
        node = setpath.pop(s)
        value, path = getCost(node, setpath)
        value += distances[node][origin]
        
        if value < lower:
            lower = value
            selected_path = path
        
        setpath.insert(s, node)

    # Add this node to path
    selected_path.append(origin + 1)

    return lower, selected_path

# ============================================================== #

if __name__ == '__main__':
    # Adjacency Matrix
    global distances

    # Vertices number
    num = int(input(''))

    # Init matrix
    distances = []

    # Read distances
    for i in range(num):
        line = input('')
        vert_distances = line.split(' ')
        distances.append([])

        for j in range(num):
            try:
                distances[i].append(int(vert_distances[j]))
            except:
                pass

    # Get value and optimal path
    value, path = dynamicSalesman(num)

    # Print solution
    print("valor : " + str(value) + "\ncircuito : " + str(path))
else:
	print("This class can not be imported.")

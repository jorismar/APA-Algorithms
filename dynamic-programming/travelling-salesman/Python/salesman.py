#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

# ============================================================== #

def dynamicSalesman(num_vertices):
    # Dynamic Programming Table
    global table

    # Calculates number of paths
    num_paths = 2

    for i in range(num_vertices - 2):
        num_paths *= 2
    
    # Fill the initial set of paths
    setpath = [i for i in range(1, num_vertices)]

    # Get cost and selected paths
    return getCost(0, setpath)

# ============================================================== #

def getCost(origin, setpath):
    if len(setpath) == 0:
        return distances[0][origin], [1, origin + 1]

    selected_path = []
    lower = sys.maxsize

    for s in range(len(setpath)):
        node = setpath.pop(s)
        value, path = getCost(node, setpath)
        value += distances[node][origin]
        
        if value < lower:
            lower = value
            selected_path = path
        
        setpath.insert(s, node)

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
        distances.append(list(map(int, line.split(' '))))

    value, path = dynamicSalesman(num)

    print("valor : " + str(value) + "\ncircuito : " + str(path))
else:
	print("This class can not be imported.")

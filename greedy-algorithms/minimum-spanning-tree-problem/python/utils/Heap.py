#!/usr/bin/python
# -*- coding: utf-8 -*-

import heapq

class Heap():
    def __init__(self, elements):
        self.heap = elements
        heapq.heapify(self.heap)

    def pop(self):
        return heapq.heappop(self.heap)

    def push(self, item):
        heapq.heappush(self.heap, item)

    def contains(self, item):
        return item in self.heap

    def length(self):
        return len(self.heap)

    def is_empty(self):
        return len(self.heap) < 1
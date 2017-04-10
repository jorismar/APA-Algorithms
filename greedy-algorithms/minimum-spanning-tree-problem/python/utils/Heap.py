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
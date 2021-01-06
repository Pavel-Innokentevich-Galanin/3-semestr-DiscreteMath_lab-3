import numpy

class Graph:
    def graph(self, numbeOfVertices):
        self.arr = numpy.zeros( (numbeOfVertices, numbeOfVertices))
        for i in range(len(self.arr)):
            for j in range(len(self.arr)):
                self.arr[i][j] = float('inf')
        return self.arr
    
    def addEdge_weight(self, i, j, weight):
        self.arr[i][j] = weight
        self.arr[j][i] = weight

    def addEdge(self, i, j):
        self.arr[i][j] = 1
        self.arr[j][i] = 1

    def addEdge_direction(self, i, j):
        self.arr[i][j] = 1

    def removeEdge(self, i, j):
        self.arr[i][j] = 0
        self.arr[j][i] = 0

    def isEdge(self, i, j):
        return self.arr[i][j]

    def printArr(self):
        print()
        print('Граф смежности')
        print(self.arr)
        print()

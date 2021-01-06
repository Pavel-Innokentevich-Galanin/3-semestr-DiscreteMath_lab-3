import numpy

from graph import Graph

class Kruskal_s_algorithm(Graph):
    def find(self, i):
        while (self.parent[i]):
            i = self.parent[i]
        return i

    def uni(self, i, j):
        if i != j:
            self.parent[j] = i
            return 1
        return 0

    def make_Kruskal_s_algorithm(self):
        print('Алгоритм Краскаля')
        print('Ребро: Вес')
        self.parent = numpy.zeros( (len(self.arr)), dtype = int )

        ne = 0
        mincost = 0
        for i in range(len(self.arr)):
            for j in range(len(self.arr)):
                if (self.arr[i][j] == 0):
                    self.arr = float('inf')

        while ne < (len(self.arr) - 1):
            min = float('inf')
            for i in range(len(self.arr)):
                for j in range(len(self.arr)):
                    if self.arr[i][j] < min:
                        min = self.arr[i][j]
                        a = u = i
                        b = v = j
            u = self.find(u)
            v = self.find(v)
            if a == 1 and b == 0:
                self.arr[a][b] = float('inf')
                continue
            if a == 0 and b == 2:
                self.arr[a][b] = float('inf')
                continue
            if self.uni(u, v):
                ne += 1
                print(a, ' - ', b, ' : ', min)
                mincost += min
            self.arr[a][b] = float('inf')
        print('Mинимальная сумма равна: ', mincost)

if __name__ == '__main__':
    g = Kruskal_s_algorithm()
    g.graph(7)

    g.addEdge_weight(0, 1, 5)
    g.addEdge_weight(0, 2, 8)
    g.addEdge_weight(0, 4, 11)
    g.addEdge_weight(1, 2, 4)
    g.addEdge_weight(1, 3, 8)
    g.addEdge_weight(2, 5, 10)
    g.addEdge_weight(3, 6, 6)
    g.addEdge_weight(3, 5, 2)
    g.addEdge_weight(4, 6, 4)
    g.addEdge_weight(4, 5, 7)
    g.addEdge_weight(5, 6, 5)
    g.printArr()
    g.make_Kruskal_s_algorithm()
    g.printArr()
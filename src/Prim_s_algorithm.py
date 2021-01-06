import numpy

from graph import Graph

class Prim_s_algorithm(Graph):
    def prim_s_algorithm(self):
        no_edge = 0
        print('Остовные деревья')
        print('Алгоритм Прима')
        print('Ребро : Вес')
        selected = numpy.zeros( (len(self.arr)) )
        while no_edge < len(self.arr):
            min = float('inf')
            x = 0
            y = 0
            for i in range(len(self.arr)):
                if (selected[i]):
                    for j in range(len(self.arr)):
                        if not selected[j] and self.arr[i][j]:
                            if min > self.arr[i][j]:
                                min = self.arr[i][j]
                                x = i
                                y = j
            print(x, ' - ', y, ' : ', self.arr[x][y])
            selected[y] = True
            no_edge += 1

if __name__ == '__main__':
    g = Prim_s_algorithm()
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
    g.prim_s_algorithm()
    g.printArr()
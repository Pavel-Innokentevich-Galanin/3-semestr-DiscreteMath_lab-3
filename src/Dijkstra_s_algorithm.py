import numpy

from graph import Graph

class Dijkstra_s_algorithm(Graph):
    def make_Dijkstra_s_algorithm(self, start):
        distance = numpy.zeros( (len(self.arr)) )
        m = start
        visited = numpy.zeros( (len(self.arr)) )
        for i in range(len(self.arr)):
            distance[i] = float('inf')
            visited[i] = False
        distance[start] = 0
        for count in range(len(self.arr) - 1):
            min = float('inf')
            for i in range(len(self.arr)):
                if not visited[i] and distance[i] <= min:
                    min = distance[i]
                    index = i
            u = index
            visited[u] = True
            for i in range(len(self.arr)):
                if not visited[i] and self.arr[u][i] and distance[u] != float('inf') and distance[u] + self.arr[u][i] < distance[i]:
                    distance[i] = distance[u] + self.arr[u][i]
        print('Алгоритм Дейкстры')
        print('Стоимость пути из начальной вершины до остальных:')
        for i in range(1, len(self.arr)):
            if distance[i] != float('inf'):
                print(m, ' > ', i, ' = ', distance[i])
            else:
                print(m, ' > ', i, ' = ', 'маршрут недоступен')

if __name__ == '__main__':
    g = Dijkstra_s_algorithm()
    g.graph(8)

    g.addEdge_weight(1, 2, 3)
    g.addEdge_weight(1, 3, 7)
    g.addEdge_weight(1, 4, 4)
    g.addEdge_weight(2, 4, 2)
    g.addEdge_weight(2, 3, 5)
    g.addEdge_weight(2, 7, 10)
    g.addEdge_weight(3, 6, 4)
    g.addEdge_weight(4, 5, 4)
    g.addEdge_weight(5, 6, 5)
    g.addEdge_weight(5, 7, 6)
    g.addEdge_weight(6, 7, 7)

    g.printArr()
    g.make_Dijkstra_s_algorithm(1)
    g.printArr()
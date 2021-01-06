from graph import Graph

class Floyd_Warshell_algorithm(Graph):
    def make_Floyd_Warshell_algorithm(self, start):
        for k in range(len(self.arr)):
            for i in range(len(self.arr)):
                for j in range(len(self.arr)):
                    if self.arr[i][k] and self.arr[k][j] and i != j:
                        if self.arr[i][k] + self.arr[k][j] < self.arr[i][j] or self.arr[i][j] == 0:
                            self.arr[i][j] = self.arr[i][k] + self.arr[k][j]
        # for k in range(len(self.arr)):
        #     for i in range(len(self.arr)):
        #         for j in range(len(self.arr)):
        #             self.arr[i][j] = self.arr[i][j] or self.arr[i][k] and self.arr[k][i]
        print('Алгоритм Флоида Уоршала')
        for j in range(1, len(self.arr)):
            print(start, ' > ', j, ' = ', self.arr[start][j])

if __name__ == '__main__':
    g = Floyd_Warshell_algorithm()
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
    g.make_Floyd_Warshell_algorithm(1)
    g.printArr()
#include "bfs.hpp"

Graph_bfs::Graph_bfs(int v) {
    V = v;
    adjList = new list<int>[V];
}

void Graph_bfs::add_edge(int v, int w) {
    adjList[v].push_back(w);
}

void Graph_bfs::util(int v, bool visited[]) {
    list<int> queue;
    list<int>::iterator i;

    visited[v] = true; // текущий узел помечаем как посещенный

    cout << "Обход графа в ширину начиная с " << v << " вершины: " << "\n";
    queue.push_back(v);
    int count = 0;
    while (!queue.empty()) {
        v = queue.front();
        cout << v + 1 << " ";
        queue.pop_front();
        // исследуем вершины одну за другой
        for (i = adjList[v].begin(); i != adjList[v].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
                count++;
            }
        }
    }
    cout << "\nЧисло компонент связности: " << count;
    cout << "\n";
}

void Graph_bfs::BFS(int v) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false; // все вершины не посещенные
    }
    util(v, visited);
}

int main_bfs() {
    Graph_bfs dg(9);
    dg.add_edge(0, 1);
    dg.add_edge(0, 2);
    dg.add_edge(0, 3);
    dg.add_edge(1, 2);
    dg.add_edge(1, 3);
    dg.add_edge(2, 3);
    dg.add_edge(4, 5);
    dg.add_edge(5, 6);
    dg.add_edge(7, 8);

    dg.BFS(0);

    return 0;
}

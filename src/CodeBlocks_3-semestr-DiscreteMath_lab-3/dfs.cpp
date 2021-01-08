#include "dfs.hpp"

Graph_dfs::Graph_dfs(int v) {
    V = v;
    adjList = new list<int>[V];
}

void Graph_dfs::add_edge(int v, int w) {
    adjList[v].push_back(w);
}

void Graph_dfs::util(int v, bool visited[]) {
    list<int>::iterator i;

    visited[v] = true; // текущий узел помечаем как посещенный

    cout << v + 1 << " ";


    // рекурсивно обрабатываем все соседние вершины узла
    for (i = adjList[v].begin(); i != adjList[v].end(); ++i) {
        if (!visited[*i]) {
            util(*i, visited);
        }
    }

}

void Graph_dfs::DFS() {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false; // все вершины не посещенные
    }

    int count = 0;

    cout << "Обход в глубину графа:" << "\n";
    // исследуем вершины одну за другой
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            util(i, visited);
            count++;
        }
    }
    cout << "\nЧисло компонент связности: " << count;
    cout << "\n";
}

int main_dfs() {
    Graph_dfs dg(9);
    dg.add_edge(0, 1);
    dg.add_edge(0, 2);
    dg.add_edge(0, 3);
    dg.add_edge(1, 2);
    dg.add_edge(1, 3);
    dg.add_edge(2, 3);
    dg.add_edge(4, 5);
    dg.add_edge(5, 6);
    dg.add_edge(7, 8);

    dg.DFS();

    return 0;
}

#include "prim.hpp"

Graph_prim::Graph_prim(int v) {
    V = v;
    visited = new int[V];
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }
    vertexes = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    vector<vector<int>> g(V, vector<int>(V, 0));
    G = g;
    T.clear();
}

void Graph_prim::add_edge(int u, int v, int w) {
    G[u][v] = G[v][u] = w;
}

int Graph_prim::min_node(int visited[]) {
    int result;
    int min = INT_MAX;

    for (int i = 0; i < V; i++) {
        if (visited[i]) {
            for (int j = 0; j < V; j++) {
                if (G[i][j] && !visited[j]) {
                    if (G[i][j] < min) {
                        min = G[i][j];
                        result = i * 10 + j;
                    }
                }
            }
        }
    }
    return result;
}

void Graph_prim::prim(int v) {
    int num = V - 1;
    int i, j, r;

    visited[v] = 1;
    while (num > 0) {
        r = min_node(visited);
        i = r / 10;
        j = r % 10;
        T.push_back(make_pair(G[i][j], graph_edge(i, j)));
        visited[j] = 1;
        num--;
    }
}

void Graph_prim::display() {
    cout << "Минимальное остовное дереро (алгоритм Прима):" << "\n";
    cout << "Ребро :" << " Вес" << "\n";
    for (int i = 0; i < T.size(); i++) {
        cout << vertexes[T[i].second.first] << " - " << vertexes[T[i].second.second] << " : " << T[i].first << "\n";
    }
}

int main_prim() {
    Graph_prim gmst(7);
    gmst.add_edge(0, 1, 2);
    gmst.add_edge(0, 2, 4);
    gmst.add_edge(0, 3, 7);
    gmst.add_edge(0, 5, 5);
    gmst.add_edge(1, 4, 3);
    gmst.add_edge(1, 3, 6);
    gmst.add_edge(1, 6, 8);
    gmst.add_edge(2, 5, 6);
    gmst.add_edge(3, 5, 4);
    gmst.add_edge(3, 6, 6);
    gmst.add_edge(4, 6, 7);
    gmst.add_edge(5, 6, 6);

    gmst.prim(0);
    gmst.display();

    return 0;
}

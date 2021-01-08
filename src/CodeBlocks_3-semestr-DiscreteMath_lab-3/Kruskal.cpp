#include "Kruskal.hpp"

Graph_kruskal::Graph_kruskal(int V) {
    parent = new int[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
    vertexes = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    G.clear();
    T.clear();
}

void Graph_kruskal::add_edge(int u, int v, int w) {
    G.push_back(make_pair(w, graph_edge(u, v)));
}

int Graph_kruskal::find_set(int i) {
    if (i == parent[i]) {
        return i;
    }
    else { // рекурсивно находим родителя
        return find_set(parent[i]);
    }
}

void Graph_kruskal::union_set(int u, int v) {
    parent[u] = parent[v];
}

void Graph_kruskal::kruskal() {
    int i, uSt, vEd;

    // сортировка ребер по весам
    sort(G.begin(), G.end());

    for (i = 0; i < G.size(); i++) {
        uSt = find_set(G[i].second.first);
        vEd = find_set(G[i].second.second);
        if (uSt != vEd) {
            T.push_back(G[i]);
            union_set(uSt, vEd);
        }
    }
}

void Graph_kruskal::display() {
    cout << "Минимальное остовное дереро (алгоритм Крускала):" << "\n";
    cout << "Ребро :" << " Вес" << "\n";
    for (int i = 0; i < T.size(); i++) {
        cout << vertexes[T[i].second.first] << " - " << vertexes[T[i].second.second] << " : " << T[i].first << "\n";
    }
}

int main_kruskal() {
    Graph_kruskal gmst(7);
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

    gmst.kruskal();
    gmst.display();

    return 0;
}

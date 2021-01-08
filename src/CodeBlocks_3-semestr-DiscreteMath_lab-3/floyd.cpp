#include "floyd.hpp"

Graph_floyd::Graph_floyd(int v) {
    V = v;
    vector<vector<int>> g(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g[i][j] = (i == j) ? 0 : 1000;
        }
    }
    G = g;
}

void Graph_floyd::add_edge(int u, int v, int w) {
    u--, v--;
    G[u][v] = G[v][u] = w;
}

void Graph_floyd::floyd() {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

void Graph_floyd::display() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << setw(4) << G[i][j] << " ";
        }
        cout << "\n";
    }
}

int main_floyd() {
    Graph_floyd gf(7);
    gf.add_edge(1, 2, 5);
    gf.add_edge(1, 3, 4);
    gf.add_edge(2, 4, 3);
    gf.add_edge(2, 5, 6);
    gf.add_edge(2, 6, 6);
    gf.add_edge(2, 7, 8);
    gf.add_edge(3, 5, 5); // ???
    gf.add_edge(3, 6, 7);
    gf.add_edge(4, 6, 4);
    gf.add_edge(5, 6, 4);
    gf.add_edge(6, 7, 3);

    gf.floyd();
    gf.display();

    return 0;
}

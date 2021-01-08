#include "pruefer.hpp"

Graph_pruefer::Graph_pruefer(int v) {
    V = v;
    E = V - 1;
    vector<int> d(V, 0);
    Degree = d;
    Code.clear();
    D.clear();
}

void Graph_pruefer::add_edge(int u, int v) {
    G.push_back(make_pair(u, v));
    Degree[u]++;
    Degree[v]++;
}

void Graph_pruefer::display() {
    cout << "Исходное дерево:\n";
    for (int i = 0; i < G.size(); i++) {
        cout << G[i].first << " " << G[i].second << "\n";
    }

    cout << "Код Прюфера: ";
    for (int i = 0; i < Code.size(); i++) {
        cout << Code[i] << " ";
    }
    cout << "\n";

    cout << "Декодированное дерево:\n";
    for (int i = 0; i < D.size(); i++) {
        cout << D[i].first << " " << D[i].second << "\n";
    }
}

void Graph_pruefer::prufer_encode() {
    int x;
    for (int i = 0; i < V - 2; i++) {
        int min = INT_MAX;
        // выбрать вершину с наименьшим индексом и равную 1
        for (int j = 0; j < E; j++) {
            if (Degree[G[j].first] == 1 && Degree[G[j].second] > 0) {
                if (min > G[j].first) {
                    min = G[j].first;
                    x = j;
                }
            }
            if (Degree[G[j].second] == 1 && Degree[G[j].first] > 0) {
                if (min > G[j].second) {
                    min = G[j].second;
                    x = j;
                }
            }
        }
        // уменьшить значение вершин на 1
        if (Degree[G[x].first] > 0) {
            Degree[G[x].first]--;
        }
        if (Degree[G[x].second] > 0) {
            Degree[G[x].second]--;
        }

        // сохранить вершину, из которой удаляется лист
        if (Degree[G[x].first] == 0) {
            Code.push_back(G[x].second);
        }
        else {
            Code.push_back(G[x].first);
        }
    }
}

void Graph_pruefer::prufer_decode() {
    int n = (int)Code.size() + 2;
    vector<int> degree(n, 1);
    for (int i = 0; i < n - 2; ++i) {
        ++degree[Code[i]];
    }

    set<int> leaves;
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 1) {
            leaves.insert(i);
        }
    }

    for (int i = 0; i < n - 2; ++i) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());
        int v = Code[i];
        D.push_back(make_pair(leaf, v));
        if (--degree[v] == 1) {
            leaves.insert(v);
        }
    }
    D.push_back(make_pair(*leaves.begin(), *--leaves.end()));
}

int main_pruefer() {
    Graph_pruefer gp(13);
    gp.add_edge(0, 1);
    gp.add_edge(0, 2);
    gp.add_edge(1, 3);
    gp.add_edge(1, 4);
    gp.add_edge(2, 5);
    gp.add_edge(2, 6);
    gp.add_edge(4, 7);
    gp.add_edge(7, 8);
    gp.add_edge(7, 9);
    gp.add_edge(9, 10);
    gp.add_edge(9, 11);
    gp.add_edge(11, 12);

    gp.prufer_encode();
    gp.prufer_decode();
    gp.display();

    return 0;
}

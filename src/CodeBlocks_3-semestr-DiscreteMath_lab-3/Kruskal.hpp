#ifndef __KRUSKAL_H__
    #define __KRUSKAL_H__

    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    #define graph_edge pair<int, int>

    class Graph_kruskal
    {
        private:
            int V; // количество вершин
            vector<pair<int, graph_edge>> G; // граф
            vector<pair<int, graph_edge>> T; // минимальное остовное дерево
            int* parent;
            vector<char> vertexes;
        public:
            Graph_kruskal(int V);
            void add_edge(int u, int v, int w);
            int find_set(int i);
            void union_set(int u, int v);
            void kruskal();
            void display();
    };

    int main_kruskal();
#endif // __KRUSKAL_H__

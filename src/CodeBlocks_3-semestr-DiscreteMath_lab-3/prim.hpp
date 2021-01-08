#ifndef __PRIM_H__
    #define __PRIM_H__

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <climits>

    using namespace std;

    #define graph_edge pair<int, int>

    class Graph_prim {
        private:
            // количество вершин
            int V;
            vector<vector<int>> G; // граф
            vector<pair<int, graph_edge>> T; // минимальное остовное дерево
            int* visited;
            vector<char> vertexes;
        public:
            Graph_prim(int v);
            void add_edge(int u, int v, int w);
            int min_node(int visited[]);
            void prim(int v);
            void display();
    };

    int main_prim();
#endif // __PRIM_H__

#ifndef __FLOYD_H__
    #define __FLOYD_H__

    #include <vector>
    #include <iostream>
    #include <iomanip>

    using namespace std;

    class Graph_floyd
    {
        private:
            int V; // количество вершин
            vector<vector<int>> G; // граф
        public:
            Graph_floyd(int v);
            void add_edge(int u, int v, int w);
            void floyd();
            void display();
    };

    int main_floyd();
#endif // __FLOYD_H__

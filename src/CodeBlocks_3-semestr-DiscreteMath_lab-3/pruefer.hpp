#ifndef __PRUEFER_H__
    #define __PRUEFER_H__

    #include <iostream>
    #include <vector>
    #include <set>
    #include <climits>

using namespace std;

    class Graph_pruefer
    {
        private:
            int V; // количество вершин
            int E;
            vector<pair<int, int>> G; // граф исходный
            vector<pair<int, int>> D; // граф декодированный
            vector<int> Degree;
            vector<int> Code;
        public:
            Graph_pruefer(int v);
            void add_edge(int u, int v);
            void prufer_encode();
            void prufer_decode();
            void display();
    };

    int main_pruefer();
#endif // __PRUEFER_H__

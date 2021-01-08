#ifndef __BFS_H__
    #define __BFS_H__

    #include <iostream>
    #include <list>

    using namespace std;

    class Graph_bfs
    {
        private:
            int V; // количество вершин
            list<int>* adjList;
            void util(int v, bool visited[]);
        public:
            Graph_bfs(int v);
            void add_edge(int v, int w);
            void BFS(int v);
    };

    int main_bfs();
#endif // __BFS_H__

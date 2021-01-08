#ifndef __DFS_H__
    #define __DFS_H__

    #include <iostream>
    #include <list>

    using namespace std;

    class Graph_dfs
    {
        private:
            int V; // количество вершин
            list<int>* adjList;
            void util(int v, bool visited[]);
        public:
            Graph_dfs(int v);
            void add_edge(int v, int w);
            void DFS();
    };

    int main_dfs();
#endif // __DFS_H__

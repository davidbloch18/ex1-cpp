#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "graph.h"

namespace graph
{

    class Algorithms
    {
    public:
        static Graph bfs(Graph &g, int start);
        static Graph dfs(Graph &g, int start);
        static Graph dijkstra(Graph &g, int start);
        static Graph prim(Graph &g);
        static Graph kruskal(Graph &g);
    };

} // namespace graph

#endif

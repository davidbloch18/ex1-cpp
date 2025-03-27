#include <iostream>
#include "graph.hpp"
#include "algorithms.hpp"

int main()
{
    graph::Graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);

    std::cout << "Graph:\n";
    g.print_graph();

    std::cout << "\nBFS Tree from Node 0:\n";
    graph::Graph bfsTree = graph::Algorithms::bfs(g, 0);
    bfsTree.print_graph();

    std::cout << "\nDFS Tree from Node 0:\n";
    graph::Graph dfsTree = graph::Algorithms::dfs(g, 0);
    dfsTree.print_graph();

    std::cout << "\nDijkstra's Shortest Path Tree from Node 0:\n";
    graph::Graph dijkstraTree = graph::Algorithms::dijkstra(g, 0);
    dijkstraTree.print_graph();

    std::cout << "\nMinimum Spanning Tree (Prim's Algorithm):\n";
    graph::Graph primTree = graph::Algorithms::prim(g);
    primTree.print_graph();

    std::cout << "\nMinimum Spanning Tree (Kruskal's Algorithm):\n";
    graph::Graph kruskalTree = graph::Algorithms::kruskal(g);
    kruskalTree.print_graph();

    return 0;
}

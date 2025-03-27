#ifndef GRAPH_H
#define GRAPH_H

namespace graph
{

    class Graph
    {
    private:
        int numVertices;
        int **adjMatrix;

    public:
        Graph(int vertices);
        ~Graph();
        void addEdge(int src, int dest, int weight = 1);
        void removeEdge(int src, int dest);
        void print_graph();
        int getVertices() { return numVertices; }
        int **getAdjMatrix() { return adjMatrix; }
    };

} // namespace graph

#endif

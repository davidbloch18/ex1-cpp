#include "graph.h"
#include <iostream>

namespace graph
{

    Graph::Graph(int vertices)
    {
        numVertices = vertices;
        adjMatrix = new int *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new int[numVertices]{0};
        }
    }

    Graph::~Graph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void Graph::addEdge(int src, int dest, int weight)
    {
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
    }

    void Graph::removeEdge(int src, int dest)
    {
        if (adjMatrix[src][dest] == 0)
            throw std::runtime_error("Edge does not exist.");
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0;
    }

    void Graph::print_graph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

} // namespace graph

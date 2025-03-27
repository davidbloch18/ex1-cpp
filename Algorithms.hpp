#include "algorithms.h"
#include "ds.h"
#include <iostream>
#include <limits>

namespace graph
{

    // חיפוש BFS
    Graph Algorithms::bfs(Graph &g, int start)
    {
        int n = g.getVertices();
        Graph tree(n);
        ds::Queue queue(n);
        bool *visited = new bool[n]{false};

        queue.enqueue(start);
        visited[start] = true;

        while (!queue.isEmpty())
        {
            int v = queue.dequeue();
            for (int i = 0; i < n; i++)
            {
                if (g.getAdjMatrix()[v][i] != 0 && !visited[i])
                {
                    tree.addEdge(v, i, g.getAdjMatrix()[v][i]);
                    queue.enqueue(i);
                    visited[i] = true;
                }
            }
        }

        delete[] visited;
        return tree;
    }

    // חיפוש DFS
    void dfsUtil(Graph &g, Graph &tree, bool *visited, int v)
    {
        visited[v] = true;
        for (int i = 0; i < g.getVertices(); i++)
        {
            if (g.getAdjMatrix()[v][i] != 0 && !visited[i])
            {
                tree.addEdge(v, i, g.getAdjMatrix()[v][i]);
                dfsUtil(g, tree, visited, i);
            }
        }
    }

    Graph Algorithms::dfs(Graph &g, int start)
    {
        int n = g.getVertices();
        Graph tree(n);
        bool *visited = new bool[n]{false};

        dfsUtil(g, tree, visited, start);

        delete[] visited;
        return tree;
    }

    // אלגוריתם דייקסטרה
    Graph Algorithms::dijkstra(Graph &g, int start)
    {
        int n = g.getVertices();
        Graph tree(n);
        ds::PriorityQueue pq;
        int *dist = new int[n];
        bool *visited = new bool[n]{false};

        for (int i = 0; i < n; i++)
            dist[i] = std::numeric_limits<int>::max();
        dist[start] = 0;
        pq.insert(start, 0);

        while (!pq.isEmpty())
        {
            int u = pq.extractMin();
            if (visited[u])
                continue;
            visited[u] = true;

            for (int v = 0; v < n; v++)
            {
                if (g.getAdjMatrix()[u][v] != 0 && !visited[v])
                {
                    int newDist = dist[u] + g.getAdjMatrix()[u][v];
                    if (newDist < dist[v])
                    {
                        dist[v] = newDist;
                        pq.insert(v, newDist);
                        tree.addEdge(u, v, g.getAdjMatrix()[u][v]);
                    }
                }
            }
        }

        delete[] dist;
        delete[] visited;
        return tree;
    }

    // אלגוריתם פרים
    Graph Algorithms::prim(Graph &g)
    {
        int n = g.getVertices();
        Graph mst(n);
        int *key = new int[n];
        bool *inMST = new bool[n]{false};
        int *parent = new int[n];

        for (int i = 0; i < n; i++)
            key[i] = std::numeric_limits<int>::max();
        key[0] = 0;
        parent[0] = -1;

        ds::PriorityQueue pq;
        pq.insert(0, 0);

        while (!pq.isEmpty())
        {
            int u = pq.extractMin();
            inMST[u] = true;

            for (int v = 0; v < n; v++)
            {
                if (g.getAdjMatrix()[u][v] != 0 && !inMST[v] && g.getAdjMatrix()[u][v] < key[v])
                {
                    key[v] = g.getAdjMatrix()[u][v];
                    pq.insert(v, key[v]);
                    parent[v] = u;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (parent[i] != -1)
                mst.addEdge(parent[i], i, g.getAdjMatrix()[parent[i]][i]);
        }

        delete[] key;
        delete[] inMST;
        delete[] parent;
        return mst;
    }

    // אלגוריתם קרוסקל
    Graph Algorithms::kruskal(Graph &g)
    {
        int n = g.getVertices();
        Graph mst(n);
        ds::UnionFind uf(n);

        struct Edge
        {
            int src, dest, weight;
        };

        Edge *edges = new Edge[n * n];
        int edgeCount = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (g.getAdjMatrix()[i][j] != 0)
                {
                    edges[edgeCount++] = {i, j, g.getAdjMatrix()[i][j]};
                }
            }
        }

        for (int i = 0; i < edgeCount - 1; i++)
        {
            for (int j = 0; j < edgeCount - i - 1; j++)
            {
                if (edges[j].weight > edges[j + 1].weight)
                {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < edgeCount; i++)
        {
            if (uf.find(edges[i].src) != uf.find(edges[i].dest))
            {
                mst.addEdge(edges[i].src, edges[i].dest, edges[i].weight);
                uf.unite(edges[i].src, edges[i].dest);
            }
        }

        delete[] edges;
        return mst;
    }

} // namespace graph

#ifndef DS_H
#define DS_H

namespace ds
{

    // מבנה נתונים: תור (Queue) ללא STL
    class Queue
    {
    private:
        int *arr;
        int front, rear, capacity;

    public:
        Queue(int size);
        ~Queue();
        void enqueue(int value);
        int dequeue();
        bool isEmpty();
    };

    // מבנה נתונים: תור עדיפויות (Priority Queue) ללא STL
    class PriorityQueue
    {
    private:
        struct Node
        {
            int value;
            int priority;
            Node *next;
        };
        Node *head;

    public:
        PriorityQueue();
        ~PriorityQueue();
        void insert(int value, int priority);
        int extractMin();
        bool isEmpty();
    };

    // מבנה נתונים: Union-Find (ללא STL)
    class UnionFind
    {
    private:
        int *parent, *rank, size;

    public:
        UnionFind(int n);
        ~UnionFind();
        int find(int x);
        void unite(int x, int y);
    };

} // namespace ds

#endif

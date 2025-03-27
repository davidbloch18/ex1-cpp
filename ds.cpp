#include "ds.hpp"
#include <iostream>

namespace ds
{

    // מימוש תור (Queue)
    Queue::Queue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    Queue::~Queue()
    {
        delete[] arr;
    }

    void Queue::enqueue(int value)
    {
        if (rear == capacity - 1)
            return;
        if (front == -1)
            front = 0;
        arr[++rear] = value;
    }

    int Queue::dequeue()
    {
        if (front == -1 || front > rear)
            return -1;
        return arr[front++];
    }

    bool Queue::isEmpty()
    {
        return front == -1 || front > rear;
    }

    // מימוש תור עדיפויות (Priority Queue)
    PriorityQueue::PriorityQueue() : head(nullptr) {}

    PriorityQueue::~PriorityQueue()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void PriorityQueue::insert(int value, int priority)
    {
        Node *newNode = new Node{value, priority, nullptr};
        if (!head || priority < head->priority)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int PriorityQueue::extractMin()
    {
        if (!head)
            return -1;
        int value = head->value;
        Node *temp = head;
        head = head->next;
        delete temp;
        return value;
    }

    bool PriorityQueue::isEmpty()
    {
        return head == nullptr;
    }

    // מימוש Union-Find
    UnionFind::UnionFind(int n)
    {
        size = n;
        parent = new int[n];
        rank = new int[n]();
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    UnionFind::~UnionFind()
    {
        delete[] parent;
        delete[] rank;
    }

    int UnionFind::find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // דחיסת נתיבים
        return parent[x];
    }

    void UnionFind::unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

} // namespace ds

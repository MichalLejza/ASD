#ifndef EVERYTHING_QUEUE_HPP
#define EVERYTHING_QUEUE_HPP

#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/LinkedNode.cpp"

namespace Queue
{
    template<typename T>
    class Queue
    {
        Node::LinkedNode<T> *head;
        ssize_t size{};

    public:
        Queue();
        explicit Queue(T data);
        explicit Queue(Node::LinkedNode<T> *headNode);
        ~Queue() = default;
        T getHead();
        template<typename ...Args>
        void insert(const T &value, Args ... args);
        void push(T data);
        void push(Node::LinkedNode<T> *node);
        void pop();
        void clear();
        bool empty();
        ssize_t getSize();
        void printQueue();
    };

    template<typename T>
    class PriorityQueue
    {
        Node::LinkedNode<std::pair<T, size_t>> *head;
        ssize_t size;
    public:
        PriorityQueue();
        ~PriorityQueue() = default;
        explicit PriorityQueue(Node::LinkedNode<std::pair<T, size_t>> *node);
        PriorityQueue(T value, size_t priority);
        explicit PriorityQueue(std::pair<T, size_t> node);
        void insert(Node::LinkedNode<std::pair<T, size_t>> *node);
        void insert(T data, size_t priority);
        void dequeue();
        void increaseKey(T data, size_t priority);
        void increaseKey(Node::LinkedNode<std::pair<T, size_t>> *node, size_t priority);
        void decreaseKey(T data, size_t priority);
        void decreaseKey(Node::LinkedNode<std::pair<T, size_t>> *node, size_t priority);
        void clear();
        bool empty();
        ssize_t getSize();
        void print();
    };
}

#endif //EVERYTHING_QUEUE_HPP

#ifndef EVERYTHING_HEAP_HPP
#define EVERYTHING_HEAP_HPP

#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/HeapNode.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Tree/Tree.cpp"

#pragma once

namespace Heap
{
    template<typename T>
    class Heap
    {
    protected:
        Node::HeapNode<T> *root, *lastElement;
        std::vector<Node::HeapNode<T> *> elements;
        virtual void heapifyUp() {};
        virtual void heapifyDown() {};
    public:
        virtual Node::HeapNode<T> *getTop() {};
        virtual Node::HeapNode<T> *getLast() {};
        virtual std::vector<Node::HeapNode<T> *>getArray() {};
        virtual T getTopValue() {};
        virtual void slowConstruct(std::vector<T> vec) {};
        virtual void fastConstruct(std::vector<T> vec) {};
        virtual void addNode(T data) {};
        virtual void minDelete() {};
        virtual void printArray() {};
        virtual void clear() {};
        virtual int getHeight() {};
    };

    template<typename T>
    class MinHeap : public Heap<T>
    {
    protected:
        void heapifyUp();
        void heapifyDown();
    public:
        MinHeap() = default;
        ~MinHeap() = default;
        explicit MinHeap(T data);
        Node::HeapNode<T> *getTop();
        Node::HeapNode<T> *getLast();
        std::vector<Node::HeapNode<T> *>getArray();
        T getTopValue();
        void slowConstruct(std::vector<T> vec);
        void fastConstruct(std::vector<T> vec);
        void addNode(T data);
        void minDelete();
        void printArray();
        void clear();
        int getHeight();
    };
}

#endif //EVERYTHING_HEAP_HPP

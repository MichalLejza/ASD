#ifndef EVERYTHING_NODE_HPP
#define EVERYTHING_NODE_HPP

#include "iostream"
#include "memory"
#include "cstdlib"
#include "limits"
#include "set"
#include "string"
#include "utility"
#include "functional"

#pragma once

namespace Node
{
    template<typename T>
    class Node
    {
    protected:
        T data;
    public:
        Node() = default;
        explicit Node(T data);
        ~Node() = default;
        void printNode();
        void setData(T data);
        T getData() const;
        void applyFunction(const std::function<void(T&)> &lambda);
        bool applyFilter(const std::function<bool(T&)> &lambda);
        [[nodiscard]] bool isInteger() const;
        [[nodiscard]] bool isDouble() const;
        [[nodiscard]] bool isString() const;
        bool isEqual(Node<T> *node);
        bool isGreaterThen(Node<T> *node);
        bool isLesserThen(Node<T> *node);
    };

    template<typename T>
    class LinkedNode : public Node<T>
    {
        LinkedNode<T> *next;
    public:
        LinkedNode() = default;
        explicit LinkedNode(T data);
        ~LinkedNode() = default;
        void setNext(LinkedNode<T> *next);
        void setNext(T data);
        LinkedNode<T> *getNext();
    };

    template<typename T>
    class DoubleLinkedNode : public Node<T>
    {
        DoubleLinkedNode<T> *next, *previous;
    public:
        DoubleLinkedNode() = default;
        explicit DoubleLinkedNode(T data);
        ~DoubleLinkedNode() = default;
        void setNext(DoubleLinkedNode<T> *next);
        void setNext(T data);
        void setPrevious(DoubleLinkedNode<T> *previous);
        void setPrevious(T data);
        DoubleLinkedNode<T> *getNext();
        DoubleLinkedNode<T> *getPrevious();
    };

    template<typename T>
    class BNode : public Node<T>
    {
    protected:
        BNode<T> *left, *right;
        ssize_t height{};

    public:
        BNode() = default;
        explicit BNode(T data);
        BNode(T data, ssize_t height);
        ~BNode() = default;
        void setLeft(BNode<T> *node);
        void setLeft(T data);
        void setRight(BNode<T> *node);
        void setRight(T data);
        BNode<T> *getLeft();
        BNode<T> *getRight();
        void setHeight(ssize_t h);
        ssize_t getHeight();
        int getBalance();
    };

    template<typename T>
    class GraphNode : public Node<T>
    {
    public:
        bool visited {};
        std::set<std::pair<GraphNode<T> *, ssize_t>> connectedNodes;
    public:
        GraphNode() = default;
        explicit GraphNode(T data);
        ~GraphNode() = default;
        std::set<std::pair<GraphNode<T> *, ssize_t>> getConnectedNodes();
        bool isVisited();
        void setVisited(bool value);
        void changeWeight(T data, ssize_t weight);
        void addConnection(std::pair<GraphNode<T> *, ssize_t> node);
        void addConnection(GraphNode<T> *node, ssize_t weight = 0);
        void addConnection(T data, ssize_t weight = 0);
        void deleteNode(GraphNode<T> * node);
        void deleteNode(T data);
        void printConnectedNodes();
        ssize_t getSetSize();
    };

    template<typename T>
    class HeapNode : public Node<T>
    {
        HeapNode<T> *left, *right, *next, *previous, *parent;
        ssize_t height {};
    public:
        HeapNode() = default;
        ~HeapNode() = default;
        explicit HeapNode(T data);
        HeapNode(T data, ssize_t h);
        HeapNode<T> *getNext();
        HeapNode<T> *getPrevious();
        HeapNode<T> *getParent();
        HeapNode<T> *getLeft();
        HeapNode<T> *getRight();
        void setNext(T data);
        void setNext(HeapNode<T> *node);
        void setPrevious(T data);
        void setPrevious(HeapNode<T> *node);
        void setParent(HeapNode<T> *node);
        void setLeft(T data);
        void setLeft(HeapNode<T> *node);
        void setRight(T data);
        void setRight(HeapNode<T> *node);
        void setHeight(ssize_t h);
        ssize_t getHeight();
    };
}

#endif //EVERYTHING_NODE_HPP
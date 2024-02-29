#include "Graph.hpp"
#pragma once


template<typename T>
Graph::UndirectedGraph<T>::UndirectedGraph()
{
    this -> nodes = std::set<Node::GraphNode<T> *>();
}

template<typename T>
Graph::UndirectedGraph<T>::UndirectedGraph(std::map<T, std::vector<T>> &connection)
{
    this -> nodes = std::set<Node::GraphNode<T> *>();
    addConnection(connection);
}

template<typename T>
void Graph::UndirectedGraph<T>::addConnection(std::map<T, std::vector<T>> &connections)
{
    for (auto &node : connections)
    {
        auto *A = new Node::GraphNode<T>(node.first);
        std::vector<T> &values = node.second;
        for (auto a : this -> nodes)
            if (a -> getData() == A -> getData())
                A = a;

        for (auto a : values)
        {
            auto *B = new Node::GraphNode<T>(a);
            for (auto b : this -> nodes)
                if (b -> getData() == B -> getData())
                    B = b;
            A -> addConnection(B);
            this -> nodes.insert(A);
            this -> nodes.insert(B);
        }
    }
}

template<typename T>
void Graph::UndirectedGraph<T>::addNode(Node::GraphNode<T> *node, Node::GraphNode<T> *goal)
{
    node -> addConnection(goal);
    this -> nodes.insert(node);
    this -> nodes.insert(goal);
}

template<typename T>
void Graph::UndirectedGraph<T>::addNode(T one, T two)
{
    auto *A = new Node::GraphNode<T>(one);
    auto *B = new Node::GraphNode<T>(two);
    for (auto a : this -> nodes)
    {
        if (a -> getData() == one)
            A = a;
        if (a -> getData() == two)
            B = a;
    }
    addConnection(A, B);
}

template<typename T>
void Graph::UndirectedGraph<T>::deleteNode(Node::GraphNode<T> *node)
{
    for (auto n : this -> nodes)
        n -> deleteNode(node);
    this -> nodes.erase(node);
}

template<typename T>
void Graph::UndirectedGraph<T>::deleteNode(T value)
{
    for (auto a : this -> nodes)
        a -> deleteNode(value);
    for (auto a : this -> nodes)
        if (a -> getData() == value)
            this -> nodes.erase(a);
}

template<typename T>
void Graph::UndirectedGraph<T>::printGraph()
{
    for (auto n : this -> nodes)
    {
        std::cout << "[" << n -> getData() << "] -> ";
        if (n -> getSetSize() != 0)
            n -> printConnectedNodes();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
int Graph::UndirectedGraph<T>::getSize()
{
    return this -> nodes.size();
}

template<typename T>
Node::GraphNode<T> *Graph::UndirectedGraph<T>::getNode(T data)
{
    auto *temp = new Node::GraphNode<T>();
    for (auto a : this -> nodes)
        if (a -> getData() == data)
            temp = a;
    return temp;
}

template<typename T>
std::set<Node::GraphNode<T> *> Graph::UndirectedGraph<T>::getNodes()
{
    return this -> nodes;
}

template<typename T>
void Graph::UndirectedGraph<T>::clear()
{
    this -> nodes.clear();
}



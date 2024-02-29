#include "Graph.hpp"
#pragma once


template<typename T>
Graph::WeightedGraph<T>::WeightedGraph()
{
    this -> nodes = std::set<Node::GraphNode<T> *>();
}

template<typename T>
void Graph::WeightedGraph<T>::addNode(std::map<T, std::pair<T, ssize_t>> &connections)
{
    for (auto &node : connections)
    {
        auto *A = new Node::GraphNode<T>(node.first);
        std::vector<std::pair<T, ssize_t>> &values = node.second;
        for (auto a : this -> nodes)
            if (a -> getData() == A -> getData())
                A = a;

        for (auto a : values)
        {
            auto *B = new Node::GraphNode<T>(a.first);
            for (auto b : this -> nodes)
                if (b -> getData() == B -> getData())
                    B = b;
            A -> addConnection(B, a.second);
            this -> nodes.insert(A);
            this -> nodes.insert(B);
        }
    }
}

template<typename T>
void
Graph::WeightedGraph<T>::addNode(Node::GraphNode<T> *node, Node::GraphNode<T> *goal, ssize_t weight)
{
    node -> addConnection(goal, weight);
    this -> nodes.insert(node);
    this -> nodes.insert(goal);
}

template<typename T>
void Graph::WeightedGraph<T>::addNode(T one, T two, ssize_t weight)
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
    addNode(A, B, weight);
}

template<typename T>
void Graph::WeightedGraph<T>::deleteNode(T value)
{
    for (auto a : this -> nodes)
        a -> deleteNode(value);
    for (auto a : this -> nodes)
        if (a -> getData() == value)
            this -> nodes.erase(a);
}

template<typename T>
void Graph::WeightedGraph<T>::deleteNode(Node::GraphNode<T> *node)
{
    for (auto n : this -> nodes)
        n -> deleteNode(node);
    this -> nodes.erase(node);
}

template<typename T>
void Graph::WeightedGraph<T>::changeWeight(T one, T two, ssize_t weight)
{
    for (auto a : this -> nodes)
        if (a -> getData() == one)
            a -> changeWeight(one, two, weight);
}

template<typename T>
void Graph::WeightedGraph<T>::printGraph()
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
int Graph::WeightedGraph<T>::getSize()
{
    return this -> nodes.size();
}

template<typename T>
Node::GraphNode<T> *Graph::WeightedGraph<T>::getNode(T data)
{
    auto *temp = new Node::GraphNode<T>();
    for (auto a : this -> nodes)
        if (a -> getData() == data)
            temp = a;
    return temp;
}

template<typename T>
std::set<Node::GraphNode<T> *> Graph::WeightedGraph<T>::getNodes()
{
    return this -> nodes;
}

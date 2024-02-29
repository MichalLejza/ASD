#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.hpp"
#pragma once

template<typename T>
Node::GraphNode<T>::GraphNode(T data) : Node<T>(data), visited(false)
{
    this -> connectedNodes = std::set<std::pair<GraphNode<T> *, ssize_t>>();
}

template<typename T>
std::set<std::pair<Node::GraphNode<T> *, ssize_t>> Node::GraphNode<T>::getConnectedNodes()
{
    return this -> connectedNodes;
}

template<typename T>
void Node::GraphNode<T>::setVisited(bool value)
{
    this -> visited = value;
}

template<typename T>
bool Node::GraphNode<T>::isVisited()
{
    return this -> visited;
}

template<typename T>
void Node::GraphNode<T>::changeWeight(T data, ssize_t weight)
{
    for (auto a : this -> connectedNodes)
        if (a.first -> getData == data)
            a.second = weight;
}

template<typename T>
void Node::GraphNode<T>::addConnection(std::pair<GraphNode < T> * , ssize_t> node)
{
    bool add = true;
    for (auto a : this -> connectedNodes)
        if (node.first -> isEqual(a.first))
            add = false;
    if (add)
        this -> connectedNodes.insert(node);
}

template<typename T>
void Node::GraphNode<T>::addConnection(GraphNode<T> *node, ssize_t weight)
{
    bool add = true;
    for (auto a : this -> connectedNodes)
        if (node -> isEqual(a.first))
            add = false;
    if (add)
    {
        std::pair<GraphNode < T> *, ssize_t > para{node, weight};
        this -> connectedNodes.insert(para);
    }
}

template<typename T>
void Node::GraphNode<T>::addConnection(T data, ssize_t weight)
{
    auto *node = new GraphNode<T>(data);
    bool add = true;
    for (auto a : this -> connectedNodes)
        if (node -> isEqual(a.first))
            add = false;
    if (add)
    {
        std::pair<GraphNode < T> *, ssize_t > para{node, weight};
        this -> connectedNodes.insert(para);
    }
}

template<typename T>
void Node::GraphNode<T>::deleteNode(T data)
{
    for (auto a : this -> connectedNodes)
        if (a.first -> getData() == data)
            this -> connectedNodes.erase(a);
}

template<typename T>
void Node::GraphNode<T>::deleteNode(GraphNode<T> *node)
{
    this -> connectedNodes.erase(node);
}

template<typename T>
void Node::GraphNode<T>::printConnectedNodes()
{
    for (auto a : this -> connectedNodes)
        std::cout << "[ " << a.first -> data << " , " << a.second << " ]  ";
}

template<typename T>
ssize_t Node::GraphNode<T>::getSetSize()
{
    return this -> connectedNodes.size();
}


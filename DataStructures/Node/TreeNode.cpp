#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.hpp"
#pragma once

template<typename T>
void Node::TreeNode<T>::printConnectedNodes()
{
    for (auto node : this -> nodes)
        std::cout << "[ " << this -> data << " ]  ";
    std::cout << std::endl;
}

template<typename T>
Node::TreeNode<T>::TreeNode(T data) : Node<T>(data)
{
    this -> nodes = std::set<TreeNode<T> *>();
}

template<typename T>
void Node::TreeNode<T>::addNode(TreeNode <T> *node)
{
    this -> nodes.insert(node);
}

template<typename T>
std::set<Node::TreeNode<T> *>Node::TreeNode<T>::getNodes()
{
    return this -> nodes;
}

template<typename T>
int Node::TreeNode<T>::nodesCounter()
{
    return this -> nodes.size();
}


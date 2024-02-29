#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.hpp"
#pragma once

template<typename T>
Node::BNode<T>::BNode(T data) : Node<T>(data), height(0), left(nullptr), right(nullptr){}

template<typename T>
Node::BNode<T>::BNode(T data, ssize_t height) : Node<T>(data), height(height), left(nullptr), right(nullptr) {}

template<typename T>
void Node::BNode<T>::setLeft(BNode<T> *node)
{
    this -> left = node;
}

template<typename T>
void Node::BNode<T>::setLeft(T data)
{
    this -> left = new BNode<T>(data);
}

template<typename T>
void Node::BNode<T>::setRight(BNode<T> *node)
{
    this -> right = node;
}

template<typename T>
void Node::BNode<T>::setRight(T data)
{
    this -> right = new BNode<T>(data);
}

template<typename T>
Node::BNode<T> *Node::BNode<T>::getLeft()
{
    return this -> left;
}

template<typename T>
Node::BNode<T> *Node::BNode<T>::getRight()
{
    return this -> right;
}

template<typename T>
void Node::BNode<T>::setHeight(ssize_t h)
{
    this -> height = h;
}

template<typename T>
ssize_t Node::BNode<T>::getHeight()
{
    return this -> height;
}

template<typename T>
int Node::BNode<T>::getBalance()
{
    return left -> getHeight() - right -> getHeight();
}















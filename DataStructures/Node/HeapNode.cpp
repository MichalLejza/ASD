#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.hpp"
#pragma once

template<typename T>
Node::HeapNode<T>::HeapNode(T data) : Node<T>(data),left(nullptr), right(nullptr), next(nullptr), previous(nullptr),parent(nullptr) ,height(0) {}

template<typename T>
Node::HeapNode<T>::HeapNode(T data, ssize_t h) : Node<T>(data), left(nullptr), right(nullptr), previous(nullptr), next(nullptr), parent(nullptr), height(h) {}

template<typename T>
Node::HeapNode <T> *Node::HeapNode<T>::getNext()
{
    return this -> next;
}

template<typename T>
void Node::HeapNode<T>::setNext(T data)
{
    this -> next = new HeapNode<T>(data);
}

template<typename T>
void Node::HeapNode<T>::setNext(HeapNode<T> *node)
{
    this -> next = node;
}

template<typename T>
Node::HeapNode <T> *Node::HeapNode<T>::getPrevious()
{
    return this -> previous;
}

template<typename T>
void Node::HeapNode<T>::setPrevious(T data)
{
    this -> previous = new HeapNode<T>(data);
}

template<typename T>
void Node::HeapNode<T>::setPrevious(HeapNode<T> *node)
{
    this -> previous = node;
}

template<typename T>
Node::HeapNode <T> *Node::HeapNode<T>::getParent()
{
    return this -> parent;
}

template<typename T>
void Node::HeapNode<T>::setParent(HeapNode<T> *node)
{
    this -> parent = node;
}

template<typename T>
Node::HeapNode <T> *Node::HeapNode<T>::getLeft()
{
    return this -> left;
}

template<typename T>
void Node::HeapNode<T>::setLeft(T data)
{
    this -> left = new HeapNode<T>(data);
}

template<typename T>
void Node::HeapNode<T>::setLeft(HeapNode<T> *node)
{
    this -> left = node;
}

template<typename T>
Node::HeapNode <T> *Node::HeapNode<T>::getRight()
{
    return this -> right;
}

template<typename T>
void Node::HeapNode<T>::setRight(T data)
{
    this -> right = new HeapNode<T>(data);
}

template<typename T>
void Node::HeapNode<T>::setRight(HeapNode<T> *node)
{
    this -> right = node;
}

template<typename T>
ssize_t Node::HeapNode<T>::getHeight()
{
    return this -> height;
}

template<typename T>
void Node::HeapNode<T>::setHeight(ssize_t h)
{
    this -> height = h;
}
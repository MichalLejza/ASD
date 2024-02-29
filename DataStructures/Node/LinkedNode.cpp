#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.hpp"
#pragma once


template<typename T>
Node::LinkedNode<T>::LinkedNode(T data) : Node<T>(data), next(nullptr) {}

template<typename T>
void Node::LinkedNode<T>::setNext(LinkedNode<T> *nextNode)
{
    this -> next = nextNode;
}

template<typename T>
void Node::LinkedNode<T>::setNext(T data)
{
    this -> next = new LinkedNode<T>(data);
}

template<typename T>
Node::LinkedNode<T>* Node::LinkedNode<T>::getNext()
{
    return this -> next;
}


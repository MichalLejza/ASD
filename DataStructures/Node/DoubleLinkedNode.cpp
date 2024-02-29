#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.hpp"
#pragma once

template<typename T>
Node::DoubleLinkedNode<T>::DoubleLinkedNode(T data) : Node<T>(data), next(nullptr), previous(nullptr) {}

template<typename T>
void Node::DoubleLinkedNode<T>::setNext(DoubleLinkedNode <T> *nextNode)
{
    this -> next = nextNode;
}

template<typename T>
void Node::DoubleLinkedNode<T>::setNext(T data)
{
    this -> next = new DoubleLinkedNode<T>(data);
}

template<typename T>
void Node::DoubleLinkedNode<T>::setPrevious(DoubleLinkedNode <T> *previousNode)
{
    this -> previous = previousNode;
}

template<typename T>
void Node::DoubleLinkedNode<T>::setPrevious(T data)
{
    this -> previous = new DoubleLinkedNode<T>(data);
}

template<typename T>
Node::DoubleLinkedNode <T> *Node::DoubleLinkedNode<T>::getNext()
{
    return this -> next;
}

template<typename T>
Node::DoubleLinkedNode <T> *Node::DoubleLinkedNode<T>::getPrevious()
{
    return this -> previous;
}


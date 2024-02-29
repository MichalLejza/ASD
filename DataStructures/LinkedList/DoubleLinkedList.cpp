#include "LinkedList.hpp"
#pragma once

template<typename T>
LinkedList::DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), size(0) {}

template<typename T>
LinkedList::DoubleLinkedList<T>::DoubleLinkedList(T data) : head(new Node::DoubleLinkedNode<T>(data)), size(0) {}

template<typename T>
LinkedList::DoubleLinkedList<T>::DoubleLinkedList(Node::DoubleLinkedNode<T> *node) : head(node), size(0) {}

template<typename T>
Node::DoubleLinkedNode<T> *LinkedList::DoubleLinkedList<T>::getHead()
{
    return this -> head;
}



template<typename T>
void LinkedList::DoubleLinkedList<T>::pushBack(T value)
{
    if (this -> head == nullptr)
        this -> head = new Node::DoubleLinkedNode<T>(value);
    else
    {
        auto *temp = this -> head;
        while (temp -> getNext() != nullptr)
            temp = temp -> getNext();
        temp -> setNext(value);
        temp -> getNext() -> setPrevious(temp);
    }
    this -> size++;
}


template<typename T>
void LinkedList::DoubleLinkedList<T>::pushBack(Node::LinkedNode<T> *node)
{
    if (node == nullptr)
        return;
    if (this -> head == nullptr)
        this -> head = node;
    else
    {
        auto *temp = this -> head;
        while (temp -> getNext() != nullptr)
            temp = temp -> getNext();
        temp -> setNext(node);
        temp -> getNext() -> setPrevious(temp);
    }
    this -> size++;
}

template<typename T>
void LinkedList::DoubleLinkedList<T>::pushFront(T value)
{
    if (this -> head == nullptr)
        this -> head = new Node::DoubleLinkedNode<T>(value);
    else
    {
        auto *temp = new Node::DoubleLinkedNode<T>(value);
        temp -> setNext(head);
        this -> head -> setPrevious(temp);
        this -> head = temp;
        delete temp;
    }
    this -> size++;
}

template<typename T>
void LinkedList::DoubleLinkedList<T>::pushFront(Node::LinkedNode<T> *node)
{
    if (node == nullptr)
        return;
    if (this -> head == nullptr)
        this -> head = node;
    else
    {
        auto *temp = node;
        temp -> setNext(head);
        this -> head -> setPrevious(temp);
        this -> head = temp;
        delete temp;
    }
    this -> size++;
}

template<typename T>
void LinkedList::DoubleLinkedList<T>::popFront()
{
    if (this -> head -> getNext() == nullptr)
    {
        this -> head = nullptr;
        this -> size = 0;
    }
    else
    {
        auto *temp = this -> head -> getNext();
        this -> head = temp;
        delete temp;
        this -> size--;
    }
}

template<typename T>
void LinkedList::DoubleLinkedList<T>::popBack()
{
    if (this -> head -> getNext() == nullptr)
    {
        this -> head = nullptr;
        this -> size = 0;
    }
    else
    {
        auto *temp = this -> head;
        while (temp -> getNext() != nullptr)
            temp = temp -> getNext();
        delete temp -> getNext();
        temp -> setNext(nullptr);
        this -> size = 0;
    }
}

template<typename T>
void LinkedList::DoubleLinkedList<T>::popElement(T value)
{

}

template<typename T>
void LinkedList::DoubleLinkedList<T>::clear()
{
    while (this -> head != nullptr)
    {
        auto *temp = this -> head;
        this -> head = this -> head -> getNext();
        delete temp;
    }
    this -> size = 0;
}

template<typename T>
void LinkedList::DoubleLinkedList<T>::print()
{
    auto *temp = this -> head;
    while (temp != nullptr)
    {
        std::cout << temp -> getData() << " <-> ";
        temp = temp -> getNext();
    }
    std::cout << "null" << std::endl;
}

template<typename T>
bool LinkedList::DoubleLinkedList<T>::isEmpty()
{
    return this -> head == nullptr;
}

template<typename T>
ssize_t LinkedList::DoubleLinkedList<T>::getSize()
{
    return this -> size;
}
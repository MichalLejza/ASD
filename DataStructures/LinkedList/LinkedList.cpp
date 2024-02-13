#include "LinkedList.hpp"
#pragma once

template<typename T>
LinkedList::LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template<typename T>
LinkedList::LinkedList<T>::LinkedList(T data) : head(new Node::LinkedNode<T>(data)), size(1) {}

template<typename T>
LinkedList::LinkedList<T>::LinkedList(Node::LinkedNode<T> *node) : head(node), size(1) {}

template<typename T>
Node::LinkedNode<T> *LinkedList::LinkedList<T>::getHead()
{
    return this -> head;
}

template<typename T>
template<typename ...Args>
void LinkedList::LinkedList<T>::insert(const T &value, Args ...args)
{
    pushBack(value);
    if constexpr (sizeof...(args) > 0)
        insert(args...);
}

template<typename T>
void LinkedList::LinkedList<T>::pushBack(T value)
{
    if(this -> head == nullptr)
        this -> head = new Node::LinkedNode<T>(value);
    else
    {
        auto *temp = new Node::LinkedNode<T>(value);
        auto current = this -> head;
        while (current -> getNext())
            current = current -> getNext();
        current -> setNext(temp);
    }
    this -> size++;
}


template<typename T>
void LinkedList::LinkedList<T>::pushBack(Node::LinkedNode<T> *node)
{
    if (node == nullptr)
        return;
    if (this -> head == nullptr)
    {
        this -> head = node;
        this -> size++;
    }
    else
    {
        auto current = this -> head;
        while (current -> getNext())
            current = current -> getNext();
        current -> setNext(node);
        this -> size++;
    }
}

template<typename T>
void LinkedList::LinkedList<T>::pushFront(T value)
{
    auto *newNode = new Node::LinkedNode<T>(value);
    newNode -> setNext(head);
    this -> head = newNode;
    this -> size++;
}


template<typename T>
void LinkedList::LinkedList<T>::pushFront(Node::LinkedNode<T> *node)
{
    node -> setNext(this -> head);
    this -> head = node;
    delete node;
    this -> size++;
}

template<typename T>
void LinkedList::LinkedList<T>::popFront()
{
    if(this -> head)
    {
        auto *temp = this -> head;
        this -> head = this -> head -> getNext();
        delete temp;
        this -> size--;
    }
}

template<typename T>
void LinkedList::LinkedList<T>::popBack()
{
    if (this -> head)
    {
        if (this -> head -> getNext() == nullptr)
        {
            delete this -> head;
            this -> head = nullptr;
            this -> size = 0;
        }
        else
        {
            auto *current = this -> head;
            while (current -> getNext() -> getNext())
                current = current -> getNext();
            delete current -> getNext();
            current -> setNext(nullptr);
            this -> size--;
        }
    }
}

template<typename T>
void LinkedList::LinkedList<T>::popElement(T value)
{
    if(this -> head != nullptr)
    {
        if(this -> head -> getData() == value)
            popFront();
        else
        {
            auto *current = this -> head;
            while (current -> getNext() != nullptr)
            {
                if(current -> getNext() -> getData() == value)
                {
                    auto *temp = current -> getNext();
                    current -> getNext() = current -> getNext() -> getNext();
                    delete temp;
                    this -> size--;
                }
                current = current -> getNext();
            }
        }
    }
}

template<typename T>
void LinkedList::LinkedList<T>::clear()
{
    while (this -> head != nullptr)
    {
        auto *temp = this -> head;
        this -> head = this -> head -> getNext();
        delete temp;
        this -> size--;
    }
}

template<typename T>
bool LinkedList::LinkedList<T>::sorted()
{
    auto *current = this -> head;
    while (current -> getNext())
    {
        if(current -> getData() > current -> getNext() -> getData())
            return false;
        current = current -> getNext();
    }
    return true;
}

template<typename T>
bool LinkedList::LinkedList<T>::isEmpty()
{
    return this -> size == 0;
}

template<typename T>
ssize_t LinkedList::LinkedList<T>::getSize()
{
    return this -> size;
}

template<typename T>
T LinkedList::LinkedList<T>::getValue()
{
    return this -> head -> getData();
}

template<typename T>
void LinkedList::LinkedList<T>::print()
{
    Node::LinkedNode<T> *current = this -> head;
    while (current)
    {
        std::cout << current -> getData() << " -> ";
        current = current -> getNext();
    }
    std::cout << std::endl;
}

template<typename T>
void LinkedList::LinkedList<T>::map(std::function<void(T&)> fun)
{
    auto *run = this -> head;
    while (run != nullptr)
    {
        run -> applyFunction(fun);
        run = run -> getNext();
    }
}

template<typename T>
void LinkedList::LinkedList<T>::filter(const std::function<bool(T &)> &fun)
{
    while (this -> head != nullptr && this -> head -> applyFilter(fun))
    {
        auto *temp = this -> head;
        this -> head = this -> head -> getNext();
        delete temp;
        this -> size--;
    }
    if (this -> head == nullptr)
    {
        this -> size = 0;
        return;
    }

    auto *run = this -> head;
    while (run -> getNext() != nullptr)
    {
        if (run -> getNext() -> applyFilter(fun))
        {
            auto temp = this -> head -> getNext();
            run -> setNext(temp -> getNext());
            delete temp;
            this -> size--;
        }
        else
            run = run -> getNext();
    }
}
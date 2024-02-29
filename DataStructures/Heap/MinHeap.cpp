#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Heap/Heap.hpp"

#pragma once

template<typename T>
Heap::MinHeap<T>::MinHeap(T data)
{
    auto *node = new Node::HeapNode<T>(data);
    this -> elements = std::vector<Node::HeapNode<T> *>();
    this -> root = node;
    this -> elements.push_back(node);
    this -> lastElement = node;
}

template<typename T>
void Heap::MinHeap<T>::addNode(T data)
{
    auto *node = new Node::HeapNode<T>(data);
    node -> setParent(nullptr);
    this -> elements.push_back(node);
    this -> lastElement = node;

    if (this -> elements.size() == 1)
    {
        this -> root = node;
    }
    else
    {
        size_t index = this -> elements.size() - 1;
        Node::HeapNode<T> *parent = this -> elements.at((index - 1) / 2);
        Node::HeapNode<T> *previous = this -> elements.at(index - 1);

        parent -> getLeft() == nullptr ? parent -> setLeft(node) : parent -> setRight(node);
        node -> setParent(parent);
        previous -> setNext(node);
        node -> setPrevious(previous);
        heapifyUp();
    }
}

template<typename T>
void Heap::MinHeap<T>::minDelete()
{
    T data = this -> lastElement -> getData();
    this -> root -> setData(data);
    auto *parent = this -> lastElement -> getParent();
    auto *previous = this -> lastElement -> getPrevious();
    previous -> setNext(nullptr);
    parent -> getRight() == nullptr ? parent -> setLeft(nullptr) : parent -> setRight(nullptr);
    delete this -> lastElement;
    this -> lastElement = previous;
    this -> elements.pop_back();
    heapifyDown();
}

template<typename T>
Node::HeapNode<T> *Heap::MinHeap<T>::getTop()
{
    return this -> root;
}

template<typename T>
Node::HeapNode<T> *Heap::MinHeap<T>::getLast()
{
    return this -> lastElement;
}

template<typename T>
std::vector<Node::HeapNode<T> *> Heap::MinHeap<T>::getArray()
{
    return this -> elements;
}

template<typename T>
T Heap::MinHeap<T>::getTopValue()
{
    return this -> root -> getData();
}

template<typename T>
void Heap::MinHeap<T>::slowConstruct(std::vector<T> vec)
{
    for (auto a : vec)
        addNode(a);
}

template<typename T>
void Heap::MinHeap<T>::fastConstruct(std::vector<T> vec)
{
    for (auto a : vec)
    {
        auto *node = new Node::HeapNode<T>(a);
        node -> setParent(nullptr);
        this -> elements.push_back(node);
        this -> lastElement = node;

        if (this -> elements.size() == 1)
            this -> root = node;
        else
        {
            size_t index = this -> elements.size() - 1;
            Node::HeapNode<T> *parent = this -> elements.at((index - 1) / 2);
            Node::HeapNode<T> *previous = this -> elements.at(index - 1);

            parent -> getLeft() == nullptr ? parent -> setLeft(node) : parent -> setRight(node);
            node -> setParent(parent);
            previous -> setNext(node);
            node -> setPrevious(previous);
        }
    }
}

template<typename T>
void Heap::MinHeap<T>::heapifyUp()
{
    auto *temp = this -> lastElement;
    while (temp != this -> root)
    {
        if (temp -> getData() < temp -> getParent() -> getData())
        {
            T tempP = temp -> getParent() -> getData();
            T tempN = temp -> getData();
            temp -> setData(tempP);
            temp -> getParent() ->setData(tempN);
        }
        temp = temp -> getParent();
    }
}

template<typename T>
void Heap::MinHeap<T>::heapifyDown()
{
    auto *temp = this -> root;

    while (temp != nullptr)
    {
        if (temp -> getLeft() != nullptr && temp -> getRight() != nullptr)
        {
            auto *son = temp -> getLeft() -> getData() < temp -> getRight() -> getData() ? temp -> getLeft() : temp -> getRight();
            if (son -> getData() < temp -> getData())
            {
                T tempN = temp -> getData();
                T tempS = son -> getData();
                son -> setData(tempN);
                temp ->setData(tempS);
                temp = son;
            }
            else
                return;
        }
        else if (temp -> getLeft() != nullptr && temp -> getRight() == nullptr)
        {
            if (temp -> getLeft() -> getData() < temp -> getData())
            {
                T tempS = temp -> getLeft() -> getData();
                T tempN = temp -> getData();
                temp ->setData(tempS);
                temp -> getLeft() ->setData(tempN);
                temp = temp -> getLeft();
            }
            else
                return;
        }
        else
            return;
    }
}

template<typename T>
void Heap::MinHeap<T>::printArray()
{
    for (auto a : this -> elements)
        std::cout << a -> getData() << " ";
    std::cout << std::endl;
}

template<typename T>
void Heap::MinHeap<T>::clear()
{
    this -> elements.clear();
    this -> root = nullptr;
    this -> lastElement = nullptr;
}

template<typename T>
int Heap::MinHeap<T>::getHeight()
{
    auto *temp = this -> lastElement;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp -> getParent();
    }
    return count;
}

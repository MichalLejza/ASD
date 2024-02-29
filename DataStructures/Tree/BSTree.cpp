#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Tree/Tree.hpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Tree/Tree.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Stack/Stack.cpp"

#pragma once

template<typename T>
Tree::BSTree<T>::BSTree(T data) : BTree<T>(data) {}

template<typename T>
template<typename ...Args>
void Tree::BSTree<T>::insert(const T &value, Args ...args)
{
    addNode(value);
    if constexpr (sizeof...(args) > 0)
        insert(args...);
}

template<typename T>
void Tree::BSTree<T>::addNode(T data)
{
    if (this -> root == nullptr)
        this -> root = new Node::BNode<T>(data);
    Node::BNode<T> *current = this -> root;
    Node::BNode<T> *parent = nullptr;
    auto *newNode = new Node::BNode<T>(data);

    while (current != nullptr)
    {
        parent = current;
        if (data > current -> getData())
            current = current -> getRight();
        else if (data < current -> getData())
            current = current -> getLeft();
        else
        {
            delete newNode;
            return;
        }
    }
    if (data < parent -> getData())
        parent ->setLeft(newNode);
    else
        parent ->setRight(newNode);
}

template<typename T>
void Tree::BSTree<T>::removeNode(T data)
{
    auto *nodeStack = new Stack::Stack<Node::BNode<T> *>;
    Node::BNode<T> *current = this -> root;
    Node::BNode<T> *parent = nullptr;

    while (current != nullptr && current -> getData() != data)
    {
        parent = current;
        data < current -> getData() ? current = current -> getLeft() : current = current -> getRight();
    }

    if (current == nullptr)
        return;

    if (current -> getLeft() == nullptr)
    {
        if (parent == nullptr)
            this -> root = current -> getRight();
        else if (current == parent -> getRight())
            parent -> setLeft(current -> getRight());
        else
            parent -> setRight(current -> getRight());
        delete current;
    }
    else if (current -> getRight() == nullptr)
    {
        if (parent == nullptr)
            this -> root = current -> getLeft();
        else if (current == parent -> getLeft())
            parent -> setLeft(current -> getLeft());
        else
            parent -> setRight(current -> getLeft());
        delete current;
    }
    else
    {
        Node::BNode<T> *successor = current -> getLeft();
        while (successor -> getLeft() != nullptr)
        {
            nodeStack->push(successor);
            successor = successor->getLeft();
        }
        current ->setData(successor -> getData());
        if (nodeStack->isEmpty())
            current ->setRight(successor -> getRight());
        else
        {
            nodeStack->getTop() ->setLeft(successor -> getRight());
            delete successor;
        }
    }
    nodeStack -> clear();
}


template<typename T>
int Tree::BSTree<T>::getHeight(Node::BNode<T> *node)
{
    if (node == nullptr)
        return 0;
    else
        return 1 + std::max(getHeight(node -> getLeft()), getHeight(node -> getRight()));
}

template<typename T>
T Tree::BSTree<T>::getMinValue()
{
    auto *temp = this -> root;
    while (temp -> getLeft() != nullptr)
        temp = temp -> getLeft();
    return temp -> getData();
}

template<typename T>
T Tree::BSTree<T>::getMaxValue()
{
    auto *temp = this -> root;
    while (temp -> getRight() != nullptr)
        temp = temp -> getRight();
    return temp -> getData();
}

template<typename T>
int Tree::BSTree<T>::countNodes(Node::BNode<T> *node)
{
    if (node == nullptr)
        return 0;
    else
        return countNodes(node -> getLeft()) + countNodes(node -> getRight()) + 1;
}



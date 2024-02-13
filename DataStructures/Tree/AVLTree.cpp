#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Tree/Tree.hpp"

#pragma once

template<typename T>
Tree::AVLTree<T>::AVLTree(T data) : BTree<T>(data) {}


template<typename T>
void Tree::AVLTree<T>::addNode(T data)
{
    this -> root = addingNode(this -> root, data);
}

template<typename T>
void Tree::AVLTree<T>::removeNode(T data)
{
    this -> root = removingNode(this -> root, data);
}

template<typename T>
T Tree::AVLTree<T>::getMinValue()
{
    auto *temp = this -> root;
    while (temp -> getLeft() != nullptr)
        temp = temp -> getLeft();
    return temp -> getData();
}

template<typename T>
T Tree::AVLTree<T>::getMaxValue()
{
    auto *temp = this -> root;
    while (temp -> getRight() != nullptr)
        temp = temp -> getRight();
    return temp -> getData();
}

template<typename T>
int Tree::AVLTree<T>::gettingHeight(Node::BNode<T> *node)
{
    return node == nullptr ? -1 : node -> getHeight();
}

template<typename T>
int Tree::AVLTree<T>::countNodes(Node::BNode<T> *node)
{
    if (node == nullptr)
        return 0;
    else
        return countNodes(node -> getLeft()) + countNodes(node -> getRight()) + 1;
}

template<typename T>
template<typename ...Args>
void Tree::AVLTree<T>::insert(const T &value, Args ...args)
{
    addNode(value);
    if constexpr (sizeof...(args) > 0)
        insert(args...);
}

template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::addingNode(Node::BNode<T> *node, T data)
{
    if (node == nullptr)
        return new Node::BNode<T>(data, 0);
    else if (data < node -> getData())
    {
        node -> setLeft(addingNode(node -> getLeft(), data));
        if (gettingHeight(node->getLeft()) - gettingHeight(node->getRight()) == 2)
        {
            if (data < node -> getLeft() -> getData())
                node = rotateRight(node);
            else
                node = doubleRotateRight(node);
        }
    }
    else if (data > node -> getData())
    {
        node -> setRight(addingNode(node -> getRight(), data));
        if (gettingHeight(node->getRight()) - gettingHeight(node->getLeft()) == 2)
        {
            if (data > node -> getRight() -> getData())
                node = rotateLeft(node);
            else
                node = doubleRotateLeft(node);
        }
    }
    node -> setHeight(std::max(gettingHeight(node->getLeft()), gettingHeight(node->getRight())) + 1);

    return node;
}


template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::rotateRight(Node::BNode<T> *node)
{
    Node::BNode<T> *U = node -> getLeft();
    node -> setLeft(U -> getRight());
    U -> setRight(node);
    node -> setHeight(std::max(gettingHeight(node->getLeft()), gettingHeight(node->getRight())) + 1);
    U -> setHeight(std::max(gettingHeight(node->getRight()), gettingHeight(node)) + 1);
    return U;
}

template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::rotateLeft(Node::BNode<T> *node)
{
    Node::BNode<T> *U = node -> getRight();
    node -> setRight(U -> getLeft());
    U -> setLeft(node);
    node -> setHeight(std::max(gettingHeight(node->getLeft()), gettingHeight(node->getRight())) + 1);
    U -> setHeight(std::max(gettingHeight(node->getRight()), gettingHeight(node)) + 1);
    return U;
}

template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::doubleRotateLeft(Node::BNode<T> *node)
{
    node -> setRight(rotateRight(node -> getRight()));
    return rotateLeft(node);
}

template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::doubleRotateRight(Node::BNode<T> *node)
{
    node -> setLeft(rotateLeft(node -> getLeft()));
    return rotateRight(node);
}

template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::removingNode(Node::BNode<T> *node, T data)
{
    if (data < node -> getData())
        node -> setLeft(removingNode(node -> getLeft(), data));
    else if(data > node -> getData())
        node -> setRight(removingNode(node -> getRight(), data));
    else
    {
        Node::BNode<T> *right = node -> getRight();
        if (node -> getRight() == nullptr)
        {
            Node::BNode<T> *left = node -> getLeft();
            delete(node);
            node = left;
        }
        else if (node -> getLeft() == nullptr)
        {
            delete(node);
            node = right;
        }
        else
        {
            while (right -> getLeft() != nullptr)
                right = right -> getLeft();
            node -> setData(right -> getData());
            node ->setRight(removingNode(node -> getRight(), right -> getData()));
        }
    }
    if (node == nullptr)
        return node;
    node -> setHeight(1 + std::max(getHeight(node -> getLeft()), getHeight(node -> getRight())));
    int balance = getHeight(node -> getLeft()) - getHeight(node -> getRight());
    if (balance > 1)
    {
        if (getHeight(node -> getLeft()) >= getHeight(node -> getRight()))
            return rotateRight(node);
        else
        {
            node -> setLeft(rotateLeft(node -> getLeft()));
            return rotateRight(node);
        }
    }
    else if (balance < -1)
    {
        if (getHeight(node -> getRight()) >= getHeight(node -> getLeft()))
            return rotateLeft(node);
        else
        {
            node -> setRight(rotateLeft(node -> getRight()));
            return rotateLeft(node);
        }
    }
    return node;
}

template<typename T>
int Tree::AVLTree<T>::getHeight(Node::BNode<T> *node)
{
    if (node == nullptr)
        return 0;
    else
        return 1 + std::max(getHeight(node -> getLeft()), getHeight(node -> getRight()));
}
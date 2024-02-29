#include "Tree.hpp"

#pragma once

template<typename T>
Tree::BTree<T>::BTree(T data) : root(new Node::BNode<T>(data)) {}

template<typename T>
Tree::BTree<T>::BTree(Node::BNode<T> *node) : root(node) {}

template<typename T>
Node::BNode<T> *Tree::BTree<T>::getRoot()
{
    return this -> root;
}

template<typename T>
void Tree::BTree<T>::setRoot(T data)
{
    this -> root = new Node::BNode<T>(data);
}

template<typename T>
void Tree::BTree<T>::setRoot(Node::BNode<T> *node)
{
    this -> root = node;
}

template<typename T>
void Tree::BTree<T>::printPreOrder()
{
    preOrderTraversal(this -> getRoot());
    std::cout << std::endl;
}

template<typename T>
void Tree::BTree<T>::printInOrder()
{
    inOrderTraversal(this -> getRoot());
    std::cout << std::endl;
}

template<typename T>
void Tree::BTree<T>::printPostOrder()
{
    postOrderTraversal(this -> getRoot());
    std::cout << std::endl;
}

template<typename T>
void Tree::BTree<T>::inOrderTraversal(Node::BNode<T> *node)
{
    if (node != nullptr)
    {
        inOrderTraversal(node -> getLeft());
        std::cout << "[" << node -> getData() << "] ";
        inOrderTraversal(node -> getRight());
    }
}


template<typename T>
void Tree::BTree<T>::preOrderTraversal(Node::BNode<T> *node)
{
    if (node != nullptr)
    {
        std::cout << node -> getData() << " ";
        preOrderTraversal(node -> getLeft());
        preOrderTraversal(node -> getRight());
    }
}

template<typename T>
void Tree::BTree<T>::postOrderTraversal(Node::BNode<T> *node)
{
    if (node != nullptr)
    {
        postOrderTraversal(node -> getLeft());
        postOrderTraversal(node -> getRight());
        std::cout << node -> getData() << " ";
    }
}




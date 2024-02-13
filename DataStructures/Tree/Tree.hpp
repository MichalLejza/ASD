#ifndef EVERYTHING_TREE_HPP
#define EVERYTHING_TREE_HPP

#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/BNode.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/LinkedList/LinkedList.cpp"

#pragma once

namespace Tree
{
    template<typename T>
    class BTree
    {
        void inOrderTraversal(Node::BNode<T> *node);
        void preOrderTraversal(Node::BNode<T> *node);
        void postOrderTraversal(Node::BNode<T> *node);

    protected:
        Node::BNode<T> *root;
    public:
        BTree() = default;
        ~BTree() = default;
        explicit BTree(T data);
        explicit BTree(Node::BNode<T> *node);
        Node::BNode<T> *getRoot();
        void setRoot(T data);
        void setRoot(Node::BNode<T> *node);
        void printInOrder();
        void printPreOrder();
        void printPostOrder();

        virtual T getMinValue() {};
        virtual T getMaxValue() {};
        virtual void addNode(T data) {};
        virtual void removeNode(T data) {};
        virtual int getHeight(Node::BNode<T> *node) {};
        virtual int countNodes(Node::BNode<T> *node) {};
    };

    template<typename T>
    class BSTree : public BTree<T>
    {
    public:
        BSTree() = default;
        ~BSTree() = default;
        explicit BSTree(T data);
        T getMinValue() override;
        T getMaxValue() override;
        template<typename ...Args>
        void insert(const T &value, Args ...args);
        void addNode(T data) override;
        void removeNode(T data) override;
        int getHeight(Node::BNode<T> *node) override;
        int countNodes(Node::BNode<T> *node) override;
    };

    template<typename T>
    class AVLTree : public BTree<T>
    {
        Node::BNode<T> *rotateLeft(Node::BNode<T> *node);
        Node::BNode<T> *rotateRight(Node::BNode<T> *node);
        Node::BNode<T> *doubleRotateLeft(Node::BNode<T> *node);
        Node::BNode<T> *doubleRotateRight(Node::BNode<T> *node);
        Node::BNode<T> *addingNode(Node::BNode<T> *node, T data);
        Node::BNode<T> *removingNode(Node::BNode<T> *node, T data);

    public:
        AVLTree() = default;
        ~AVLTree() = default;
        explicit AVLTree(T data);
        void addNode(T data) override;
        void removeNode(T data) override;
        T getMinValue() override;
        T getMaxValue() override;
        template<typename ...Args>
        void insert(const T &value, Args ...args);
        int gettingHeight(Node::BNode<T> *node);
        int getHeight(Node::BNode<T> *node) override;
        int countNodes(Node::BNode<T> *node) override;
    };
}

#endif //EVERYTHING_TREE_HPP

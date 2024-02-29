#ifndef EVERYTHING_LINKEDLIST_HPP
#define EVERYTHING_LINKEDLIST_HPP

#pragma once
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/LinkedNode.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/DoubleLinkedNode.cpp"
#include <iostream>
#include <sstream>
#include <cstdarg>
#include "functional"

namespace LinkedList
{
    template<typename T>
    class LinkedList
    {
        Node::LinkedNode<T> *head;
        ssize_t size{};

    public:
        LinkedList();
        explicit LinkedList(T data);
        explicit LinkedList(Node::LinkedNode<T> *node);
        ~LinkedList() = default;
        Node::LinkedNode<T> *getHead();
        T getValue();
        template<typename ...Args>
        void insert(const T &value, Args ... args);
        void pushBack(T value);
        void pushBack(Node::LinkedNode<T> *node);
        void pushFront(T value);
        void pushFront(Node::LinkedNode<T> *node);
        void popFront();
        void popBack();
        void popElement(T value);
        void clear();
        void print();
        bool sorted();
        bool isEmpty();
        ssize_t getSize();
        void map(std::function<void(T&)> fun);
        void filter(const std::function<bool(T&)> &fun);
    };

    template<typename T>
    class DoubleLinkedList
    {
        Node::DoubleLinkedNode<T> *head;
        ssize_t size{};

    public:
        DoubleLinkedList();
        explicit DoubleLinkedList(T data);
        explicit DoubleLinkedList(Node::DoubleLinkedNode<T> *node);
        ~DoubleLinkedList() = default;
        Node::DoubleLinkedNode<T> *getHead();
        template<typename ...Args>
        void insert(const T &value, Args ... args);
        void pushBack(T value);
        void pushBack(Node::LinkedNode<T> *node);
        void pushFront(T value);
        void pushFront(Node::LinkedNode<T> *node);
        void popFront();
        void popBack();
        void popElement(T value);
        void clear();
        void print();
        bool isEmpty();
        ssize_t getSize();
    };
}

#endif //EVERYTHING_LINKEDLIST_HPP

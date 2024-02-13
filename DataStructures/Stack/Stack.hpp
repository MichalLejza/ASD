#ifndef EVERYTHING_STACK_HPP
#define EVERYTHING_STACK_HPP

#pragma once

#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/LinkedNode.cpp"

namespace Stack
{
    template<typename T>
    class Stack
    {
        Node::LinkedNode<T> *head;
        ssize_t size {};
    public:
        Stack();
        explicit Stack(T data);
        explicit Stack(Node::LinkedNode<T> *headNode);
        ~Stack() = default;

        template<typename ...Args>
        void insert(const T &value, Args ...args);
        void push(T data);
        void push(Node::LinkedNode<T> *node);
        void pop();
        ssize_t getSize();
        bool isEmpty();
        void print();
        void clear();
        T getTop();
    };
}


#endif //EVERYTHING_STACK_HPP

#include "Node.hpp"
#pragma once

template<typename T>
Node::Node<T>::Node(T data) : data(data) {}

template<typename T>
void Node::Node<T>::printNode()
{
    std::cout << this -> data << std::endl;
}

template<typename T>
void Node::Node<T>::setData(T update)
{
    this -> data = update;
}

template<typename T>
T Node::Node<T>::getData() const
{
    return this -> data;
}

template<typename T>
void Node::Node<T>::applyFunction(const std::function<void(T &)> &lambda)
{
    lambda(this -> data);
}

template<typename T>
bool Node::Node<T>::applyFilter(const std::function<bool(T &)> &lambda)
{
    return lambda(this -> data);
}

template<typename T>
bool Node::Node<T>::isInteger() const
{
    return std::is_integral<T>::value;
}

template<typename T>
bool Node::Node<T>::isDouble() const
{
    return std::is_same_v<double, T>;
}

template<typename T>
bool Node::Node<T>::isString() const
{
    return std::is_same_v<std::string, T>;
}

template<typename T>
bool Node::Node<T>::isEqual(Node<T> *node)
{
    return this -> data == node -> data;
}

template<typename T>
bool Node::Node<T>::isGreaterThen(Node<T> *node)
{
    return this -> data > node -> data;
}

template<typename T>
bool Node::Node<T>::isLesserThen(Node<T> *node)
{
    return this -> data < node -> data;
}
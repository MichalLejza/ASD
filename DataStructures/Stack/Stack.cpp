#include "Stack.hpp"

template<typename T>
Stack::Stack<T>::Stack() : size(0), head(nullptr) {}

template<typename T>
Stack::Stack<T>::Stack(T data) : size(1), head(new Node::LinkedNode<T>(data)) {}

template<typename T>
Stack::Stack<T>::Stack(Node::LinkedNode<T> *headNode) : size(1), head(headNode) {}

template<typename T>
template<typename ...Args>
void Stack::Stack<T>::insert(const T &value, Args ...args)
{
    push(value);
    if constexpr (sizeof...(args) > 0)
        insert(args...);
}

template<typename T>
T Stack::Stack<T>::getTop()
{
    return this -> head -> getData();
}

template<typename T>
void Stack::Stack<T>::pop()
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
bool Stack::Stack<T>::isEmpty()
{
    return this -> head == nullptr;
}

template<typename T>
ssize_t Stack::Stack<T>::getSize()
{
    return this -> size;
}

template<typename T>
void Stack::Stack<T>::push(T data)
{
    auto *newNode = new Node::LinkedNode<T>(data);
    newNode -> setNext(head);
    this -> head = newNode;
    this -> size++;
}

template<typename T>
void Stack::Stack<T>::push(Node::LinkedNode<T> *node)
{
    node -> setNext(this -> head);
    this -> head = node;
    delete node;
    this -> size++;
}

template<typename T>
void Stack::Stack<T>::print()
{
    auto *temp = this -> head;
    while (temp != nullptr)
    {
        std::cout << temp -> getData() << " <- ";
        temp = temp -> getNext();
    }
    std::cout << std::endl;
}

template<typename T>
void Stack::Stack<T>::clear()
{
    while (this -> head != nullptr)
    {
        auto *temp = this -> head;
        this -> head = this -> head -> getNext();
        delete temp;
        this -> size--;
    }
}
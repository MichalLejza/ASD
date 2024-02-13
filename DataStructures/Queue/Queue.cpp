#include "Queue.hpp"

template<typename T>
Queue::Queue<T>::Queue() : head(nullptr), size(0) {}

template<typename T>
Queue::Queue<T>::Queue(T data) : size(1), head(new Node::LinkedNode<T>(data)) {}

template<typename T>
Queue::Queue<T>::Queue(Node::LinkedNode<T> *headNode) : size(0), head(headNode) {}

template<typename T>
T Queue::Queue<T>::getHead()
{
    return this -> head -> getData();
}

template<typename T>
template<typename ...Args>
void Queue::Queue<T>::insert(const T &value, Args ...args)
{
    push(value);
    if constexpr (sizeof...(args) > 0)
        insert(args...);
}

template<typename T>
void Queue::Queue<T>::push(T value)
{
    if (this -> head == nullptr)
    {
        this -> head = new Node::LinkedNode<T>(value);
        this -> size = 1;
    }
    else
    {
        auto *temp = new Node::LinkedNode<T>(value);
        auto run = this -> head;
        while (run -> getNext() != nullptr)
            run = run -> getNext();
        run -> setNext(temp);
        this -> size++;
    }
}

template<typename T>
void Queue::Queue<T>::push(Node::LinkedNode<T> *node)
{
    if (node == nullptr)
        return;
    if(this -> head == nullptr)
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
void Queue::Queue<T>::pop()
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
ssize_t Queue::Queue<T>::getSize()
{
    return this -> size;
}

template<typename T>
void Queue::Queue<T>::clear()
{
    while (this -> head != nullptr)
    {
        auto *temp = this -> head;
        this -> head = head -> getNext();
        delete temp;
    }
    this -> size = 0;
    this -> head = nullptr;
}

template<typename T>
bool Queue::Queue<T>::empty()
{
    return this -> head == nullptr;
}

template<typename T>
void Queue::Queue<T>::printQueue()
{
    auto *temp = this -> head;
    while (temp != nullptr)
    {
        std::cout << temp -> getData() << " -> ";
        temp = temp -> getNext();
    }
    std::cout << std::endl;
}



template<typename T>
Queue::PriorityQueue<T>::PriorityQueue() : head(nullptr), size(0) {}

template<typename T>
Queue::PriorityQueue<T>::PriorityQueue(T value, size_t priority) : size(1)
{
    std::pair<T, size_t> para{value, priority};
    this -> head = new Node::LinkedNode<std::pair<T, size_t>>(para);
}

template<typename T>
Queue::PriorityQueue<T>::PriorityQueue(Node::LinkedNode<std::pair<T, size_t>> *node) : size(0)
{
    this -> head = node;
}

template <typename T>
Queue::PriorityQueue<T>::PriorityQueue(std::pair<T, size_t> node) : size(1)
{
    this -> head = new Node::LinkedNode<std::pair<T, size_t>>(node);
}

template<typename T>
void Queue::PriorityQueue<T>::insert(Node::LinkedNode<std::pair<T, size_t>> *node)
{
    if (head == nullptr)
    {
        this -> head = node;
        this -> size++;
    }
    else
    {
        auto *temp = head;
        while (temp -> getNext() != nullptr && temp -> getNext() -> getData().second > node -> getData().second)
        {
            temp = temp -> getNext();
        }
        auto *next = temp -> getNext();
        node -> setNext(next);
        temp -> setNext(node);
        this -> size++;
        delete next;
    }
}

template<typename T>
void Queue::PriorityQueue<T>::insert(T data, size_t priority)
{
    if (head == nullptr)
    {
        std::pair<T, size_t> para{data, priority};
        this -> head = new Node::LinkedNode<std::pair<T, size_t>>(para);
        this -> size++;
    }
    else
    {
        if (head -> getData().second < priority)
        {
            std::pair<T, size_t> para{data, priority};
            auto *newNode = new Node::LinkedNode<std::pair<T, size_t>>(para);
            newNode -> setNext(this -> head);
            this -> head = newNode;
            this -> size++;
            return;
        }
        auto *current = this -> head;
        while (current -> getNext() != nullptr && current -> getNext() -> getData().second > priority) {
            current = current -> getNext();
        }
        std::pair<T, size_t> para{data, priority};
        auto *newNode = new Node::LinkedNode<std::pair<T, size_t>>(para);
        newNode -> setNext(current -> getNext());
        current -> setNext(newNode);
        this -> size++;
    }
}

template<typename T>
void Queue::PriorityQueue<T>::dequeue()
{
    if (this -> head != nullptr)
    {
        if (this -> head -> getNext() == nullptr)
        {
            delete this -> head;
            this -> head = nullptr;
            this -> size = 0;
        }
        else
        {
            auto *temp = this -> head;
            this -> head = this -> head -> getNext();
            delete temp;
            this -> size--;
        }
    }
}

template<typename T>
void Queue::PriorityQueue<T>::increaseKey(T data, size_t priority)
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        if (data == head -> getData().first)
        {
            std::pair<T, size_t> para{data, priority};
            this -> head -> setData(para);
            return;
        }

        auto *temp = head;
        while (temp -> getNext() != nullptr)
        {
            if (temp -> getNext() -> getData().first == data)
            {
                auto *t = temp -> getNext();
                temp -> setNext(temp -> getNext() -> getNext());
                delete t;
            }
            temp = temp -> getNext();
        }
        insert(data, priority);
    }
}

template<typename T>
void Queue::PriorityQueue<T>::increaseKey(Node::LinkedNode<std::pair<T, size_t>> *node, size_t priority)
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        if (node -> getData().first == head -> getData().first)
        {
            std::pair<T, size_t> para{node -> getData().first, priority};
            this -> head -> setData(para);
            return;
        }

        auto *temp = head;
        while (temp -> getNext() != nullptr)
        {
            if (temp -> getNext() -> getData().first == node -> getData.first)
            {
                auto *t = temp -> getNext();
                temp -> setNext(temp -> getNext() -> getNext());
                delete t;
            }
            temp = temp -> getNext();
        }
        insert(node -> getData().first, priority);
    }
}

template<typename T>
void Queue::PriorityQueue<T>::decreaseKey(T data, size_t priority)
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        auto *temp = head;
        while (temp != nullptr)
        {
            if (temp -> getData().first == data)
            {
                std::pair<T, size_t> para{data, priority};
                temp -> setData(para);
                while (temp -> getNext() != nullptr && temp -> getNext() -> getData().second > priority)
                {
                    auto currentData = temp -> getData();
                    temp ->setData(temp -> getNext() -> getData());
                    temp -> getNext() ->setData(currentData);
                    temp = temp -> getNext();
                }
            }
            temp = temp -> getNext();
        }
    }
}

template<typename T>
void Queue::PriorityQueue<T>::decreaseKey(Node::LinkedNode<std::pair<T, size_t>> *node, size_t priority)
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        auto *temp = head;
        while (temp != nullptr)
        {
            if (temp -> getData().first == node -> getData().first)
            {
                std::pair<T, size_t> para{node -> getData().first, priority};
                temp -> setData(para);
                while (temp -> getNext() != nullptr && temp -> getNext() -> getData().second > priority)
                {
                    auto currentData = temp -> getData();
                    temp -> setData(temp -> getNext() -> getData());
                    temp -> getNext() ->setData(currentData);
                    temp = temp -> getNext();
                }
            }
            temp = temp -> getNext();
        }
    }
}

template<typename T>
void Queue::PriorityQueue<T>::clear()
{
    while (this -> head != nullptr)
    {
        auto *temp = this -> head;
        this -> head = this -> head -> getNext();
        delete temp;
    }
    this -> size = 0;
}

template<typename T>
bool Queue::PriorityQueue<T>::empty()
{
    return this -> size == 0;
}

template<typename T>
ssize_t Queue::PriorityQueue<T>::getSize()
{
    return this -> size;
}

template<typename T>
void Queue::PriorityQueue<T>::print()
{
    auto *temp = this -> head;
    while (temp)
    {
        std::cout << "[ " << temp -> getData().first << ", " << temp -> getData().second << " ] -> ";
        temp = temp -> getNext();
    }
    std::cout << "null" << std::endl;
}


#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class CircularQueue {
    int size;
    T* buffer;
    int frontIndex;
    int backIndex;
    int currentSize;
    int maxCapacity;

public:
    CircularQueue(int capacity);
    ~CircularQueue();

    void push(const T& element);
    void pop();
    T& front();
    T& back();
    int getSize();
    bool empty();
};

template<typename T>
inline CircularQueue<T>::CircularQueue(int capacity) : size(capacity), buffer(new T[capacity]), frontIndex(0), backIndex(0), currentSize(0), maxCapacity(capacity) {}

template<typename T>
inline CircularQueue<T>::~CircularQueue()
{
    delete[] buffer;
}

template<typename T>
inline void CircularQueue<T>::push(const T& element)
{
    if (currentSize == maxCapacity)
    {
        buffer[backIndex] = element;
        frontIndex = (frontIndex + 1) % maxCapacity;
        backIndex = (backIndex + 1) % maxCapacity;
    }
    else {
        buffer[backIndex] = element;
        backIndex = (backIndex + 1) % maxCapacity;
        currentSize++;
    }
}

template<typename T>
inline void CircularQueue<T>::pop()
{
    if (empty())
    {
        std::cout << "Linia este goala.:)";
        throw std::runtime_error("Randul este gol");
    }
    frontIndex = (frontIndex + 1) % maxCapacity;
    currentSize--;
}

template<typename T>
inline T& CircularQueue<T>::front()
{
    if (empty())
    {
        std::cout << "Linia este goala.:)";
        throw std::runtime_error("Randul este gol");
    }
    return buffer[frontIndex];
}

template<typename T>
inline T& CircularQueue<T>::back()
{
    if (empty())
    {
        std::cout << "Linia este goala.:)";
        throw std::runtime_error("Randul este gol");
    }
    return buffer[(backIndex + maxCapacity - 1) % maxCapacity];
}

template <typename T>
int CircularQueue<T>::getSize() {
    return currentSize;
}

template <typename T>
bool CircularQueue<T>::empty() {
    return currentSize == 0;
}

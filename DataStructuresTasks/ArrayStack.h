#pragma once
#include <iostream>
#include <stdexcept>

template <class T>
class ArrayStack {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    ArrayStack(int size = 100) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(T element) {
        if (topIndex < capacity - 1) {
            arr[++topIndex] = element;
        }
        else {
            std::cout << "Stack Overflow!\n";
        }
    }

    void pop() {
        if (!isEmpty()) {
            topIndex--;
        }
    }

    T top() const {
        if (!isEmpty()) {
            return arr[topIndex];
        }
        throw std::out_of_range("Stack is empty");
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};
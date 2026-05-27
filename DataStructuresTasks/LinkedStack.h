#pragma once
#include <iostream>
#include <stdexcept>

template <class T>
class LinkedStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* topNode;

public:
    LinkedStack() : topNode(nullptr) {}

    ~LinkedStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T element) {
        Node* newNode = new Node(element);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    T top() const {
        if (!isEmpty()) {
            return topNode->data;
        }
        throw std::out_of_range("Stack is empty");
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    void display() const {
        Node* current = topNode;
        std::cout << "  [Stack]: Top -> ";
        if (!current) {
            std::cout << "(empty)";
        }
        while (current != nullptr) {
            std::cout << current->data << (current->next ? " -> " : "");
            current = current->next;
        }
        std::cout << "\n";
    }
};
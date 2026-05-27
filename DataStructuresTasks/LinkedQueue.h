#pragma once
#include <iostream>
#include <stdexcept>

template <class T>
class LinkedQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* frontNode;
    Node* rearNode;

public:
    LinkedQueue() : frontNode(nullptr), rearNode(nullptr) {}

    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            if (frontNode == nullptr) {
                rearNode = nullptr;
            }
            delete temp;
        }
    }

    T front() const {
        if (!isEmpty()) {
            return frontNode->data;
        }
        throw std::out_of_range("Queue is empty");
    }

    bool isEmpty() const {
        return frontNode == nullptr;
    }

    void display() const {
        Node* current = frontNode;
        std::cout << "  [Queue]: Front -> ";
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
#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <iostream>
#include <string>
#include <utility>
#include <locale>

template <typename T>
class SingleLinkedList {
private:
    struct Node {
        T data;
        Node* next = nullptr;

        explicit Node(const T& value) : data(value), next() {}
        explicit Node(T&& value) : data(std::move(value)), next() {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int listSize = 0;

    void clearNode() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        listSize = 0;
    }

public:
    SingleLinkedList() = default;
    ~SingleLinkedList() {
        clearNode();
    }

    SingleLinkedList(const SingleLinkedList&) = delete;
    SingleLinkedList& operator=(const SingleLinkedList&) = delete;

    SingleLinkedList(SingleLinkedList&& other) noexcept :
        head(other.head), tail(other.tail), listSize(other.listSize) {
        other.head = nullptr;
        other.tail = nullptr;
        other.listSize = 0;
    }

    SingleLinkedList& operator=(SingleLinkedList&& other) noexcept {
        if (this != &other) {
            clearNode();
            head = other.head;
            tail = other.tail;
            listSize = other.listSize;
            other.head = nullptr;
            other.tail = nullptr;
            other.listSize = 0;
        }
        return *this;
    }

    void push_back(const T& value);
    void push_back(T&& value);
    void print() const;
    void input();
};

#include "SingleLinkedList.cpp"

#endif // SINGLELINKEDLIST_H
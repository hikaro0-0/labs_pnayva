#ifndef SINGLELINKEDLIST_CPP
#define SINGLELINKEDLIST_CPP

#include "SingleLinkedList.h"

template <typename T>
void SingleLinkedList<T>::push_back(const T& value) {
    auto* newNode = new Node(value);
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    ++listSize;
}

template <typename T>
void SingleLinkedList<T>::push_back(T&& value) {
    auto* newNode = new Node(std::move(value));
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    ++listSize;
}

template <typename T>
void SingleLinkedList<T>::print() const {
    Node* actual = head;
    while (actual) {
        std::cout << actual->data << " -> ";
        actual = actual->next;
    }
    std::cout << "�����(" << std::endl;
}

template <typename T>
void SingleLinkedList<T>::input() {
    std::cout << "������� �������� ������ (��� ���������� ������� 'end'): " << std::endl;

    while (true) {
        T value;
        bool shouldBreak = false;

        if constexpr (std::is_same_v<T, std::string>) {
            std::string input;
            std::getline(std::cin, input);
            if (input == "end") {
                shouldBreak = true;
            }
            else {
                value = input;
            }
        }
        else {
            if (!(std::cin >> value)) {
                std::cin.clear();
                std::string tempString;
                std::getline(std::cin, tempString);
                std::cout << "���� ��������." << std::endl;
                shouldBreak = true;
            }
        }

        if (shouldBreak) break;
        push_back(std::move(value));
    }
}

#endif // SINGLELINKEDLIST_CPP
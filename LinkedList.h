#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <iostream>
#include "ListNode.h"

template <typename T>
class LinkedList {
private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;

public:
    LinkedList();
    ~LinkedList();

    void insertFront(T d);
    void insertBack(T d);
    T removeBack();
    T removeFront();
    int removeNode(T value);
    int find(T value);
    bool isEmpty();
    unsigned int getSize();

    void printList(bool isPrintLink);
};

#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() {
    front = nullptr;
    back = nullptr;
    size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (!isEmpty()) {
        removeFront();
    }
}

template<typename T>
void LinkedList<T>::insertFront(T d) {
    ListNode<T> *node = new ListNode<T>(d);
    if (isEmpty()) {
        back = node;
    } else {
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}

template<typename T>
void LinkedList<T>::insertBack(T d) {
    ListNode<T> *node = new ListNode<T>(d);
    if(isEmpty()) {
        front = node;
    } else {
        back->next = node;
        node->prev = back;
    }
    back = node;
    ++size;
}

template<typename T>
T LinkedList<T>::removeFront() {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }

    ListNode<T> *temp = front;

    if (front->next == nullptr) {
        //one node in the list
        back = nullptr;
    } else {
        //more than one node
        front->next->prev = nullptr;
    }

    front = front->next;
    temp->next = nullptr;
    T data = temp->data;
    --size;

    delete temp;
    return data;
}

template<typename T>
T LinkedList<T>::removeBack() {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }

    ListNode<T> *temp = back;

    if (back->prev == nullptr) {
        //one node
        front = nullptr;
    } else {
        back->prev->next = nullptr;
    }
    back = back->prev;
    temp->prev = nullptr;
    T data = temp->data;
    --size;
    delete temp;
    return data;
}

template<typename T>
int LinkedList<T>::find(T value) {
    int pos = -1;
    ListNode<T> *curr = front;

    while (curr != nullptr) {
        ++pos;
        if (curr->data == value)
            return pos;
        curr = curr->next;
    }
    if (curr == nullptr)
        pos = -1;

    return pos;
}

template<typename T>
int LinkedList<T>::removeNode(T value) {

    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }

    ListNode<T> *curr = front;
    while (curr->data != value) {
        curr = curr->next;

        if (curr == nullptr)
            return -1;
    }

    //if we make it here we found the node that needs to be deleted :3
    if (curr == front) {
        front = curr->next;
        if(front)
            front->prev = nullptr;
    } else if (curr == back) {
        back = curr->prev;
        if(back)
            back->next = nullptr;
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    curr->next = nullptr;
    curr->prev = nullptr;
    T temp = curr->data;
    --size;
    delete curr;
    return temp;
}

template<typename T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

template<typename T>
unsigned int LinkedList<T>::getSize() {
    return size;
}

template<typename T>
void LinkedList<T>::printList(bool isPrintLink) {
    ListNode<T> *current = front;
    while (current != nullptr) {
        std::cout << current->data;
        if (isPrintLink && current->next != nullptr)
            std::cout << " <-> ";
        else if (current->next != nullptr)
            std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif

#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode {
public:
    T data;
    ListNode<T>* next;
    ListNode<T>* prev;

    ListNode();
    ListNode(T d);
    ~ListNode();
};

template<typename T>
ListNode<T>::ListNode() : data(T()), next(nullptr), prev(nullptr) {}

template<typename T>
ListNode<T>::ListNode(T d) : data(d), next(nullptr), prev(nullptr) {}

template<typename T>
ListNode<T>::~ListNode() {
    prev = nullptr;
    next = nullptr;
}

#endif
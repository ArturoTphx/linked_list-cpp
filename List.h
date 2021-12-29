//
// Created by thepu on 29/12/2021.
//

#ifndef LINKED_LIST_LIST_H
#define LINKED_LIST_LIST_H

#include <iostream>
#include <sstream>
using namespace std;

template <class T> class Node {
public:
    T data;
    Node * next;
    Node(T data, Node * next): data(data), next(next) {}
};

template <class T> class List {
private:
    Node<T> * first;
public:
    typedef Node<T> element;
    List() {
        this->first = nullptr;
    }
    ~List() {
        deleteAll();
    }

    void insert(T data) {
        if (first == nullptr) {
            first = new Node<T>(data, nullptr);
        } else {
            element * tmp = first;
            first = new Node<T>(data, tmp);
        }
    }

    void deleteAll() {
        if (first == nullptr) {
            return;
        } else {
            element * tmp = first->next;
            while (tmp != nullptr) {
                element * erase = tmp;
                tmp = tmp->next;
                delete erase;
            }
            delete first;
            first = nullptr;
        }
    }

    string toList() {
        stringstream s;
        if (first == nullptr) {
            s << "The list is empty!\n";
        } else {
            element * tmp = first;
            while (tmp != nullptr) {
                s << tmp->data << "\n";
                tmp = tmp->next;
            }
        }
        return s.str();
    }
};

#endif //LINKED_LIST_LIST_H

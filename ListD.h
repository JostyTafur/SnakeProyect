#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T>* next;
    Node<T>* prev;
    Node(T v, Node* n = nullptr, Node* p = nullptr) :value(v), next(n), prev(p) {}
};

template <class T>
class Iterator {
    unsigned int pos;
    Node<T>* aux;
public:
    Iterator(unsigned int pos, Node<T>* aux) : pos(pos), aux(aux) {}
    Iterator() {}

    void operator ++() { pos++; aux = aux->next; }
    bool operator !=(Iterator x) { return pos != x.pos; }
    T operator *() { return aux->value; }
};

template <class T>
class ListD {
private:
    Node<T>* start;
    Node<T>* finish;
    unsigned long size;
public:
    ListD() {
        start = finish = nullptr;
        size = 0;
    }

    T back() {
        return finish->value;
    }

    T front() {
        return start->value;
    }


    void push_front(T v) {
        Node<T>* nuevo = new Node<T>(v);
        if (size == 0) {
            finish = nuevo;
        }
        else {
            nuevo->next = start;
            start->prev = nuevo;
        }
        start = nuevo;
        ++size;
    }
    void print() {
        Node<T>* aux = start;
        while (aux != nullptr) {
            cout << aux->value << "-->";
            aux = aux->next;
        }
        cout << "nullptr\n";
    }
    void push_back(T v) {
        Node<T>* nuevo = new Node<T>(v);
        if (size == 0)
            push_front(v);//begin=end=nuevo;++size;
        else {
            finish->next = nuevo;
            nuevo->prev = finish;
            finish = nuevo;
            ++size;
        }
    }

    Iterator<T> begin() {
        return Iterator<T>(0, start);
    }
    Iterator<T> end() {
        return Iterator<T>(size, nullptr);
    }
};
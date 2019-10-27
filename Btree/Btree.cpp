//
// Created by pda on 10/22/19.
//

#include "Btree.h"
#include <iostream>


template<typename T>
Node<T>::Node() {
    this->leaf = true;
    numkeys = 0;
    this->data = nullptr;
    this->ChildPtrs = nullptr;
}

template<typename T>
void Node<T>::Sort(T *mas) {
    int i, j, key = 0;
    T temp = 0;
    for (i = 0; i < numkeys - 1; i++) {
        key = i + 1;
        temp = mas[key];
        for (j = i + 1; j > 0; j--) {
            if (temp < mas[j - 1]) {
                mas[j] = mas[j - 1];
                key = j - 1;
            }
        }
        mas[key] = temp;
    }
}

template<typename T>
bool Node<T>::addkey(T key) {
    T *subdata = new T(numkeys + 1);

    for (int i = 0; i < numkeys; i++) {
        subdata[i] = data[i];
    }
    delete[] data;
    data = subdata;
    numkeys++;
    data[numkeys - 1] = key;
    Sort(data);
}

template Btree<int>::Btree(unsigned int maxpower);

template Btree<float>::Btree(unsigned int maxpower);

template Btree<char>::Btree(unsigned int maxpower);

template<typename T>
Btree<T>::Btree(unsigned int maxpower) {
    root = nullptr;
    power = maxpower;
}


template<typename T>
Btree<T>::~Btree() {
}

template Btree<float>::~Btree();

template Btree<char>::~Btree();

template Btree<int>::~Btree();


template<>
BtreeSearch<int> *Btree<int>::search(Node<int> *x, int key) {
    int bsearch = binarysearch(x->data, 0, x->numkeys, key);
    unsigned int n = x->numkeys;
    if (bsearch != -1) {
        BtreeSearch<int> *btreeSearch = new BtreeSearch<int>();
        btreeSearch->index = bsearch;
        btreeSearch->node = x;
        return btreeSearch;
    } else if (key < x->data[0] && !x->leaf) {
        search(x->ChildPtrs[0], key);
    } else if (key > x->data[n - 1] && !x->leaf) {
        search(x->ChildPtrs[n], key);
    } else if (!x->leaf) {
        bool flag = false;
        int i = 0;
        for (int i = 0; i < n - 1 && !flag; i++) {
            if (key > x->data[i] && key < x->data[i + 1]) {
                flag = true;
                search(x->ChildPtrs[i + 1], key);
            }
        }

    } else return nullptr;
}


template<>
int Btree<int>::add(int data) {

    int i, temp;
    if (root == nullptr) {
        root = new Node<int>();
        root->addkey(data);
    } else if (root->leaf) {
        root->addkey(data);
    }

    std::cout << search(root, data)->index << std::endl;
    std::cout << search(root, data)->node << std::endl;
}

template<typename typedata>
int Btree<typedata>::binarysearch(typedata *arr, int l, int r, typedata key) {
    bool flag = false;
    int mid;

    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (arr[mid] == key) flag = true; //проверяем ключ со серединным элементом
        if (arr[mid] > key) r = mid - 1; // проверяем, какую часть нужно отбросить
        else l = mid + 1;
    }
    if (flag) { return mid; } else { return -1; }
}

template<typename typedata>
void Btree<typedata>::splitting(Node<typedata> *x, unsigned int i) {
    Node<typedata> *z = new Node<typedata>;
    Node<typedata> *y = x->ChildPtrs[i];
    *z->leaf = *y->leaf;
    z->numkeys = power;

    for (int j = 0; j < power; j++) { z->data[j] = y->data[j + power]; }
    if (!y->leaf) {
        for (int j = 0; j <= power; j++) {
            z->ChildPtrs[j] = y->ChildPtrs[j + power];
        }
    }
    y->numkeys = power;
    for (int j = x->numkeys; j > i; j--) {
        x->ChildPtrs[j + 1] = x->ChildPtrs[j];
    }
    x->ChildPtrs[i] = z;

    for (int j = x->numkeys; j > i; j--) {
        x->data[j + 1] = x->data[j];
    }
    x->data[i] = y->data[power];
    x->numkeys = x->numkeys + 1;

}
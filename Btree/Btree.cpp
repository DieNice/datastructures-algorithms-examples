//
// Created by pda on 10/22/19.
//

#include "Btree.h"

template<typename T>
Btree<T>::Btree(unsigned int maxpower) {
    root = nullptr;
    power = maxpower;
}

template Btree<int>::Btree(unsigned int maxpower);

template Btree<float>::Btree(unsigned int maxpower);

template Btree<char>::Btree(unsigned int maxpower);

template<typename T>
Btree<T>::~Btree() {
}

template Btree<float>::~Btree();

template Btree<char>::~Btree();

template Btree<int>::~Btree();
//
// Created by pda on 10/22/19.
//

#ifndef BTREE_BTREE_H
#define BTREE_BTREE_H

template<typename T>
struct Node {
    bool leaf;
    T *data;
    unsigned int numkeys; //кол-во ключей узла
    Node **ChildPtrs;

    Node();

    bool addkey(T key);

private:
    void Sort(T *numbers);
};

template<typename T>
struct BtreeSearch {
    unsigned int index;
    Node<T> *node;
};


template<typename typedata>
class Btree {
private:
    unsigned int power; // максимальная степень дерева
    Node<typedata> *root;

    int binarysearch(typedata *data, int left, int right, typedata key);

    void splitting(Node<typedata> *x, unsigned int i); // индекс i-такой что узел x.Ci-заполненный дочерний узел

public:

    Btree<typedata>(unsigned int maxpower);

    ~Btree();

    BtreeSearch<typedata> *search(Node<typedata> *x, typedata key);

    int add(typedata data);

    int remove(typedata data);

    int getpower();

};


#endif //BTREE_BTREE_H

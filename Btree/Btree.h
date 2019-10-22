//
// Created by pda on 10/22/19.
//

#ifndef BTREE_BTREE_H
#define BTREE_BTREE_H

template<typename T>
struct Node {
    bool leaf;
    T data;
    unsigned int numnode; //кол-во ключей узла
    Node **ChildPtrs;


};

template<typename typedata>
class Btree {
private:
    unsigned int power; // максимальная степень дерева
    Node<typedata> *root;

    void insert(typedata key, Node<typedata> *leaf);

public:
    Btree<typedata>(unsigned int maxpower);

    ~Btree();

    Node<typedata> *search(typedata key);

    int add(typedata data);

    int remove(typedata data);


};


#endif //BTREE_BTREE_H

#include <iostream>
#include "Btree.h"

int main() {
    Btree<int> btree(2);
    btree.add(10);
    btree.add(11);
    btree.add(14);
    btree.add(20);
    btree.add(1);
    return 0;
}